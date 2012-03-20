// Precalculate distances
union {
    VECTOR v[2];
    float f[8];
} distances[6];
VECTOR xtlower = _mm_load_ps(ix), ytlower = _mm_load_ps(iy);
VECTOR xtupper = _mm_load_ps(&ix[4]), ytupper = _mm_load_ps(&iy[4]);
xtupper = _mm_movelh_ps(xtupper, xtupper);
ytupper = _mm_movelh_ps(ytupper, ytupper);

for(int i = 0; i < sum; i+=2) {
    VECTOR px = VECTOR_BROADCAST(&ix[i]);
    VECTOR py = VECTOR_BROADCAST(&iy[i]);
    VECTOR px2 = VECTOR_BROADCAST(&ix[i + 1]);
    VECTOR py2 = VECTOR_BROADCAST(&iy[i + 1]);
    
    distances[i].v[0] = distance(px, py, xtlower, ytlower);
    distances[i + 1].v[0] = distance(px2, py2, xtlower, ytlower);
                
    px = _mm_movelh_ps(px, px2);
    py = _mm_movelh_ps(py, py2);
    distances[i].v[1] = distance(px, py, xtupper, ytupper);
    
    distances[i + 1].f[4] = distances[i].f[6];
    distances[i + 1].f[5] = distances[i].f[7];
    
    // [Skipped: Set distances[i..i+1].f[sum..8] to FLT_MAX.]
}