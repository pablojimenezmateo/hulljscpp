#include "Coordinate.h"

Coordinate::Coordinate(const double x, const double y) {
    this->x = x;
    this->y = y;
};

Coordinate::Coordinate() {
    this->x = 0;
    this->y = 0;
};

double Coordinate::getX() const {
    return this->x;
};
double Coordinate::getY() const {
    return this->y;
};

void Coordinate::setX(const double x) {
    this->x = x;
};

void Coordinate::setY(const double y) {
    this->y = y;
};

std::string Coordinate::toString() {

    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
};

bool operator==(const Coordinate& a, const Coordinate& b) {

    return (a.getX() == b.getX()) && (a.getY() == b.getY());
};