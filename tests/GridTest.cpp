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
    int passed, total;


    /*
     cellPoints
    */
    std::cout << "Running cellPoints tests" << std::endl;
    passed = 0;
    total = 4;

    std::vector<Coordinate> test;
    test.push_back(Coordinate(0, 0));
    test.push_back(Coordinate(1, 1));
    test.push_back(Coordinate(9, 5));

    std::vector<Coordinate> result_c = g.cellPoints(0, 0);
    if (result_c != test) {

        std::cout << "[FAILED] g.cellPoints(0, 0), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result_c) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    test.clear();
    test.push_back(Coordinate(1, 11));
    test.push_back(Coordinate(5, 15));

    result_c = g.cellPoints(0, 1);
    if (result_c != test) {

        std::cout << "[FAILED] g.cellPoints(0, 1), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result_c) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    test.clear();
    test.push_back(Coordinate(11, 0));
    test.push_back(Coordinate(11, 1));
    test.push_back(Coordinate(19, 5));

    result_c = g.cellPoints(1, 0);
    if (result_c != test) {

        std::cout << "[FAILED] g.cellPoints(0, 1), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result_c) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    test.clear();
    test.push_back(Coordinate(10, 10));
    test.push_back(Coordinate(11, 11));

    result_c = g.cellPoints(1, 1);
    if (result_c != test) {

        std::cout << "[FAILED] g.cellPoints(0, 1), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result_c) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    std::cout << "[CORRECT] cellPoints [" << passed << "/" << total << "]" << std::endl;

    /*
     coordToCellNum
    */
    std::cout << "Running coordToCellNum tests" << std::endl;

    passed = 0;
    total = 4;

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

    std::cout << "[CORRECT] coordToCellNum [" << passed << "/" << total << "]" << std::endl;
}