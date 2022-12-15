#include "Grid.h"
#include <cmath>

Grid::Grid(std::vector<Coordinate> coordinates, double cellSize) {

    // Initialize the matrix
    this->cellSize = cellSize;
    this->reverseCellSize = 1/cellSize;

    long unsigned int i;

    for (i=0; i < coordinates.size(); i++) {
        Coordinate coordinate = coordinates[i];
        const double x = this->coordToCellNum(coordinate.getX());
        const double y = this->coordToCellNum(coordinate.getY());

        if (this->cells.count(x) == 0) {

            std::map<int, std::vector<Coordinate>> map;
            std::vector<Coordinate> array;

            array.push_back(coordinate);
            map.insert(std::pair<int, std::vector<Coordinate>>(y, array));

            this->cells.insert(std::pair<int, std::map<int, std::vector<Coordinate>>>(x, map));

            std::map<int, std::vector<Coordinate>> aux;

        } else if (this->cells[x].count(y) == 0) {
            std::vector<Coordinate> array;

            array.push_back(coordinate);

            this->cells[x][y] = array;
        } else {
            this->cells[x][y].push_back(coordinate);
        }
    }
};

std::vector<Coordinate> Grid::cellPoints(int x, int y) {
    if (this->cells.count(x) == 1 && this->cells[x].count(y) == 1) {
        return this->cells[x][y];
    } else {
        std::vector<Coordinate> ret;
        return ret;
    }
};

// std::vector<Coordinate> Grid::rangePoints(std::vector<Coordinate> bbox);
// std::vector<Coordinate> Grid::removeCoordinate(Coordinate coordinate);
// double Grid::removeCoordinate(double val);
double Grid::trunc(double val) {
    return std::trunc(val);
};

double Grid::coordToCellNum(double x) {
    return this->trunc(x * this->reverseCellSize);
};

// BoundingBox Grid::extendBbox(BoundingBox bbox, double scaleFactor);