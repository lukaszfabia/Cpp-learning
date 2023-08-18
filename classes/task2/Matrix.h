#ifndef MATRIX_H
#define MATRIX_H

#include <string>

using namespace std;
class Matrix {
private:
    int* matrix;
    int rows;
    int cols;

    void initMatrix();
    bool isTheSameSize(Matrix* matrix);

public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();

    void setElement(int row, int col, int value);
    int getElement(int row, int col);

    void print();

    Matrix* add(Matrix* matrix);
    Matrix* subtract(Matrix* matrix);
    Matrix* multiply(Matrix* matrix);
    Matrix* transpose();

    bool isSquare();
    bool isSymmetric();
    bool isIdentity();
    bool isDiagonal();

    int getRows();
    int getCols();
};

#endif