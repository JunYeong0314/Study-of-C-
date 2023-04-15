#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

using namespace std;

class Rectangle{
public:
    Rectangle(int x=0, int y = 0, int h = 0, int w = 0, int n = 0);
    ~Rectangle();
    int GetNum();
    int GetHeight();
    int GetWidth();
    int GetArea();
    friend ostream& operator << (ostream& os, const Rectangle& r);
    int rNum, xLow, yLow, height, width;
};

#endif /* Rectangle_hpp */
