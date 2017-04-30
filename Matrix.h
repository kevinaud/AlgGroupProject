#include <iostream>

#ifndef MATRIX_SET_H_INCLUDED
#define MATRIX_SET_H_INCLUDED

using namespace std;

class Matrix {
public:
    int* data;
    int dim;

    Matrix(int dim) {
        this->dim = dim;
        data = new int[dim * dim];
    }

    Matrix(Matrix& m) {
        this->dim = m->dim;
        data = new int[dim * dim];
        for(int i = 0; i < (dim * dim); i++) {
            this->data[i] = m.data[i];
        }
    }

    int get(int row, int col) {
        return this->data[(dim * row) + col];
    }

    void set(int row, int col, int val) {
        this->data[(dim * row) + col] = val;
    }

    Matrix* add(Matrix& m) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                int ndx = (dim * i) + j;
                data[ndx] = data[ndx] + m.data[ndx];
            }
        }
        return this;
    }

    Matrix* subtract(Matrix& m) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                int ndx = (dim * i) + j;
                data[ndx] = data[ndx] - m.data[ndx];
            }
        }
        return this;
    }

    void print() {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << data[(dim * i) + j] << " ";
            }
            cout << endl;
        }
    }
};

#endif
