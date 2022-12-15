#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {

    private:
        double x;
        double y;

    public:
        Coordinate();
        Coordinate(double x, double y);
        double getX();
        double getY();
        void setX(const double x);
	    void setY(const double y);
};

#endif