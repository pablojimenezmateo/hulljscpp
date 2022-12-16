#ifndef INTERSECT_H
#define INTERSECT_H
#include "Coordinate.h"
#include <vector>

bool intersect(std::vector<Coordinate> seg1, std::vector<Coordinate> seg2);
bool ccw(Coordinate a, Coordinate b, Coordinate c);

#endif