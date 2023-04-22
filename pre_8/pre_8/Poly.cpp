//
//  Poly.cpp
//  pre_8
//
//  Created by 김준영 on 2023/04/22.
//

#include "Poly.hpp"
#include <iostream>

using namespace std;

Poly::Poly(){
    capacity = 1;
    terms = 0;
    termArray = new Term[capacity];
}

void Poly::NewTerm(const float coef, const int exp){
    if(terms == capacity-1){
        capacity *= 2;
        Term* tmp = new Term[capacity];
        copy(termArray, termArray+terms, tmp);
        delete[] termArray;
        termArray = tmp;
    }
    termArray[terms].coef = coef;
    termArray[terms++].exp = exp;
}

Poly Poly::operator+(Poly b){
    Poly c;
    int aPos=0, bPos=0;
    
    while((aPos <= terms) && (bPos <= b.terms)){
        if(termArray[aPos].exp == b.termArray[bPos].exp){
            c.NewTerm(termArray[aPos].coef + b.termArray[bPos].coef, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if(termArray[aPos].exp < b.termArray[bPos].exp){
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else{
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
        
        for(; aPos<=terms; aPos++){
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
        }
        for(; bPos<=terms; bPos++){
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
        }
    }
    return c;
}

Poly Poly::operator*(Poly b){
    Poly c;
    
    for(int i=0; i<terms; i++){
        for(int j=0; j<b.terms; j++){
            int c_coef = termArray[i].coef * b.termArray[j].coef;
            int c_exp = termArray[i].exp + b.termArray[j].exp;
            
            int sameIndex = -1;
            for(int ck_exp=0; ck_exp < c.terms; ck_exp++){
                if(c.termArray[ck_exp].exp == c_exp) sameIndex = ck_exp;
            }
            
            if((sameIndex == -1) && c_coef != 0) c.NewTerm(c_coef, c_exp);
            else c.termArray[sameIndex].coef += c_coef;
        }
    }
    return c;
}

int Poly::Eval(int x){
    int eval = 0;
    for(int i=0; i<terms; i++){
        eval += termArray[i].coef * pow(x, termArray[i].exp);
    }
    return eval;
}

void Poly::sortPoly(){
    for(int i=0; i<terms; i++){
        int j=i;
        for(int k=i+1; k<terms; k++){
            if(termArray[j].exp < termArray[k].exp) j=k;
        }
        swap(termArray[i].exp, termArray[j].exp);
        swap(termArray[i].coef, termArray[j].coef);
    }
}

ostream& operator << (ostream& os, const Poly& p){
    for(int i=0; i<p.terms; i++){
        if(i > 0){
            os << " + ";
        }
        if(p.termArray[i].coef == 1 && p.termArray[i].exp == 1){
            os << "x";
        }
        else if(p.termArray[i].coef == 1){
            os << "x^" << p.termArray[i].exp;
        }
        else if(p.termArray[i].exp == 1){
            os << p.termArray[i].coef << "x";
        }
        else{
            os << p.termArray[i].coef << "x^" << p.termArray[i].exp;
        }
    }
    os << endl;
    return os;
}
