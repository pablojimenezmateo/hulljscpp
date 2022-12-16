extern "C" {


	double getHullArea(Coordinate* hull, int len) {

		// Convert Coordinate* to vector<Coordinate>
		std::vector<Coordinate> hullPoints(hull, hull+len);

		double area=0.0, currX, currY, nextX, nextY;
		int i, l;

		for (i = 0, l = len; i < (l-1); i++) {
			currX = hullPoints[i].GetX();
			currY = hullPoints[i].GetY();
			nextX = hullPoints[i + 1].GetX();
			nextY = hullPoints[i + 1].GetY();
			area += (nextX + currX) * (nextY - currY);

			std::cout << currX << " " << currY << " " << nextX << " " << nextY << "\n";
		}

    	return area * 0.5;
	}



	// Function to return the perimeter of the convex hull
	double getHullPerimeter(Coordinate* hull, int len) {
		// Convert Coordinate* to vector<Coordinate>
		std::vector<Coordinate> hullPoints(hull, hull+len);

		double perimeter = 0.0;

		// Find the distance between adjacent points
		for (unsigned long i = 0; i < hullPoints.size() - 1; i++) {
			perimeter += dist(hullPoints[i], hullPoints[i + 1]);
		}

		// Add the distance between first and last point
		perimeter += dist(hullPoints[0], hullPoints[hullPoints.size() - 1]);

		return perimeter;
	}
}