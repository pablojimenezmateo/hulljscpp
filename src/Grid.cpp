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

std::vector<Coordinate> Grid::rangePoints(std::vector<double> bbox) {

    long unsigned int i;
    int x, y;
    int tlCellX = this->coordToCellNum(bbox[0]);
    int tlCellY = this->coordToCellNum(bbox[1]);
    int brCellX = this->coordToCellNum(bbox[2]);
    int brCellY = this->coordToCellNum(bbox[3]);

    std::vector<Coordinate> coordinates; 

    for (x = tlCellX; x <= brCellX; x++) {
        for (y = tlCellY; y <= brCellY; y++) {
            for (i = 0; i < this->cellPoints(x, y).size(); i++) {
                coordinates.push_back(this->cellPoints(x, y)[i]);
            }
        }
    }

    return coordinates;
};

std::vector<Coordinate> Grid::removeCoordinate(Coordinate coordinate) {

    int cellX = this->coordToCellNum(coordinate.getX());
    int cellY = this->coordToCellNum(coordinate.getY());

    std::vector<Coordinate> cell = this->cells[cellX][cellY];

    cell.erase(std::remove(cell.begin(), cell.end(), coordinate), cell.end());

    return cell;
};

int Grid::trunc(double val) {
    return std::trunc(val);
};

int Grid::coordToCellNum(double x) {
    return this->trunc(x * this->reverseCellSize);
};

std::vector<double> Grid::extendBbox(std::vector<double> bbox, int scaleFactor) {

    int factor = scaleFactor * this->cellSize;

    return {bbox[0] - factor, bbox[1] - factor, bbox[2] + factor, bbox[3] + factor};
};