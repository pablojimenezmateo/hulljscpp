#include "../src/Coordinate.h"
#include "../src/Hull.h"
#include <iostream>

int main() {

    std::cout << "Running hull tests" << std::endl;
    int passed=0, total=5;

    std::vector<Coordinate> points, expected, result;

    points.push_back(Coordinate(162, 332)); 
    points.push_back(Coordinate(182, 299)); 
    points.push_back(Coordinate(141, 292)); 
    points.push_back(Coordinate(158, 264)); 
    points.push_back(Coordinate(141, 408)); 
    points.push_back(Coordinate(160, 400)); 
    points.push_back(Coordinate(177, 430)); 
    points.push_back(Coordinate(151, 442)); 
    points.push_back(Coordinate(155, 425)); 
    points.push_back(Coordinate(134, 430)); 
    points.push_back(Coordinate(126, 447)); 
    points.push_back(Coordinate(139, 466)); 
    points.push_back(Coordinate(160, 471)); 
    points.push_back(Coordinate(167, 447)); 
    points.push_back(Coordinate(182, 466)); 
    points.push_back(Coordinate(192, 442)); 
    points.push_back(Coordinate(187, 413)); 
    points.push_back(Coordinate(173, 403)); 
    points.push_back(Coordinate(168, 425)); 
    points.push_back(Coordinate(153, 413)); 
    points.push_back(Coordinate(179, 275)); 
    points.push_back(Coordinate(163, 292)); 
    points.push_back(Coordinate(134, 270)); 
    points.push_back(Coordinate(143, 315)); 
    points.push_back(Coordinate(177, 320)); 
    points.push_back(Coordinate(163, 311)); 
    points.push_back(Coordinate(162, 281)); 
    points.push_back(Coordinate(182, 255)); 
    points.push_back(Coordinate(141, 226)); 
    points.push_back(Coordinate(156, 235)); 
    points.push_back(Coordinate(173, 207)); 
    points.push_back(Coordinate(187, 230)); 
    points.push_back(Coordinate(204, 194)); 
    points.push_back(Coordinate(165, 189)); 
    points.push_back(Coordinate(145, 201)); 
    points.push_back(Coordinate(158, 167)); 
    points.push_back(Coordinate(190, 165)); 
    points.push_back(Coordinate(206, 145)); 
    points.push_back(Coordinate(179, 153)); 
    points.push_back(Coordinate(204, 114)); 
    points.push_back(Coordinate(221, 138)); 
    points.push_back(Coordinate(243, 112)); 
    points.push_back(Coordinate(248, 139)); 
    points.push_back(Coordinate(177, 122)); 
    points.push_back(Coordinate(179, 99)); 
    points.push_back(Coordinate(196, 82)); 
    points.push_back(Coordinate(219, 90)); 
    points.push_back(Coordinate(240, 75)); 
    points.push_back(Coordinate(218, 61)); 
    points.push_back(Coordinate(228, 53)); 
    points.push_back(Coordinate(211, 34)); 
    points.push_back(Coordinate(197, 51)); 
    points.push_back(Coordinate(179, 65)); 
    points.push_back(Coordinate(155, 70)); 
    points.push_back(Coordinate(165, 85)); 
    points.push_back(Coordinate(134, 80)); 
    points.push_back(Coordinate(124, 58)); 
    points.push_back(Coordinate(153, 44)); 
    points.push_back(Coordinate(173, 34)); 
    points.push_back(Coordinate(192, 27)); 
    points.push_back(Coordinate(156, 19)); 
    points.push_back(Coordinate(119, 32)); 
    points.push_back(Coordinate(128, 17)); 
    points.push_back(Coordinate(138, 36)); 
    points.push_back(Coordinate(100, 58)); 
    points.push_back(Coordinate(112, 73)); 
    points.push_back(Coordinate(100, 92)); 
    points.push_back(Coordinate(78, 100)); 
    points.push_back(Coordinate(83, 78)); 
    points.push_back(Coordinate(61, 63)); 
    points.push_back(Coordinate(80, 44)); 
    points.push_back(Coordinate(100, 26)); 
    points.push_back(Coordinate(60, 39)); 
    points.push_back(Coordinate(43, 71)); 
    points.push_back(Coordinate(34, 54)); 
    points.push_back(Coordinate(32, 90)); 
    points.push_back(Coordinate(53, 104)); 
    points.push_back(Coordinate(60, 82)); 
    points.push_back(Coordinate(66, 99)); 
    points.push_back(Coordinate(247, 94)); 
    points.push_back(Coordinate(187, 180)); 
    points.push_back(Coordinate(221, 168));

    expected.push_back(Coordinate(248,139));
    expected.push_back(Coordinate(221,168));
    expected.push_back(Coordinate(204,194));
    expected.push_back(Coordinate(187,230));
    expected.push_back(Coordinate(182,255));
    expected.push_back(Coordinate(182,299));
    expected.push_back(Coordinate(177,320));
    expected.push_back(Coordinate(160,400));
    expected.push_back(Coordinate(173,403));
    expected.push_back(Coordinate(187,413));
    expected.push_back(Coordinate(192,442));
    expected.push_back(Coordinate(182,466));
    expected.push_back(Coordinate(160,471));
    expected.push_back(Coordinate(139,466));
    expected.push_back(Coordinate(126,447));
    expected.push_back(Coordinate(141,408));
    expected.push_back(Coordinate(162,332));
    expected.push_back(Coordinate(143,315));
    expected.push_back(Coordinate(141,292));
    expected.push_back(Coordinate(134,270));
    expected.push_back(Coordinate(141,226));
    expected.push_back(Coordinate(145,201));
    expected.push_back(Coordinate(158,167));
    expected.push_back(Coordinate(177,122));
    expected.push_back(Coordinate(179,99));
    expected.push_back(Coordinate(165,85));
    expected.push_back(Coordinate(134,80));
    expected.push_back(Coordinate(100,92));
    expected.push_back(Coordinate(78,100));
    expected.push_back(Coordinate(53,104));
    expected.push_back(Coordinate(32,90));
    expected.push_back(Coordinate(34,54));
    expected.push_back(Coordinate(60,39));
    expected.push_back(Coordinate(100,26));
    expected.push_back(Coordinate(128,17));
    expected.push_back(Coordinate(156,19));
    expected.push_back(Coordinate(192,27));
    expected.push_back(Coordinate(211,34));
    expected.push_back(Coordinate(228,53));
    expected.push_back(Coordinate(240,75));
    expected.push_back(Coordinate(247,94));
    expected.push_back(Coordinate(248,139));

    result = hull(points, 50);

    if (result != expected) {

        std::cout << "[FAILED] hull, expected [";
        
        for(Coordinate c : expected) {
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

    std::cout << "[CORRECT] hull [" << passed << "/" << total << "]" << std::endl;
    return 0;
}