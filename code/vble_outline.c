while (grid_size > min_grid_size) {

	// Initialize voting array.
	// Set each cell's score to zero.

	for(int anchor = 0; anchor < count; anchor++) {

		// Calculate outer and inner test regions
		// (xMin, xMax, yMin, yMax)

		for(int x = xMin; x < xMax; x++) {
			for(int y = yMin; y < yMax; y++) {

				// Skip cell if it is contained in inner test region.

				// Determine sector of anchor relative to cell.

				// Calculate minimum and maximum distance between
				// the anchor and the cell's boundary.

				// Using these distances, test whether candidate ring
				// overlaps with cell. If so, increase the current cell's
				// score in the voting array.
			}
		}
	}
}

// Return center of mass of highest-ranked cells.