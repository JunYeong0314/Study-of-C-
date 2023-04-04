#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main() {
    SparseMatrix A(3, 3, 0);
    A.NewTerm(0, 0, 1);
    A.NewTerm(0, 1, 2);
    A.NewTerm(0, 2, 3);
    A.NewTerm(1, 1, 2);
    A.NewTerm(1, 2, 5);
    A.NewTerm(2, 2, 3);

    // Print the matrix
    cout << "A:" << endl;
    cout << A << endl;

    // Transpose the matrix and print it
    SparseMatrix B = A.Transpose();
    cout << "B:" << endl;
    cout << B << endl;

    return 0;
}