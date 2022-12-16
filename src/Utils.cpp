#include "Utils.h"

void printCoordinates(std::vector<Coordinate> pointSet) {

    unsigned long int i;

    for (i=0; i<pointSet.size(); i++) {

        if (i==0) {
            std::cout << pointSet.size() <<" [";
        }

        std::cout << "(" << pointSet[i].getX() << ", " << pointSet[i].getY() << ")";

        if (i==pointSet.size()-1) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
    }
}

void printCoordinates(std::string str, std::vector<Coordinate> pointSet) {

    unsigned long int i;

    for (i=0; i<pointSet.size(); i++) {

        if (i==0) {
            std::cout << str << " " << pointSet.size() <<" [";
        }

        std::cout << "(" << pointSet[i].getX() << ", " << pointSet[i].getY() << ")";

        if (i==pointSet.size()-1) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
    }
}

void printCoordinate(Coordinate coordinate) {

    std::cout << coordinate.toString() << std::endl;
}

void printCoordinate(std::string str, Coordinate coordinate) {

    std::cout << str << " " << coordinate.toString() << std::endl;
}