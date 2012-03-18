    // Starting point for refinements.  
    // Do elimination step in case of two intersections.
    VECTOR mzero = VECTOR_BROADCASTF(-0.0f);
    VECTOR delta_p1 = VECTOR_ANDNOT(mzero, distance(isectx[0], isecty[0], rvx[0], rvy[0]) - rr[0]);
    VECTOR delta_p2 = VECTOR_ANDNOT(mzero, distance(isectx[1], isecty[1], rvx[0], rvy[0]) - rr[0]);
    VECTOR emask = VECTOR_AND(VECTOR_CMPGT(icount, one), VECTOR_CMPGT(delta_p1, delta_p2));
    VECTOR p_isectx = VECTOR_BLENDV(isectx[0], isectx[1], emask);
    VECTOR p_isecty = VECTOR_BLENDV(isecty[0], isecty[1], emask);

    // If no intersection, return NAN.
    VECTOR vnan = VECTOR_BROADCASTF(NAN);
    p_isectx = VECTOR_BLENDV(isectx, vnan, VECTOR_CMPEQ(icount, VECTOR_ZERO()));
    p_isecty = VECTOR_BLENDV(isecty, vnan, VECTOR_CMPEQ(icount, VECTOR_ZERO()));