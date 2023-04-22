//
//  Rectangle.hpp
//  pre_8
//
//  Created by 김준영 on 2023/04/22.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp
#include <iostream>

using namespace std;

class Rectangle{
public:
    Rectangle(int x, int y, int h, int w, int n);
    ~Rectangle();
    int GetNum() const;
    int GetHeight() const;
    int GetWidth() const;
    int GetArea() const;
    int GetX() const;
    int GetY() const;
    
    friend ostream& operator << (ostream& os, const Rectangle& r);
private:
    int rNum, xLow, yLow, height, width;
};

#endif /* Rectangle_hpp */
