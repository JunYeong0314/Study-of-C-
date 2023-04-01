#include<iostream>
#include "SparseMatrix.h"

using namespace std;


SparseMatrix SparseMatrix::Transpose() {
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int currentB = 0;
		for (int c = 0; c < cols; c++) {
			for (int i = 0; i < terms; i++) {
				if (smArray[i].col == c) {
					b.smArray[currentB].row = c;
					b.smArray[currentB].col = smArray[i].row;
					b.smArray[currentB++].value = smArray[i].value;
				}
			}
		}
	}
	return b;
}
void SparseMatrix::NewTerm(int r, int c, int v) {
	if (terms == capacity) {
		capacity = 10;
		MatrixTerm* temp = new MatrixTerm[capacity];
		std::copy(smArray, smArray + terms, temp);
		delete[] smArray;
		smArray = temp;
	}
	smArray[terms].row = r;
	smArray[terms].col = c;
	smArray[terms++].value = v;
}

ostream& operator<<(ostream& os, const SparseMatrix& matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			int value = 0;
			for (int k = 0; k < matrix.terms; k++) {
				if (matrix.smArray[k].row == i && matrix.smArray[k].col == j) {
					value = matrix.smArray[k].value;
					break;
				}
			}
			os << value << " ";
		}
		os << endl;
	}
	return os;
}
