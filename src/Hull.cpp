#include "Hull.h"


std::vector<Coordinate> filterDuplicates(std::vector<Coordinate> pointSet) {

    std::vector<Coordinate> unique;
    unique.push_back(pointSet[0]);

    Coordinate lastPoint = pointSet[0];

    unsigned long int i;

    for (i=0; i<pointSet.size(); i++) {

        Coordinate currentPoint = pointSet[i];

        if (lastPoint.getX() != currentPoint.getX() || lastPoint.getY() != currentPoint.getY()) {

            unique.push_back(currentPoint);
        }

        lastPoint = currentPoint;
    }

    return unique;
};

bool compareXCoordinate(Coordinate a, Coordinate b) {

    return (a.getX() - b.getX()) || (a.getY() - b.getY());
};

std::vector<Coordinate> sortByX(std::vector<Coordinate> pointSet) {

    std::sort(pointSet.begin(), pointSet.end(), compareXCoordinate);
    return pointSet;
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

bool h_intersect(std::vector<Coordinate> segment, std::vector<Coordinate> pointSet) {

    unsigned long int i;

    for (i=0; i< pointSet.size()-1; i++) {
        std::vector<Coordinate> seg;
        seg.push_back(pointSet[i]);
        seg.push_back(pointSet[i+1]);

        if (segment[0].getX() == seg[0].getX() && segment[0].getY() == seg[0].getY() ||
            segment[0].getX() == seg[1].getX() && segment[0].getY() == seg[1].getY()) {
            continue;
        }

        if (intersect(segment, seg)) {
            return true;
        }
    }
    return false;
}

Coordinate h_occupiedArea(std::vector<Coordinate> pointSet) {
    double minX = std::numeric_limits<double>::min();
    double minY = std::numeric_limits<double>::min();
    double maxX = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::max();

    unsigned long int i;

    for (i=pointSet.size()-1; i>=0; i--) {
        if (pointSet[i].getX() < minX) {
            minX = pointSet[i].getX();
        }
        if (pointSet[i].getY() < minY) {
            minY = pointSet[i].getY();
        }
        if (pointSet[i].getX() > maxX) {
            maxX = pointSet[i].getX();
        }
        if (pointSet[i].getY() > maxY) {
            maxY = pointSet[i].getY();
        }
    }

    Coordinate ret = Coordinate(maxX - minX, maxY - minY);
}

std::vector<double> h_bBoxAround(std::vector<Coordinate> edge) {

    return {
        std::min(edge[0].getX(), edge[1].getX()), // left
        std::min(edge[0].getY(), edge[1].getY()), // top
        std::max(edge[0].getX(), edge[1].getX()), // right
        std::max(edge[0].getY(), edge[1].getY())  // bottom
    };
}

std::tuple<bool, Coordinate> h_midPoint(std::vector<Coordinate> edge, std::vector<Coordinate> innerPoints, std::vector<Coordinate> convex) {

    Coordinate point;
    bool found = false;
    double angle1Cos = MAX_CONCAVE_ANGLE_COS;
    double angle2Cos = MAX_CONCAVE_ANGLE_COS;
    double a1Cos, a2Cos;

    unsigned long int i;

    for (i=0; i < innerPoints.size(); i++) {
        a1Cos = cos(edge[0], edge[1], innerPoints[i]);
        a2Cos = cos(edge[1], edge[0], innerPoints[i]);
    
        if (a1Cos > angle1Cos && a2Cos > angle2Cos &&
            !h_intersect({edge[0], innerPoints[i]}, convex) &&
            !h_intersect({edge[1], innerPoints[i]}, convex)) {

            angle1Cos = a1Cos;
            angle2Cos = a2Cos;
            point = innerPoints[i];
            found = true;
        }
    }

    return std::make_tuple(found, point);
}

std::vector<Coordinate> h_concave(std::vector<Coordinate> convex, double maxSqEdgeLen, Coordinate maxSearchArea, Grid grid, std::set<std::string> edgeSkipList) {

    bool midPointInserted = false, foundMidpoint = false;
    unsigned long int i;

    for (i=0; i < convex.size(); i++) {

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
            // TODO: Failure point (?)
            //convex.splice(i + 1, 0, midPoint);
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

std::vector<Coordinate> hull(std::vector<Coordinate> pointSet, int concavity) {

    int maxEdgeLen = concavity;

    std::vector<Coordinate> points = filterDuplicates(sortByX(pointSet));

    if (points.size() < 4) {

        std::vector<Coordinate> concave = points;
        points.push_back(points[0]);

        return concave;
    }

    Coordinate occupiedArea = h_occupiedArea(points);
    Coordinate maxSearchArea = Coordinate(occupiedArea.getX() * MAX_SEARCH_BBOX_SIZE_PERCENT, occupiedArea.getY() * MAX_SEARCH_BBOX_SIZE_PERCENT);

    std::vector<Coordinate> conv = convex(points);

    std::vector<Coordinate> innerPoints;

    // In innerPoints, we will store all points that are not in conv
    for (Coordinate c: points) {

        int count = std::count(conv.begin(), conv.end(), c);

        if (count == 0) {

            innerPoints.push_back(c);
        }
    }

    double cellSize = std::ceil(1/(points.size() / (occupiedArea.getX() * occupiedArea.getY())));

    Grid grid = Grid(innerPoints, cellSize);
    std::set<std::string> edgeSkipList;

    std::vector<Coordinate> concave = h_concave(conv, pow(maxEdgeLen, 2), maxSearchArea, grid, edgeSkipList);

    return concave;
}