#ifndef BRESENHAM_H

#include <iostream>
#include <vector>




struct Location {
    int x;
    int y;
    Location() { x=0, y=0; }
    Location(int a, int b) { x=a, y=b; }
};
void Bresenham(int x1, int y1, int x2, int y2, std::vector<Location>& locationVec);
void CalcShortestDistance(const Location& startPos, const Location& endPos, std::vector<Location>& locationVec);

#define BRESENHAM_H

#endif // BRESENHAM_H
