#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int x, int y, int h, int w, int n){
    xLow = x;
    yLow = y;
    height = h;
    width = w;
    rNum = n;
}

Rectangle::~Rectangle(){}

int Rectangle::GetHeight(){return height;}
int Rectangle::GetWidth(){return width;}
int Rectangle::GetArea(){return height*width;}

ostream& operator << (ostream& os, const Rectangle& r){
    os << "Position is: [" << r.xLow  << ","<< " ";
        os << r.yLow << "]" << endl;
        os << "Height is: " << r.height << endl;
        os << "Width is: " << r.width << endl;
        return os;
}
