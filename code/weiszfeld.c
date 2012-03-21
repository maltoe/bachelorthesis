FUNCTION int
weiszfeld_test_optimum_opt(const __m128 ptsx, const __m128 ptsy, const __m128 weights, const int i) {   
    __m128 xi = _mm_load1_ps(&ptsx[i]); __m128 yi = _mm_load1_ps(&ptsy[i]);
    __m128 dists = distance(xi, yi, ptsx, ptsy);  

    __m128 tmpx = weights * ((xi - ptsx) / dists);
    __m128 tmpy = weights * ((yi - ptsy) / dists);
    __m128 inf = VECTOR_BROADCASTF(INFINITY);
    __m128 mask = _mm_and_ps(_mm_cmplt_ps(tmpx, inf), _mm_cmpgt_ps(tmpx, -inf));
    tmpx = _mm_blendv_ps(_mm_setzero_ps(), tmpx, mask);
    tmpy = _mm_blendv_ps(_mm_setzero_ps(), tmpy, mask);
    
    tmpx = _mm_hadd_ps(tmpx, tmpx); tmpx = _mm_hadd_ps(tmpx, tmpx);
    tmpy = _mm_hadd_ps(tmpy, tmpy); tmpy = _mm_hadd_ps(tmpy, tmpy);
    
    float result = sqrtf((tmpx[0] * tmpx[0]) + (tmpy[0] * tmpy[0]));
    return (result <= weights[i]) ? i : -1;
}