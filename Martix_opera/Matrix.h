//
// Created by mfbut on 1/22/2018.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <vector>
#include <iostream>

#include "RowItr.h"
#include "RowElementItr.h"
#include "ColItr.h"
#include "ColElementItr.h"


class Matrix {
  friend RowItr;
  friend RowElementItr;
  friend ColItr;
  friend ColElementItr;
 public:
  Matrix();
  
  //create a matrix from a vector of vector of doubles
  //where each inner vector is a row of the matrix
  explicit Matrix(const std::vector<std::vector<double>>& mat);
  
  // create a matrix that is numRows X numCols where all elements are val
  Matrix(const double val, const int numRows, const int numCols);

  //This one mainly use when defining operation
  Matrix(const Matrix& rhs) = default;

  int getNumRows() const;
  int getNumCols() const;

  Matrix operator-() const; // negation. negate all elements of matric

  //This one will change the value of the stored Matrix
  Matrix& operator+=(const Matrix& rhs); // matrix addition
  Matrix& operator+=(const double& rhs); //scalar addition

  //This one will return a copy of the result from addition
  Matrix operator+(const Matrix& rhs) const; // matrix addition
  Matrix operator+(const double& rhs) const; // scalar addition

  //This one will return a copy of the result from addition, where both scalar and Matrix are indicated
  friend Matrix operator+(const double lhs, const Matrix& rhs); // scalar addition

  Matrix& operator-=(const Matrix& rhs); // matrix subtraction
  Matrix& operator-=(const double& rhs); // scalar subtraction

  Matrix operator-(const Matrix& rhs) const; //matrix subtraction
  Matrix operator-(const double& rhs) const; // scalar subtraction
  friend Matrix operator-(const double lhs, const Matrix& rhs); // scalar subtraction

  Matrix& operator*=(const Matrix& rhs); // matrix multiplication
  Matrix& operator*=(const double& rhs); // scalar multiplication

  Matrix operator*(const Matrix& rhs) const; //matrix multiplication
  Matrix operator*(const double& rhs) const; // scalar multiplication
  friend Matrix operator*(const double& lhs, const Matrix& rhs); // scalar multiplication

  RowItr operator [](int i); // get RowItr over row i

  //Take in matrix and print out matrix

  //In stream should convert a Matrix from file to matrix that this program can use
  //Out stream should just be indicating how the matrix will be print out
  friend std::ostream& operator<<(std::ostream& out,  Matrix& matrix);
  friend std::istream& operator>>(std::istream& in, Matrix& matrix);

  std::vector<std::vector<double>> &getMat();

  //Used to add up rows with other numbers
  //This should be something like
    //int
    //for(auto i = rowBegin(); i != rowEnd(); i++) {
    //
  RowItr rowBegin(); //get itr to first row
  RowItr rowEnd(); //get itr to one past last row

  //Used to add up cols with other numbers
  ColItr colBegin(); // get itr to first column
  ColItr colEnd(); // get itr to one past last column

 private:
  std::vector<std::vector<double>> mat;
  int val;
  int numRows;
  int numCols;

};

#endif //MATRIX_MATRIX_H
