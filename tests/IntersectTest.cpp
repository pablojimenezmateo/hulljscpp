#include "../src/Intersect.h"
#include "../src/Coordinate.h"
#include <iostream>

int main() {

    std::cout << "Running intersect tests" << std::endl;
    int passed=0, total=5;

    std::vector<Coordinate> seg1, seg2;

    seg1.push_back(Coordinate(0, 0));
    seg1.push_back(Coordinate(0, 10));

    seg2.push_back(Coordinate(10, 0));
    seg2.push_back(Coordinate(10, 10));

    bool test = false, result;

    result = intersect(seg1, seg2);

    if (result != test) {

        std::cout << "[FAILED] intersect(seg1, seg2), expected [" << test << " got " << result << std::endl;
        
        return -1;
    }
    passed++;

    seg1.clear();
    seg2.clear();

    seg1.push_back(Coordinate(0, 0));
    seg1.push_back(Coordinate(0, 10));

    seg2.push_back(Coordinate(0, 11));
    seg2.push_back(Coordinate(0, 20));

    test = false;

    result = intersect(seg1, seg2);

    if (result != test) {

        std::cout << "[FAILED] intersect(seg1, seg2), expected [" << test << " got " << result << std::endl;
        
        return -1;
    }
    passed++;

    seg1.clear();
    seg2.clear();

    seg1.push_back(Coordinate(0, 0));
    seg1.push_back(Coordinate(0, 10));

    seg2.push_back(Coordinate(-10, 11));
    seg2.push_back(Coordinate(10, 11));

    test = false;
    
    result = intersect(seg1, seg2);

    if (result != test) {

        std::cout << "[FAILED] intersect(seg1, seg2), expected [" << test << " got " << result << std::endl;
        
        return -1;
    }
    passed++;

    seg1.clear();
    seg2.clear();

    seg1.push_back(Coordinate(0, 0));
    seg1.push_back(Coordinate(0, 10));

    seg2.push_back(Coordinate(-10, 5));
    seg2.push_back(Coordinate(10, 5));

    test = true;
    
    result = intersect(seg1, seg2);

    if (result != test) {

        std::cout << "[FAILED] intersect(seg1, seg2), expected [" << test << " got " << result << std::endl;
        
        return -1;
    }
    passed++;

    seg1.clear();
    seg2.clear();

    seg1.push_back(Coordinate(0, 0));
    seg1.push_back(Coordinate(0, 10));

    seg2.push_back(Coordinate(-10, 10));
    seg2.push_back(Coordinate(10, 10));

    test = true;
    
    result = intersect(seg1, seg2);

    if (result != test) {

        std::cout << "[FAILED] intersect(seg1, seg2), expected [" << test << " got " << result << std::endl;
        
        return -1;
    }
    passed++;

    std::cout << "[CORRECT] intersect [" << passed << "/" << total << "]" << std::endl;
    return 0;
}