#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

void Matrix::initMatrix()
{
    this->matrix = new int[this->rows * this->cols]();
}

bool Matrix::isTheSameSize(Matrix *matrix)
{
    return this->rows == matrix->getRows() && this->cols == matrix->getCols();
}

Matrix::Matrix()
{
    this->rows = 0;
    this->cols = 0;
    this->matrix = nullptr;
    initMatrix();
}

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix = nullptr;
    initMatrix();
}

Matrix::~Matrix()
{
    delete[] this->matrix;
}

void Matrix::setElement(int row, int col, int value)
{
    this->matrix[row * cols + col] = value;
}

int Matrix::getElement(int row, int col)
{
    return this->matrix[row * cols + col];
}

void Matrix::print()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            cout << this->matrix[i * j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

Matrix *Matrix::add(Matrix *matrix)
{
    if (!isTheSameSize(matrix))
    {
        throw "The matrices are not the same size!";
    }

    Matrix *result = new Matrix(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            result->setElement(i, j, this->getElement(i, j) + matrix->getElement(i, j));
        }
    }

    return result;
}

Matrix *Matrix::subtract(Matrix *matrix)
{
    if (!isTheSameSize(matrix))
    {
        throw "The matrices are not the same size!";
    }

    Matrix *result = new Matrix(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            result->setElement(i, j, this->getElement(i, j) - matrix->getElement(i, j));
        }
    }

    return result;
}

Matrix *Matrix::multiply(Matrix *matrix)
{
    if (this->cols != matrix->getRows())
    {
        throw "The matrices cannot be multiplied!";
    }

    Matrix *result = new Matrix(this->rows, matrix->getCols());

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < matrix->getCols(); j++)
        {
            int sum = 0;
            for (int k = 0; k < this->cols; k++)
            {
                sum += this->getElement(i, k) * matrix->getElement(k, j);
            }
            result->setElement(i, j, sum);
        }
    }

    return result;
}

Matrix *Matrix::transpose()
{
    Matrix *result = new Matrix(this->cols, this->rows);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            result->setElement(j, i, this->getElement(i, j));
        }
    }

    return result;
}

bool Matrix::isSquare()
{
    return this->rows == this->cols;
}

bool Matrix::isSymmetric()
{
    if (!isSquare())
    {
        return false;
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->getElement(i, j) != this->getElement(j, i))
            {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::isIdentity()
{
    if (!isSquare())
    {
        return false;
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (i == j && this->getElement(i, j) != 1)
            {
                return false;
            }
            else if (i != j && this->getElement(i, j) != 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::isDiagonal()
{
    if (!isSquare())
    {
        return false;
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (i != j && this->getElement(i, j) != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int Matrix::getRows()
{
    return this->rows;
}

int Matrix::getCols()
{
    return this->cols;
}
