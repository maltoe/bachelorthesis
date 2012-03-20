VECTOR max_distance = _mm_setr_ps(0.1, 0.1, 0.1, 0.1);
for (int i = 0; i < sum; i++) {
    VECTOR tmp = VECTOR_AND(one, VECTOR_CMPLT(distances[i].v[0], max_distance));
    tmp += VECTOR_AND(one, VECTOR_CMPLT(distances[i].v[1], max_distance));
    tmp = _mm_hadd_ps(tmp, tmp); tmp = _mm_hadd_ps(tmp, tmp);
    if (tmp[0] >= 3)
        // [Skipped: Return (ix[i], iy[i]) as result.]
}