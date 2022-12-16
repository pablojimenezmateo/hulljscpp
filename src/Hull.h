#ifndef HULL_H
#define HULL_H
#include "Coordinate.h"
#include "Intersect.h"
#include "Grid.h"
#include "Convex.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <string>
#include <tuple>
# define M_PI 3.14159265358979323846

const double MAX_CONCAVE_ANGLE_COS = std::cos(90 / (180 / M_PI)); // angle = 90 deg
const double MAX_SEARCH_BBOX_SIZE_PERCENT = 0.6;

std::vector<Coordinate> filterDuplicates(std::vector<Coordinate> pointSet);
bool compareXCoordinate(Coordinate a, Coordinate b);
std::vector<Coordinate> sortByX(std::vector<Coordinate> pointSet);


#endif