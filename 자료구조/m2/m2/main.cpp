#include <iostream>
#include <vector>
#include "SparseMatrix.h"

using namespace std;

int main() {
    int row = 0, col = 0;
    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int>(col));

    int cnt = 0; // count of zero value
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) cnt++;
        }
    }

    if (cnt >= ((row * col) * 0.7)) {
        SparseMatrix A(row, col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                A.NewTerm(i, j, arr[i][j]);
            }
        }
        // Transpose the matrix and print it
        SparseMatrix B = A.FastTranspose();
        B.sortMatrix();
        cout << B << endl;

        // No need to free memory when using vectors
    }
    else {
        vector<vector<int>> arr2(col, vector<int>(row));

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                arr2[i][j] = arr[j][i];
            }
        }

        cout << "1" << endl;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }

        // No need to free memory when using vectors
    }
    return 0;
}
