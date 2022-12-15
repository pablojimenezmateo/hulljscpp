#ifndef COORDINATE_H
#define COORDINATE_H
#include <string>
#include <iostream>

class Coordinate {

    private:
        double x;
        double y;

    public:
        Coordinate();
        Coordinate(double x, double y);
        double getX() const;
        double getY() const;
        void setX(const double x);
	    void setY(const double y);
        std::string toString();
        
};

bool operator==(const Coordinate& a, const Coordinate& b);

#endif