#include "Coordinate.h"

Coordinate::Coordinate(const double x, const double y) {
    this->x = x;
    this->y = y;
};

Coordinate::Coordinate() {
    this->x = 0;
    this->y = 0;
};

double Coordinate::getX() {
    return this->x;
};
double Coordinate::getY() {
    return this->y;
};

void Coordinate::setX(const double x) {
    this->x = x;
};
void Coordinate::setY(const double y) {
    this->y = y;
};