#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    // 다항식 A 초기화
    Polynomial A;
    A.NewTerm(2, 2);
    A.NewTerm(3, 1);
    A.NewTerm(1, 0);

    // 다항식 B 초기화
    Polynomial B;
    B.NewTerm(1, 2);
    B.NewTerm(2, 1);
    B.NewTerm(3, 0);

    // 두 다항식 더하기
    Polynomial C = A.Add(B);

    // 결과 출력
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
