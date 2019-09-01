#include "MatrixInnerDimensionMismatchError.h"
#include <sstream>

MatrixInnerDimensionMismatchError::MatrixInnerDimensionMismatchError(const Matrix lhs, const Matrix rhs) : lhs(lhs), rhs(rhs){
  std::stringstream errorStream;
  errorStream << "Inner dimensions do not agree. First matrix has " << lhs.getNumCols() << " columes but second matrix has " << rhs.getNumRows() << " rows."
              << std::endl;
  errString = errorStream.str();
}