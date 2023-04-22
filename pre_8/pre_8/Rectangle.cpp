//
//  Rectangle.cpp
//  pre_8
//
//  Created by 김준영 on 2023/04/22.
//

#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(int x, int y, int h, int w, int n){
    xLow = x; yLow = y; height = h; width = w; rNum = n;
}

int Rectangle::GetHeight() const{return height;}
int Rectangle::GetWidth() const{return width;}
int Rectangle::GetArea() const{return height*width;}
int Rectangle::GetX() const{return xLow;}
int Rectangle::GetY() const{return yLow;}


ostream& operator <<(ostream& os, const Rectangle& r)
{
    os << "Position is: [" << r.GetX()  << ","<< " ";
    os << r.GetY() << "]" << endl;
    os << "Height is: " << r.GetHeight() << endl;
    os << "Width is: " << r.GetWidth() << endl;
    return os;
}

