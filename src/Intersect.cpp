#include "Intersect.h"

bool intersect(std::vector<Coordinate> seg1, std::vector<Coordinate> seg2) {

    Coordinate a = seg1[0];
    Coordinate b = seg1[1];
    Coordinate c = seg2[0];
    Coordinate d = seg2[1];

    return ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d);
};

bool ccw(Coordinate a, Coordinate b, Coordinate c) {

    double cw = ((c.getY() - a.getY()) * (b.getX() - a.getX())) - ((b.getY() - a.getY()) * (c.getX() - a.getX()));

    return cw >= 0;
};