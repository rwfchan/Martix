#include <sstream>
#include "MatrixSizeMismatchError.h"

MatrixSizeMismatchError::MatrixSizeMismatchError(const Matrix lhs, const Matrix rhs) : lhs(lhs), rhs(rhs){
  std::stringstream errorStream;
  errorStream << "Matrices must be the samesize but Matrix 1 is " << lhs.getNumRows() << " X " << lhs.getNumCols()
              << " but Matrix 2 is " << rhs.getNumRows() << " X " << rhs.getNumCols() << std::endl;
  errString = errorStream.str();
}