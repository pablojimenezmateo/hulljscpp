#include "Coordinate.h"

Coordinate::Coordinate(double x, double y) {
    x = x;
    y = y;
};

Coordinate::Coordinate() {
    x = 0;
    y = 0;
};

double Coordinate::getX() {
    return x;
};
double Coordinate::getY() {
    return y;
};
