    // Refinement anchors.
    int rcount = count - 2;
    VECTOR rvx[rcount], rvy[rcount], rr[rcount];
    for (int ii = 0; ii < VECTOR_OPS; ii++) {
        // store unused anchors for refinement step
        for (int k = 0, n = 0; k < count; k++) {
            if (k != ci[ii] && k != cj[ii]) {
                rvx[n][ii] = vx[k][ii];
                rvy[n][ii] = vy[k][ii];
                rr[n][ii] = r[k][ii];
                n++;
            }
        }
    }