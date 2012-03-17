/**
 * Returns the intersections of two circles.
 * @ret: the number of intersection [0,1,2]
 */
FUNCTION int 
circle_get_intersection (float  p1x, float  p1y, float  p2x, float  p2y, float r1, float r2, float* retx, float* rety) {
    float d = distance_s(p1x,p1y,p2x,p2y);

    // no solutions, the circles are separate || the circles are coincident || no solutions because one circle is contained within the other
    // => infinite number of solutions possible
    if (r1+r2 < d || fabs(r1-r2) > d || d == 0) {
        return 0;
    }

    float a = (r1*r1 - r2*r2 + d*d) / (2.0 * d);
    float v = r1*r1 - a*a;
    float h = sqrtf(v);

    float dx = (p2x - p1x) / d;
    float dy = (p2y - p1y) / d;
    float p3x = p1x + a * dx;
    float p3y = p1y + a * dy;

    dx *= h;
    dy *= h;
    float p4x = p3x + dy;
    float p4y = p3y - dx;

    int count = (p4x == p3x && p4y == p3y) ? 1 : 2;

    retx[0] = p4x;
    rety[0] = p4y;
    if (count == 2) {
        p4x = p3x - dy;
        p4y = p3y + dx;
        retx[1] = p4x;
        rety[1] = p4y;
    }
    return count;
}