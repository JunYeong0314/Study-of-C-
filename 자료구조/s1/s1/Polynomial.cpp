#include<iostream>
#include "Polynomial.h"

using namespace std;

Polynomial Polynomial::Add(Polynomial B) {
	Polynomial C;
	int aPos = 0, bPos = 0;

	while ((aPos <= terms) && (bPos <= B.terms)) {
		if (termArray[aPos].exp == B.termArray[bPos].exp) {
			float t = termArray[aPos].coef + B.termArray[bPos].coef;
			if (t) C.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < B.termArray[bPos].exp) {
			C.NewTerm(B.termArray[bPos].coef, B.termArray[bPos].exp);
			bPos++;
		}
		else {
			C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	} // end of while
	for (; aPos <= terms; aPos++)
		C.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos <= B.terms; bPos++)
		C.NewTerm(B.termArray[bPos].coef, B.termArray[bPos].exp);
	return C;
} // end of Add

void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	if (terms == capacity) {
		capacity *= 2;
		Term* temp = new Term[capacity];
		copy(termArray, termArray + terms, temp);
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}