    // do first estimation step and refinement
    for (int k = 0; k < rcount; k++) {       
        VECTOR dist = distance(p_isectx, p_isecty, rvx[k], rvy[k]);
        VECTOR delta_pi = dist - rr[k];
            
        // case 1: point outside of circle
        VECTOR drr1 = (delta_pi / two) / (delta_pi + rr[k]);
        VECTOR delta_x_out = (rvx[k] - p_isectx) * drr1;
        VECTOR delta_y_out = (rvy[k] - p_isecty) * drr1;
            
        // case 2: point inside of circle
        delta_pi = VECTOR_MAX(dist - rr[k], rr[k] - dist);
        VECTOR drr2 = (delta_pi / two) / rr[k];
        VECTOR div = one - two * drr2;
        VECTOR delta_x_in = ((p_intersectx - rvx[k]) * drr2) / div;
        VECTOR delta_y_in = ((p_isecty - rvy[k]) * drr2) / div;
        
        VECTOR mask = VECTOR_CMPGT(dist, rr[k]);
        VECTOR dx = VECTOR_BLENDV(delta_x_in, delta_x_out, mask);
        VECTOR dy = VECTOR_BLENDV(delta_y_in, delta_y_out, mask);
            
        p_isectx += dx;
        p_isecty += dy;
    }
    
    *resx = p_isectx;
    *resy = p_isecty;
}