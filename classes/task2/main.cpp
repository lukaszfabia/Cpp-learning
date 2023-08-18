#include <iostream>
#include <stdexcept>
#include <random>
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;

Matrix* generatedMatrix(int rows, int cols)
{
    Matrix* matrix = new Matrix(rows, cols);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix->setElement(i, j, dis(gen));
        }
    }
    return matrix;
}

int main() {
    
    Matrix* matrix1 = generatedMatrix(2, 3);
    matrix1->print();
    Matrix* matrix2 = generatedMatrix(3, 2);
    matrix2->print();

    Matrix *res = matrix1->multiply(matrix2);
    res->print();
    return 0;
}


