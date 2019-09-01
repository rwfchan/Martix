//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_MATRIXINNERDIMENSIONMISMATCHERROR_H
#define MATRIX_MATRIXINNERDIMENSIONMISMATCHERROR_H

#include "MatrixError.h"
#include "Matrix.h"

class MatrixInnerDimensionMismatchError : public MatrixError{
  //If mult_matrix lhs's numCols != rhs's numRows
 public:
  MatrixInnerDimensionMismatchError(const Matrix lhs, const Matrix rhs);

 private:
  Matrix lhs;
  Matrix rhs;
};

#endif //MATRIX_MATRIXINNERDIMENSIONMISMATCHERROR_H
