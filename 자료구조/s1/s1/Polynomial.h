#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Term {
    friend class Polynomial;
public:
    float coef; //계수
    int exp; //지수
};

class Polynomial {
public:
    Polynomial() = default;
    Polynomial Add(Polynomial poly);
    Polynomial Mult(Polynomial poly);
    void NewTerm(const float f, const int exp);
    float Eval(float f);
    Term* termArray; // array of nonzero terms
    int capacity; // size of termArray 
    int terms; // number of nonzero terms
};

#endif // POLYNOMIAL_H
