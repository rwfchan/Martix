//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_MATRIXSIZEERROR_H
#define MATRIX_MATRIXSIZEERROR_H
#include "Matrix.h"
#include "MatrixError.h"

class MatrixSizeError : public MatrixError{
  //If add or substracting matrix does not match in length and width
 public:
  MatrixSizeError(const Matrix matrix);

 private:
  Matrix matrix;

};

#endif //MATRIX_MATRIXSIZEERROR_H
