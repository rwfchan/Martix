//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_MATRIXSIZEMISMATCHERROR_H
#define MATRIX_MATRIXSIZEMISMATCHERROR_H

#include "MatrixError.h"
#include "Matrix.h"
class MatrixSizeMismatchError : public MatrixError {
 public:
  MatrixSizeMismatchError(const Matrix lhs, const Matrix rhs);

 private:
  Matrix lhs;
  Matrix rhs;
};

#endif //MATRIX_MATRIXSIZEMISMATCHERROR_H
