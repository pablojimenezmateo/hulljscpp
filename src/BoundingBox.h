#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <vector>


class BoundingBox {

    private:
        std::vector<double> array;
        double cellSize;

    public:
        BoundingBox(std::vector<double> array, double cellSize);
};

#endif