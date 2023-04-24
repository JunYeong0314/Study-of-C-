#include "Transe.hpp"
#include <iostream>

Matrix::Matrix(int r, int c, int t){
    rows = r;
    cols = c;
    terms = t;
    capacity = t;
    smArray = new Term[capacity];
}

Matrix Matrix::Transepose(){
    Matrix b(cols, rows, terms);
    int currentB = 0;
    
    for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                b.smArray[currentB].row = i;
                b.smArray[currentB].col = j;
                b.smArray[currentB].value = 0;
                currentB++;
            }
        }
    
    if(terms > 0){
        for(int c=0; c<cols; c++){
            for(int i=0; i<terms; i++){
                if(smArray[i].col == c){
                    b.smArray[currentB].row = c;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB++].value = smArray[i].value;
                }
            }
        }
    }
    return b;
}

Matrix Matrix::FastTransepose(){
    Matrix b(cols, rows, terms);
    
    if(terms > 0){
        int* rowsize = new int[cols];
        int* rowstart = new int[cols];
        
        for(int i=0; i<terms; i++){
            rowsize[smArray[i].col]++;
        }
        rowstart[0] = 0;
        for(int i=1; i<terms; i++){
            rowstart[i] = rowstart[i-1] + rowsize[i-1];
        }
        for(int i=0; i<terms; i++){
            int j = rowstart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowstart[smArray[i].col]++;
        }
        delete[] rowsize;
        delete[] rowstart;
    }
    return b;
}

void Matrix::NewTerm(int r, int c, int v){
    if(capacity == terms){
        capacity *= 2;
        Term* tmp = new Term[capacity];
        copy(smArray, smArray+terms, tmp);
        delete[] smArray;
        smArray = tmp;
    }
    smArray[terms].row = r;
    smArray[terms].col = c;
    smArray[terms++].value = v;
}

void Matrix::sortMatrix(){
    for(int i=0; i<terms; i++){
        int j=i;
        for(int k=i+1; k<terms; k++){
            if(smArray[j].row == smArray[k].row){
                if(smArray[j].col > smArray[k].col) j=k;
            }
            if(smArray[j].row > smArray[k].row) j=k;
        }
        swap(smArray[i].row, smArray[j].row);
        swap(smArray[i].col, smArray[j].col);
        swap(smArray[i].value, smArray[j].value);
    }
}

ostream& operator<<(ostream& os, const Matrix& matrix) {
    os << "2" << endl;
    for (int i = 0; i < matrix.terms; i++) {
        if (matrix.smArray[i].value != 0) {
            os << matrix.smArray[i].row+1 << " " << matrix.smArray[i].col+1 << " " << matrix.smArray[i].value << endl;
        }
    }
    return os;
}
