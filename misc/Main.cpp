#include "Main.h"

int main() {

    std::vector<Coordinate> coordinates;

    coordinates.push_back(Coordinate(16, 3)); 
    coordinates.push_back(Coordinate(12, 17)); 
    coordinates.push_back(Coordinate(0, 6)); 
    coordinates.push_back(Coordinate(-4, -6));

    std::vector<Coordinate> result = hull(coordinates, 20);

    printCoordinates(result);
}