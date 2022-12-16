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
double sqLength(Coordinate a, Coordinate b);
double cos(Coordinate o, Coordinate a, Coordinate b);
bool h_intersect(std::vector<Coordinate> segment, std::vector<Coordinate> pointSet);
Coordinate h_occupiedArea(std::vector<Coordinate> pointSet);
std::vector<double> h_bBoxAround(std::vector<Coordinate> edge);
std::tuple<bool, Coordinate> h_midPoint(std::vector<Coordinate> edge, std::vector<Coordinate> innerPoints, std::vector<Coordinate> convex);
std::vector<Coordinate> h_concave(std::vector<Coordinate> convex, double maxSqEdgeLen, Coordinate maxSearchArea, Grid grid, std::set<std::string> edgeSkipList);
std::vector<Coordinate> hull(std::vector<Coordinate> pointSet, int concavity);

#endif