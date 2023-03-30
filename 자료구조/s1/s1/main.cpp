#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    // ���׽� A �ʱ�ȭ
    Polynomial A;
    A.NewTerm(2, 2);
    A.NewTerm(3, 1);
    A.NewTerm(1, 0);

    // ���׽� B �ʱ�ȭ
    Polynomial B;
    B.NewTerm(1, 2);
    B.NewTerm(2, 1);
    B.NewTerm(3, 0);

    // �� ���׽� ���ϱ�
    Polynomial C = A.Add(B);

    // ��� ���
    cout << "A: ";
    for (int i = 0; i < A.terms; i++) {
        cout << A.termArray[i].coef << "x^" << A.termArray[i].exp << " + ";
    }
    cout << endl;

    cout << "B: ";
    for (int i = 0; i < B.terms; i++) {
        cout << B.termArray[i].coef << "x^" << B.termArray[i].exp << " + ";
    }
    cout << endl;

    cout << "C: ";
    for (int i = 0; i < C.terms; i++) {
        cout << C.termArray[i].coef << "x^" << C.termArray[i].exp << " + ";
    }
    cout << endl;

    return 0;
}
