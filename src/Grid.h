#ifndef GRID_H
#define GRID_H
#include "Coordinate.h"
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

class Grid {

    private:
        std::map<int, std::map<int, std::vector<Coordinate>>> cells;
        double cellSize;
        double reverseCellSize;
        int size;

    public:
        Grid(std::vector<Coordinate> coordinates, double cellSize);
        std::vector<Coordinate> cellPoints(int x, int y);
        std::vector<Coordinate> rangePoints(std::vector<double> bbox);
        std::vector<Coordinate> removeCoordinate(Coordinate coordinate);
        int trunc(double val);
        int coordToCellNum(double x);
        std::vector<double> extendBbox(std::vector<double> bbox, int scaleFactor);
};

#endif