#ifndef GRID_H
#define GRID_H
#include <map>
#include <vector>
#include "Coordinate.h"
#include "BoundingBox.h"

class Grid {

    private:
        std::map<int, std::map<int, std::vector<Coordinate>>> cells;
        double cellSize;
        double reverseCellSize;
        int size;

    public:
        Grid(std::vector<Coordinate> coordinates, double cellSize);
        std::vector<Coordinate> cellPoints(int x, int y);
        std::vector<Coordinate> rangePoints(std::vector<int> bbox);
        std::vector<Coordinate> removeCoordinate(Coordinate coordinate);
        Coordinate removeCoordinate(double val);
        int trunc(double val);
        int coordToCellNum(double x);
        BoundingBox extendBbox(BoundingBox bbox, double scaleFactor);
};

#endif