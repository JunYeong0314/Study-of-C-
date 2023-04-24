//
//  Transe.hpp
//  pre_11
//
//  Created by 김준영 on 2023/04/24.
//

#ifndef Transe_hpp
#define Transe_hpp
#include <iostream>

using namespace std;

class Matrix;

class Term{
    friend class Matrix;
public:
    int row, col, value;
};

class Matrix{
private:
    int rows, cols, terms, capacity;
public:
    Term* smArray;
    Matrix(int r, int c, int t);
    Matrix Transepose();
    Matrix FastTransepose();
    void NewTerm(int r, int c, int v);
    void sortMatrix();
    friend ostream& operator << (ostream& os, const Matrix& m);
};

#endif /* Transe_hpp */
