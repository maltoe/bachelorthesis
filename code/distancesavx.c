union {
    VECTOR v;
    float f[8];
} distances[sum];
VECTOR xt = _mm256_load_ps(ix);
VECTOR yt = _mm256_load_ps(iy);
for(int i = 0; i < sum; i++) {
    VECTOR px = VECTOR_BROADCAST(&ix[i]);
    VECTOR py = VECTOR_BROADCAST(&iy[i]);
    distances[i].v = distance(px, py, xt, yt);
}