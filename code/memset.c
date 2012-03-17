#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <smmintrin.h>

void tim(const char *name, float *arr, 
         int length, void (*func)(float*, int, float)) {
    struct timespec t1, t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    func(arr, length, 5.0f);
    clock_gettime(CLOCK_REALTIME, &t2);
    printf("%s : %f s.\n", name, 
        (t2.tv_sec - t1.tv_sec) + 
        (float) (t2.tv_nsec - t1.tv_nsec) / 1000000000);
}

void memset1(float *arr, int length, float value) {
    for(int i = 0; i < length; i++) {
        arr[i] = value;
    }
}

void memset2(float *arr, int length, float value) {
    __m128 buf = _mm_set1_ps(value);
    for(int i = 0; i < length; i += 4) {
        _mm_store_ps(&arr[i], buf);
    }
}

void memset3(float *arr, int length, float value) {
    __m128 buf = _mm_set1_ps(value);
    for(int i = 0; i < length; i += 4) {
        _mm_stream_ps(&arr[i], buf);
    }
    _mm_sfence();
}

int main() {
    const int CACHE_LINE = 64;
    int length = CACHE_LINE * 1024 * 1024;

    // Allocate 64 MB of memory aligned to a cache line.
    float *arr;
    posix_memalign((void**) &arr, CACHE_LINE, 
                   length * sizeof(float));
    // Execute memset once to make sure the memory is allocated.
    memset1(arr, length, 0.0f);

    // Benchmark.
    tim("scalar", arr, length, memset1);
    tim("store", arr, length, memset2);
    tim("stream", arr, length, memset3);

    free(arr);    
    return 0;
}
