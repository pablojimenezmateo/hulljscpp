#include "../src/Grid.h"
#include "../src/Coordinate.h"
#include <iostream>

int cellPointsTest(Grid g) {
    /*
     cellPoints
    */
    std::cout << "Running cellPoints tests" << std::endl;
    int passed=0, total=4;

    std::vector<Coordinate> test;
    test.push_back(Coordinate(0, 0));
    test.push_back(Coordinate(1, 1));
    test.push_back(Coordinate(9, 5));

    std::vector<Coordinate> result = g.cellPoints(0, 0);
    if (result != test) {

        std::cout << "[FAILED] g.cellPoints(0, 0), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    test.clear();
    test.push_back(Coordinate(1, 11));
    test.push_back(Coordinate(5, 15));

    result = g.cellPoints(0, 1);
    if (result != test) {

        std::cout << "[FAILED] g.cellPoints(0, 1), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result) {
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

    result = g.cellPoints(1, 0);
    if (result != test) {

        std::cout << "[FAILED] g.cellPoints(0, 1), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    test.clear();
    test.push_back(Coordinate(10, 10));
    test.push_back(Coordinate(11, 11));

    result = g.cellPoints(1, 1);
    if (result != test) {

        std::cout << "[FAILED] g.cellPoints(0, 1), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    std::cout << "[CORRECT] cellPoints [" << passed << "/" << total << "]" << std::endl;
    return 0;
}

int coordToCellNumTest(Grid g) {
    /*
     coordToCellNum
    */
    std::cout << "Running coordToCellNum tests" << std::endl;

    int passed=0, total=4;

    int result = g.coordToCellNum(1);
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
    return 0;
}

int rangePointsTest(Grid g, std::vector<Coordinate> coordinates) {
    std::cout << "Running rangePoints tests" << std::endl;
    int passed=0, total=2;

    std::vector<Coordinate> test;
    test.push_back(Coordinate(0, 0));
    test.push_back(Coordinate(1, 1));
    test.push_back(Coordinate(9, 5));
    test.push_back(Coordinate(1, 11));
    test.push_back(Coordinate(5, 15));

    std::vector<Coordinate> result = g.rangePoints({1, 0, 6, 16});
    if (result != test) {

        std::cout << "[FAILED] g.rangePoints({1, 0, 6, 16}), expected [";
        
        for(Coordinate c : test) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    result = g.rangePoints({0, 0, 11, 11});
    if (result != coordinates) {

        std::cout << "[FAILED] g.rangePoints({1, 0, 6, 16}), expected [";
        
        for(Coordinate c : coordinates) {
            std::cout << c.toString();
        }

        std::cout << "] Got [";

        for(Coordinate c : result) {
            std::cout << c.toString();
        }

        std::cout << "]" << std::endl;
        
        return -1;
    }
    passed++;

    std::cout << "[CORRECT] rangePoints [" << passed << "/" << total << "]" << std::endl;
    return 0;
}


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
    
    cellPointsTest(g);
    coordToCellNumTest(g);
    rangePointsTest(g, coordinates);

}