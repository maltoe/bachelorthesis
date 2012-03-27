// Determine minimum and maximum distance to cell boundary.
// Note that (x,y) denotes the top-left corner of the cell and 
// L is its side length.
float closestX = CLAMP(anchors[i].x, x, x+L);
float closestY = CLAMP(anchors[i].y, y, y+L);
float farXoffset = max(closestX - x, (x+L) - closestX);
float farYoffset = max(closestY - y, (y+L) - closestY);
float minDistX = abs(closestX - anchors[i].x);
float minDistY = abs(closestY - anchors[i].y);
float maxDistX = minDistX + farXoffset;
float maxDistY = minDistY + farYoffset;
float dMinSqr = minDistX * minDistX + minDistY * minDistY;
float dMaxSqr = maxDistX * maxDistX + maxDistY * maxDistY; 