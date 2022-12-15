#include "../src/Grid.h"
#include "../src/Coordinate.h"
#include <iostream>

int main() {

    std::vector<Coordinate> coordinates;

    // cell 0,0
    coordinates.push_back(Coordinate(0, 0));
    coordinates.push_back(Coordinate(1, 1));
    coordinates.push_back(Coordinate(9, 5));

    // cell 0,1
    coordinates.push_back(Coordinate(1, 11));
    coordinates.push_back(Coordinate(5, 15));

    // cell 1,0
    coordinates.push_back(Coordinate(11, 0));
    coordinates.push_back(Coordinate(11, 1));
    coordinates.push_back(Coordinate(19, 5));

    // cell 1,1
    coordinates.push_back(Coordinate(10, 10));
    coordinates.push_back(Coordinate(11, 11));

    Grid g = Grid(coordinates, 10);

    // coordToCellNum
    std::cout << "Running coordToCellNum tests" << std::endl;

    int passed = 0;
    int expected = 4;

    double result = g.coordToCellNum(1);
    if (result != 0) {

        std::cout << "[FAILED] g.coordToCellNum(1), expected 0 got " << result << std::endl;
        return -1;
    }
    passed++;

    result = g.coordToCellNum(11);
    if (result != 1) {

        std::cout << "[FAILED] g.coordToCellNum(11), expected 1 got " << result << std::endl;
        return -1;
    }
    passed++;

    result = g.coordToCellNum(10);
    if (result != 1) {

        std::cout << "[FAILED] g.coordToCellNum(10), expected 1 got " << result << std::endl;
        return -1;
    }
    passed++;

    result = g.coordToCellNum(11);
    if (result != 1) {

        std::cout << "[FAILED] g.coordToCellNum(11), expected 1 got " << result << std::endl;
        return -1;
    }

    passed++;

    std::cout << "[CORRECT] coordToCellNum [" << passed << "/" << expected << "]" << std::endl;
}