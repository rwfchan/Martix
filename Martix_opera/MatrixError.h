//
// Created by mfbut on 3/1/2018.
//

#ifndef MATRIX_MATRIXERROR_H
#define MATRIX_MATRIXERROR_H

#include <exception>
#include <string>

class MatrixError : public std::exception  {
 protected:
 public:
  virtual const char* what() const noexcept override;
 protected:
  std::string errString;
};

#endif //MATRIX_MATRIXERROR_H
