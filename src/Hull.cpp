#include "Hull.h"

std::vector<Coordinate> filterDuplicates(std::vector<Coordinate> coordinates) {

    std::vector<Coordinate> unique;
    unique.push_back(coordinates[0]);

    Coordinate lastPoint = coordinates[0];

    unsigned long int i;

    for (i=0; i<coordinates.size(); i++) {

        Coordinate currentPoint = coordinates[i];

        if (lastPoint.getX() != currentPoint.getX() || lastPoint.getY() != currentPoint.getY()) {

            unique.push_back(currentPoint);
        }

        lastPoint = currentPoint;
    }

    return unique;
};

bool compareXCoordinate(Coordinate a, Coordinate b) {

    if (a.getX() == b.getX()) {

        return a.getY() < b.getY();
        
    } else {
        return a.getX() <= b.getX();
    }
};

std::vector<Coordinate> sortByX(std::vector<Coordinate> coordinates) {

    std::sort(coordinates.begin(), coordinates.end(), compareXCoordinate);
    return coordinates;
};

double sqLength(Coordinate a, Coordinate b) {

    return pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2);
};

double cos(Coordinate o, Coordinate a, Coordinate b) {

    Coordinate aShifted = Coordinate(a.getX() - o.getX(), a.getY() - o.getY());
    Coordinate bShifted = Coordinate(b.getX() - o.getX(), b.getY() - o.getY());

    double sqALen = sqLength(o, a);
    double sqBLen = sqLength(o, b);

    double dot = aShifted.getX() * bShifted.getX() + aShifted.getY() * bShifted.getY();

    return dot / sqrt(sqALen * sqBLen);
}

bool h_intersect(std::vector<Coordinate> segment, std::vector<Coordinate> coordinates) {

    unsigned long int i;

    for (i=0; i< coordinates.size()-1; i++) {
        std::vector<Coordinate> seg;
        seg.push_back(coordinates[i]);
        seg.push_back(coordinates[i+1]);

        if (((segment[0].getX() == seg[0].getX()) && (segment[0].getY() == seg[0].getY())) ||
            ((segment[0].getX() == seg[1].getX()) && (segment[0].getY() == seg[1].getY()))) {
            continue;
        }

        if (intersect(segment, seg)) {
            return true;
        }
    }
    return false;
}

Coordinate h_occupiedArea(std::vector<Coordinate> coordinates) {
    double minX = std::numeric_limits<double>::max();
    double minY = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::min();
    double maxY = std::numeric_limits<double>::min();

    long int i;

    for (i=coordinates.size()-1; i>=0; i--) {
        if (coordinates[i].getX() < minX) {
            minX = coordinates[i].getX();
        }
        if (coordinates[i].getY() < minY) {
            minY = coordinates[i].getY();
        }
        if (coordinates[i].getX() > maxX) {
            maxX = coordinates[i].getX();
        }
        if (coordinates[i].getY() > maxY) {
            maxY = coordinates[i].getY();
        }
    }

    Coordinate ret = Coordinate(maxX - minX, maxY - minY);
    return ret;
}

std::vector<double> h_bBoxAround(std::vector<Coordinate> edge) {

    return {
        std::min(edge[0].getX(), edge[1].getX()), // left
        std::min(edge[0].getY(), edge[1].getY()), // top
        std::max(edge[0].getX(), edge[1].getX()), // right
        std::max(edge[0].getY(), edge[1].getY())  // bottom
    };
}

std::tuple<bool, Coordinate> h_midPoint(std::vector<Coordinate> edge, std::vector<Coordinate> innerCoordinates, std::vector<Coordinate> convex) {

    Coordinate coordinate;
    bool found = false;
    double angle1Cos = MAX_CONCAVE_ANGLE_COS;
    double angle2Cos = MAX_CONCAVE_ANGLE_COS;
    double a1Cos, a2Cos;

    unsigned long int i;

    for (i=0; i < innerCoordinates.size(); i++) {
        a1Cos = cos(edge[0], edge[1], innerCoordinates[i]);
        a2Cos = cos(edge[1], edge[0], innerCoordinates[i]);
    
        if (a1Cos > angle1Cos && a2Cos > angle2Cos &&
            !h_intersect({edge[0], innerCoordinates[i]}, convex) &&
            !h_intersect({edge[1], innerCoordinates[i]}, convex)) {

            angle1Cos = a1Cos;
            angle2Cos = a2Cos;
            coordinate = innerCoordinates[i];
            found = true;
        }
    }

    return std::make_tuple(found, coordinate);
}

std::vector<Coordinate> h_concave(std::vector<Coordinate> convex, double maxSqEdgeLen, Coordinate maxSearchArea, Grid grid, std::set<std::string> edgeSkipList) {

    bool midPointInserted = false, foundMidpoint = false;
    unsigned long int i;

    for (i=0; i < convex.size()-1; i++) {

        std::vector<Coordinate> edge = {convex[i], convex[i + 1]};

        // generate a key in the format X0,Y0,X1,Y1
        std::string keyInSkipList = std::to_string(edge[0].getX()) + ',' + std::to_string(edge[0].getY()) + ',' + std::to_string(edge[1].getX()) + ',' + std::to_string(edge[1].getY());

        if (sqLength(edge[0], edge[1]) < maxSqEdgeLen || edgeSkipList.count(keyInSkipList) != 0) { 
            continue; 
        }
    
        int scaleFactor = 0;
        std::vector<double> bBoxAround = h_bBoxAround(edge);
        double bBoxWidth, bBoxHeight;
        Coordinate midPoint;

        do {
            bBoxAround = grid.extendBbox(bBoxAround, scaleFactor);
            bBoxWidth = bBoxAround[2] - bBoxAround[0];
            bBoxHeight = bBoxAround[3] - bBoxAround[1];

            std::tie(foundMidpoint, midPoint) = h_midPoint(edge, grid.rangePoints(bBoxAround), convex);
            scaleFactor++;
        }  while (!foundMidpoint && (maxSearchArea.getX() > bBoxWidth || maxSearchArea.getY() > bBoxHeight));

        if (bBoxWidth >= maxSearchArea.getX() && bBoxHeight >= maxSearchArea.getY()) {
            edgeSkipList.insert(keyInSkipList);
        }

        if (foundMidpoint == true) {
            convex.insert(convex.begin() + i + 1, midPoint);
            grid.removeCoordinate(midPoint);
            midPointInserted = true;
        }
    }

    if (midPointInserted) {
        return h_concave(convex, maxSqEdgeLen, maxSearchArea, grid, edgeSkipList);
    }

    return convex;
};

std::vector<Coordinate> hull(std::vector<Coordinate> coordinates, int concavity) {

    int maxEdgeLen = concavity;

    std::vector<Coordinate> coord = filterDuplicates(sortByX(coordinates));

    if (coord.size() < 4) {

        std::vector<Coordinate> concave = coord;
        concave.push_back(coord[0]);

        return concave;
    }

    Coordinate occupiedArea = h_occupiedArea(coord);
    Coordinate maxSearchArea = Coordinate(occupiedArea.getX() * MAX_SEARCH_BBOX_SIZE_PERCENT, occupiedArea.getY() * MAX_SEARCH_BBOX_SIZE_PERCENT);

    std::vector<Coordinate> conv = convex(coord);

    std::vector<Coordinate> innerCoordinates;

    // In innerCoordinates, we will store all coord that are not in conv
    for (Coordinate c: coord) {

        int count = std::count(conv.begin(), conv.end(), c);

        if (count == 0) {

            innerCoordinates.push_back(c);
        }
    }

    // JS has this reversed
    std::reverse(innerCoordinates.begin(), innerCoordinates.end());

    double cellSize = std::ceil(1/(coord.size() / (occupiedArea.getX() * occupiedArea.getY())));

    Grid grid = Grid(innerCoordinates, cellSize);
    std::set<std::string> edgeSkipList;

    std::vector<Coordinate> concave = h_concave(conv, pow(maxEdgeLen, 2), maxSearchArea, grid, edgeSkipList);

    return concave;
}