//
//  Poly.hpp
//  pre_8
//
//  Created by 김준영 on 2023/04/22.
//

#ifndef Poly_hpp
#define Poly_hpp
#include <iostream>

using namespace std;

class Term{
    friend class Poly;
public:
    float coef;
    int exp;
};

class Poly{
public:
    Poly();
    void NewTerm(const float coef, const int exp);
    void sortPoly();
    int Eval(int x);
    Poly operator+(Poly b);
    Poly operator*(Poly b);
    Term* termArray;
    int capacity;
    int terms;
    friend ostream& operator << (ostream& os, const Poly& p);
};
#endif /* Poly_hpp */
