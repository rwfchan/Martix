#include <sstream>
#include "MatrixSizeError.h"

MatrixSizeError::MatrixSizeError(const Matrix matrix) : matrix(matrix){
  std::stringstream errorStream;
  errorStream << "All rows of the matrix should have the same number of elements. Expected rows to contain " << matrix.getNumCols()
              << " elements but found row that contained " << matrix.getNumRows() << " elements." << std::endl;
  errString = errorStream.str();
}