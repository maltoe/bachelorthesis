/**
 * Returns the intersection of two circles for all 4/8 circles in the vectors.
 * @ret: the number of intersections [0,1,2] of the corresponding circles.
 */
FUNCTION VECTOR
circle_get_intersection_v (VECTOR p1x, VECTOR p1y, VECTOR p2x, VECTOR p2y, VECTOR r1, VECTOR r2, VECTOR* retx, VECTOR* rety) {
    VECTOR d = distance(p1x, p1y, p2x, p2y);

    // Mark not intersecting circles
    VECTOR retval = VECTOR_AND(one, VECTOR_CMPGE(d, VECTOR_ZERO()));
    retval = VECTOR_AND(retval, VECTOR_CMPGE(r1 + r2, d));
    retval = VECTOR_AND(retval, VECTOR_CMPGE(d, VECTOR_MAX(r1 - r2, r2 - r1)));

    VECTOR a =  (r1*r1 - r2*r2 + d*d) / (two * d);
    VECTOR v = r1*r1 - a*a;
    VECTOR h = VECTOR_SQRT(v);

    VECTOR dx = (p2x - p1x) / d;
    VECTOR dy = (p2y - p1y) / d;
    
    VECTOR p3x = p1x + a * dx;
    VECTOR p3y = p1y + a * dy;

    dx *= h;
    dy *= h;
    
    retx[0] = p3x + dy;
    rety[0] = p3y - dx;
    retx[1] = p3x - dy;
    rety[1] = p3y + dx;
    
    retval += VECTOR_AND(retval, VECTOR_CMPGE(h, VECTOR_ZERO()));
    return retval;
}