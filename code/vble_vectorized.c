__m128i j = xMin; // xMin is a __m128i, too.
while (1) {   
    // Break condition: All j elements have passed their corresponding
    // xMax values.
    // We use this to blacklist those vector elements where j has passed the
    // xMax value for the current iteration.
    VECTOR jgexMax = VECTOR_CMPGE(_mm_cvtepi32_ps(j), _mm_cvtepi32_ps(xMax));
    if (VECTOR_TEST_ALL_ONES(jgexMax))
        break;
  
    __m128i k = yMin;
    while (1) {    
        // Same here.
        VECTOR kgeyMax = VECTOR_CMPGE(_mm_cvtepi32_ps(k), _mm_cvtepi32_ps(yMax));
        if (VECTOR_TEST_ALL_ONES(kgeyMax))
            break;
        
        // [Skipped: Calculate dMax/dMin distances.]

        // Merge blacklists to guard the voting process.
        VECTOR blacklist = VECTOR_OR(jgexMax, kgeyMax);

        // Calculate voting array indices.
        __m128i scoresIdx = _mm_mullo_epi32(j, yLength + _mm_set1_epi32(1)) + k;

        // Test if candidate ring overlaps with cell.
        VECTOR sx = VECTOR_AND(VECTOR_CMPLE(dMin, anchors[i].ro), VECTOR_CMPGE(dMax, anchors[i].ri));
        VECTOR sx = VECTOR_AND(one, VECTOR_ANDNOT(blacklist, sx));
        
        // Increase cell's scores if candidate ring overlaps.
        scores[scoresIdx[0]][0] += (int) sx[0];
        scores[scoresIdx[1]][1] += (int) sx[1];
        scores[scoresIdx[2]][2] += (int) sx[2];
        scores[scoresIdx[3]][3] += (int) sx[3];

        // [Skipped: Maintain highest-ranked cell.]

        k += _mm_set1_epi32(1);
    }
    j += _mm_set1_epi32(1);
}