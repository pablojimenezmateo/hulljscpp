#include "PythonEntryPoint.h"

double dist(Coordinate a, Coordinate b)
{
	return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX())
		+ (a.getY() - b.getY()) * (a.getY() - b.getY()));
}

extern "C" {


	// Calculates the convex hull
	//
	// returns:
	// The hull size by reference (hsize)
	// The hull vector
	Coordinate* getConvexHull(Coordinate* c, int len, unsigned long &hsize) {

		// Convert Coordinate* to vector<Coordinate>
		std::vector<Coordinate> coordinates(c, c+len);

		std::vector<Coordinate> convexHull = hull(coordinates, 20);

		hsize = convexHull.size();
		
		// We need to allocate some memory for the return array, or the memory may become
		// corrupted
		Coordinate* ret = (Coordinate*)malloc(sizeof(Coordinate)*hsize);
		ret = (Coordinate*)memcpy(ret, convexHull.data(), sizeof(Coordinate)*hsize);

		return ret;
	}

	void freeHull(Coordinate* c) {
		free(c);
	}

	double getHullArea(Coordinate* hull, int len) {

		if (len < 3) {
			return 0;
		}

		// Convert Coordinate* to vector<Coordinate>
		std::vector<Coordinate> hullPoints(hull, hull+len);

		double area=0.0, currX, currY, nextX, nextY;
		int i, l;

		for (i = 0, l = len; i < (l-1); i++) {
			currX = hullPoints[i].getX();
			currY = hullPoints[i].getY();
			nextX = hullPoints[i + 1].getX();
			nextY = hullPoints[i + 1].getY();
			area += (nextX + currX) * (nextY - currY);
		}

    	return area * 0.5;
	}

	// Function to return the perimeter of the convex hull
	double getHullPerimeter(Coordinate* hull, int len) {

		if (len < 3) {
			return 0;
		}

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