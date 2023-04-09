#include <iostream>
#include <vector>
#include "SparseMatrix.h"

using namespace std;

SparseMatrix::SparseMatrix(int r, int c, int t) {
    rows = r;
    cols = c;
    terms = t;
    smArray.reserve(terms);
}

SparseMatrix::~SparseMatrix() {
    
}

SparseMatrix SparseMatrix::FastTranspose() {
    SparseMatrix b(cols, rows, terms);
    if (terms > 0) {
        int* rowsize = new int[cols];
        int* rowstart = new int[cols];
        fill(rowsize, rowsize + cols, 0);
        for (int i = 0; i < terms; i++) {
            rowsize[smArray[i].col]++;
        }
        rowstart[0] = 0;
        for (int i = 1; i < cols; i++) {
            rowstart[i] = rowstart[i - 1] + rowsize[i - 1];
        }
        for (int i = 0; i < terms; i++) {
            b.smArray.push_back({ smArray[i].col, smArray[i].row, smArray[i].value });
            rowstart[smArray[i].col]++;
        }
        delete[] rowsize;
        delete[] rowstart;
    }
    return b;
}

void SparseMatrix::sortMatrix() {
    for (int i = 0; i < terms; i++) {
        int j = i;
        for (int k = i + 1; k < terms; k++) {
            if (smArray[k].row < smArray[j].row) j = k;
            else if (smArray[k].row == smArray[j].row && smArray[k].col < smArray[j].col) j = k;
        }
        swap(smArray[i].row, smArray[j].row);
        swap(smArray[i].col, smArray[j].col);
        swap(smArray[i].value, smArray[j].value);
    }

}
void SparseMatrix::NewTerm(int r, int c, int v) {
    if (v != 0) {
        smArray.push_back({ r, c, v });
        terms++;
    }
}

ostream& operator<<(ostream& os, const SparseMatrix& matrix) {
    os << "2" << endl;
    for (int i = 0; i < matrix.terms; i++) {
        if (matrix.smArray[i].value != 0) {
            os << matrix.smArray[i].row+1 << " " << matrix.smArray[i].col+1 << " " << matrix.smArray[i].value << endl;
        }      
    }
    return os;
}
