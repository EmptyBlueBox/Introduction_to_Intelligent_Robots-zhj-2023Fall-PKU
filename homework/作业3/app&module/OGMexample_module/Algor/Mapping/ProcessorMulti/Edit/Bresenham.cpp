#include "Bresenham.h"

void Bresenham(int x1, int y1, int x2, int y2, std::vector<Location>& locationVec)
{
        bool swapflag = false;
        if (x1 > x2){
                int tmpx = x1;
                int tmpy = y1;
                x1 = x2;
                y1 = y2;
                x2 = tmpx;
                y2 = tmpy;
                swapflag = true;
        }

        int dx = x2-x1;
        int dy = y2-y1;
        int x = x1;
        int y = y1;
        int sub = (dy<<1)-dx;
        locationVec.push_back(Location(x, y));
        while(x<x2){
                ++x;
                if (sub > 0){
                        sub += (dy<<1) - (dx<<1);
                        ++y;
                }else {
                        sub += (dy<<1);
                }
                locationVec.push_back(Location(x, y));
        }

        if (swapflag){
                unsigned int size = locationVec.size();
                for (unsigned int i = 0; i < size/2 ; ++i){
                        Location tmp = locationVec[i];
                        locationVec[i] = locationVec[size-i-1];
                        locationVec[size-i-1] = tmp;
                }
        }
}

void CalcShortestDistance(const Location& startPos, const Location& endPos, std::vector<Location>& locationVec)
{
    if (startPos.x==endPos.x && startPos.y==endPos.y)
        return ;

    if (endPos.x == startPos.x){ //x相同
        if (endPos.y > startPos.y){
            for (unsigned int i = 0; i < (unsigned int)(endPos.y-startPos.y); ++i){
                locationVec.push_back(Location(startPos.x, startPos.y+i+1));
            }
        }else{
            for (unsigned int i = 0; i < (unsigned int)(startPos.y-endPos.y); ++i){
                locationVec.push_back(Location(startPos.x, startPos.y-i-1));
            }
        }
        return ;
    }

    float k = (float)(endPos.y-startPos.y)/(endPos.x-startPos.x);

    if (k >= 0 && k <= 1){ //斜率为0~1

        Bresenham(startPos.x,startPos.y,endPos.x,endPos.y,locationVec);

    }else if (k > 1){ //斜率为1~无穷大

        Bresenham(startPos.y,startPos.x,endPos.y,endPos.x,locationVec);
        for (std::vector<Location>::iterator it = locationVec.begin(); it!=locationVec.end(); ++it){
            int tmp = (*it).x;
            (*it).x = (*it).y;
            (*it).y = tmp;
        }

    }else if (k >= -1 && k < 0){ //斜率为-1~0

        Bresenham(startPos.x,-startPos.y,endPos.x,-endPos.y,locationVec);
        for (std::vector<Location>::iterator it = locationVec.begin(); it!=locationVec.end(); ++it)
            (*it).y = -(*it).y;

    }else if (k < -1){ //斜率为无穷小~-1

        Bresenham(-startPos.y,startPos.x,-endPos.y,endPos.x,locationVec);
        for (std::vector<Location>::iterator it = locationVec.begin(); it!=locationVec.end(); ++it){
            int tmp = (*it).x;
            (*it).x = (*it).y;
            (*it).y = tmp;
            (*it).y = -(*it).y;
        }
    }

    locationVec.erase(locationVec.begin());
}

