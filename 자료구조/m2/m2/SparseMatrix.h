#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class SparseMatrix;

class MatrixTerm {
    friend class SparseMatrix;
public:
    int row, col, value;
};
class SparseMatrix {
public:
    SparseMatrix(int r, int c, int t);
    ~SparseMatrix();
    SparseMatrix FastTranspose();
    void NewTerm(int r, int c, int v);
    void sortMatrix();
    friend ostream& operator<<(ostream& os, const SparseMatrix& matrix);
private:
    int rows, cols, terms, capacity;
    vector<MatrixTerm> smArray;
};
#endif
