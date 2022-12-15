#include "Convex.h"
#include <algorithm>

double _cross(Coordinate o, Coordinate a, Coordinate b) {

    return (a.getX() - o.getX()) * (b.getY() - o.getY()) - (a.getY()-o.getY()) * (b.getX() - o.getX());
};

std::vector<Coordinate> _upperTangent(std::vector<Coordinate>& pointSet) {

    std::vector<Coordinate> lower;

    int l;

    for (l=0; l < pointSet.size(); l++) {
        while(lower.size() >=2 && (_cross(lower[lower.size() - 2], lower[lower.size() - 1], pointSet[l]) <= 0)) {
            lower.pop_back();
        }
        lower.push_back(pointSet[l]);
    }
    lower.pop_back();
    return lower;
};

std::vector<Coordinate> _lowerTangent(std::vector<Coordinate>& pointSet) {

    std::vector<Coordinate> reversedPointSet(pointSet.rbegin(), pointSet.rend());
    std::vector<Coordinate> upper;

    int u;

    for (u=0; u<reversedPointSet.size(); u++) {
        while (upper.size() >= 2 && (_cross(upper[upper.size() - 2], upper[upper.size() - 1], reversedPointSet[u]) <= 0)) {
            upper.pop_back();
        }
        upper.push_back(reversedPointSet[u]);
    }
    upper.pop_back();
    return upper;
};

// pointSet has to be sorted by X
std::vector<Coordinate> convex(std::vector<Coordinate>& pointSet) {

    std::vector<Coordinate> upper = _upperTangent(pointSet);
    std::vector<Coordinate> lower = _lowerTangent(pointSet);

    // Copy lower into convex
    std::vector<Coordinate> convex(lower.begin(), lower.end());
    convex.insert(convex.end(), upper.begin(), upper.end());
    convex.push_back(pointSet[0]);

    return convex;
};