#include "Matrix.h"
#include "MatrixError.h"
#include "MatrixSizeError.h"
#include "MatrixSizeMismatchError.h"
#include "MatrixInnerDimensionMismatchError.h"
#include <fstream>

Matrix::Matrix() : numRows(0), numCols(0){}

Matrix::Matrix(const std::vector<std::vector<double>>& mat) : mat(mat), numRows(static_cast<unsigned int>(mat.size())),
                                                              numCols(static_cast<unsigned int>(mat.at(0).size())){
  for(unsigned int i = 0; i < static_cast<unsigned int>(numRows); i++) {
    if(static_cast<unsigned int>(numCols) != mat.at(i).size()){
      numRows = static_cast<unsigned int>(mat.at(i).size());
      throw MatrixSizeError(*this);
    }
  }
}

Matrix::Matrix(const double val, const int numRows, const int numCols) : numRows(numRows), numCols(numCols){
  mat.resize(static_cast<unsigned int>(numRows));

  for(int i = 0; i < numRows; i++) {
    mat.at(static_cast<unsigned int>(i)).resize(static_cast<unsigned int>(numCols));
  }

}



//This is to print out the matrix
std::ostream& operator << (std::ostream& out, Matrix& matrix) {
  for(int i = 0; i < matrix.numRows; i++) {
    for(int j = 0; j < matrix.numCols; j++) {
      std::cout << matrix.mat.at(static_cast<unsigned int>(i)).at(static_cast<unsigned int>(j)) << " ";
    }
    std::cout << std::endl;
  }

  return out;
}



//This is to store the matrix
std::istream& operator >> (std::istream& in, Matrix& matrix) {
  in >> matrix.numRows;
  in >> matrix.numCols;

  matrix.mat.resize(static_cast<unsigned int>(matrix.numRows));

  for(unsigned int i = 0; i < static_cast<unsigned int>(matrix.numRows); i++) {
    matrix.mat.at(i).resize(static_cast<unsigned int>(matrix.numCols));
  }

  for(unsigned int i = 0; i < static_cast<unsigned int>(matrix.numRows); i++) {
    for(unsigned int j = 0; j < static_cast<unsigned int>(matrix.numCols); j++) {
      in >> matrix.mat.at(i).at(j);
    }
  }

  return in;
}

//Getter
int Matrix::getNumRows() const {
  return numRows;
}
int Matrix::getNumCols() const {
  return numCols;
}

Matrix Matrix::operator-() const {
  Matrix matrix(*this);

  for(unsigned int i = 0; i < static_cast<unsigned int>(numRows); i++) {
    for(unsigned int j = 0; j < static_cast<unsigned int>(numCols); j++) {
      matrix.mat.at(i).at(j) = matrix.mat.at(i).at(j) * -1;
    }
  }

  return matrix;
}

//Matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const {
  if(this->numRows != rhs.numRows || this->numCols != rhs.numCols) {
    throw MatrixSizeMismatchError(*this, rhs);
  }

  Matrix sum_matrix(*this);

  for(unsigned int i = 0; i < static_cast<unsigned int>(rhs.numRows); i++) {
    for(unsigned int j = 0; j < static_cast<unsigned int>(rhs.numCols); j++) {
      sum_matrix.mat.at(i).at(j) = sum_matrix.mat.at(i).at(j) + rhs.mat.at(i).at(j);
    }
  }



  return sum_matrix;
}
Matrix Matrix::operator+(const double &rhs) const {
  Matrix sum_matrix(*this);

  for (auto &i : sum_matrix.mat) {
    for (double &j : i) {
      j = j + rhs;
    }
  }

  return sum_matrix;
}
Matrix &Matrix::operator+=(const Matrix &rhs) {
  *this = *this + rhs;

  return *this;
}
Matrix &Matrix::operator+=(const double &rhs) {
  *this = *this + rhs;

  return *this;
}
Matrix operator+(const double lhs, const Matrix &rhs) {
  Matrix sum_matrix(rhs);

  for(auto &i : sum_matrix.mat) {
    for(double &j : i) {
      j = lhs + j;
    }
  }

  return sum_matrix;
}

//Matrix subtraction
Matrix Matrix::operator-(const Matrix &rhs) const {
  if(this->numRows != rhs.numRows || this->numCols != rhs.numCols) {
    throw MatrixSizeMismatchError(*this, rhs);
  }

  Matrix sub_matrix(*this);

  for(unsigned int i = 0; i < static_cast<unsigned int>(sub_matrix.numRows); i++) {
    for(unsigned int j = 0; j < static_cast<unsigned int>(sub_matrix.numCols); j++) {
      sub_matrix.mat.at(i).at(j) = sub_matrix.mat.at(i).at(j) - rhs.mat.at(i).at(j);
    }
  }

  return sub_matrix;
}
Matrix Matrix::operator-(const double &rhs) const {
  Matrix sub_matrix(*this);

  for(auto &i : sub_matrix.mat) {
    for(double &j : i) {
      j = j - rhs;
    }
  }

  return sub_matrix;
}

Matrix operator-(const double lhs, const Matrix &rhs) {
  Matrix sub_matrix(rhs);

  sub_matrix = -sub_matrix + lhs;

  return sub_matrix;
}
Matrix &Matrix::operator-=(const Matrix &rhs) {
  *this = *this - rhs;

  return *this;
}
Matrix &Matrix::operator-=(const double &rhs) {
  *this = *this - rhs;

  return *this;
}

//Matrix multiplition
Matrix Matrix::operator*(const Matrix &rhs) const {
  if(this->numCols != rhs.numRows) {
    throw MatrixInnerDimensionMismatchError(*this, rhs);
  }

  Matrix mult_matrix(0, this->numRows, rhs.numCols);
  double sum = 0;

  for(unsigned int i = 0; i < static_cast<unsigned int>(mult_matrix.numRows); i++) {
    for(unsigned int j = 0; j < static_cast<unsigned int>(mult_matrix.numCols); j++) {
      for(unsigned int k = 0; k < static_cast<unsigned int>(this->numCols); k++) {

        //FIXME Might be problem with matrix mult
        sum = sum + this->mat.at(i).at(k) * rhs.mat.at(k).at(j);
      }
      mult_matrix.mat.at(i).at(j) = sum;
      sum = 0;
    }
  }

  return mult_matrix;
}
Matrix Matrix::operator*(const double &rhs) const {
  Matrix mult_matrix(*this);

  for(auto &i : mult_matrix.mat) {
    for(double &j : i) {
      j = j * rhs;
    }
  }

  return mult_matrix;
}
Matrix operator*(const double& lhs, const Matrix& rhs) {
  Matrix mult_matrix(rhs);

  for(auto &i : mult_matrix.mat) {
    for(double &j : i) {
      j = lhs * j;
    }
  }

  return mult_matrix;
}
Matrix &Matrix::operator*=(const Matrix &rhs) {
  *this = *this * rhs;

  return *this;
}
Matrix &Matrix::operator*=(const double &rhs) {
  *this = *this * rhs;

  return *this;
}

std::vector<std::vector<double>> &Matrix::getMat() {
  return mat;
}

RowItr Matrix::operator[](int i) {
  return RowItr(*this, i);
}
RowItr Matrix::rowBegin() {
  return RowItr(*this, 0);
}
RowItr Matrix::rowEnd() {
  return RowItr(*this, getNumRows());
}
ColItr Matrix::colBegin() {
  return ColItr(*this, 0);
}
ColItr Matrix::colEnd() {
  return ColItr(*this, getNumCols());
}











