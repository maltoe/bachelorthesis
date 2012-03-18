FUNCTION void
aml_run (const int count, const VECTOR* vx, const VECTOR* vy, const VECTOR* r, VECTOR* resx, VECTOR* resy) {
    VECTOR isectx[2], isecty[2], ci, cj;
    VECTOR icount = VECTOR_ZERO();

    // find two circles (random), which intersect in one or two points
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            VECTOR isectx_tmp[2], isecty_tmp[2];
            VECTOR icount_tmp = circle_get_intersection_v(vx[i], vy[i], vx[j], vy[j], r[i], r[j], isectx_tmp, isecty_tmp);
            VECTOR mask = VECTOR_AND(VECTOR_CMPEQ(icount, VECTOR_ZERO()), VECTOR_CMPGT(icount_tmp, VECTOR_ZERO()));

            icount = VECTOR_BLENDV(icount, icount_tmp, mask);
            // [Skipped: Blend ci, cj, isectx, and isecty depending on mask.]

            if (VECTOR_TEST_ALL_ONES(VECTOR_CMPGT(icount, VECTOR_ZERO())))
                goto endloop;
        }
    }
    endloop: