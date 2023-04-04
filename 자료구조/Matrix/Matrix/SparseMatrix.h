#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

using namespace std;

class MatrixTerm {
	friend class SparseMatrix;
public:
	int row, col, value;
};
class SparseMatrix {
public:
	SparseMatrix(int r, int c, int t);
	SparseMatrix Transpose();
	SparseMatrix Add(SparseMatrix b);
	SparseMatrix Multiply(SparseMatrix b);
	void NewTerm(int r, int c, int v);
	friend ostream& operator<<(ostream& os, const SparseMatrix& matrix);
private:
	int rows=0, cols=0, terms=0, capacity=1;
	MatrixTerm* smArray = new MatrixTerm[capacity];
};
#endif
