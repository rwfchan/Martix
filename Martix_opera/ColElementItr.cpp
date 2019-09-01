#include <stdexcept>
#include <sstream>
#include "ColElementItr.h"
#include "RowItr.h"
#include "Matrix.h"

ColElementItr::ColElementItr(ColItr& colItr, const int pos) : colItr(colItr), lowerBound(0), upperBound(colItr.getMatrix().getNumRows()), pos(pos){}

double &ColElementItr::operator*() {
  if(*this) {
    return colItr.getMatrix().getMat().at(static_cast<unsigned int>(pos)).at(static_cast<unsigned int>(colItr.getIndex()));
  } else {
    std::stringstream errorStream;
    errorStream << "ColElementItr dereferenced out of bounds. Acceptable values 0 -" << (upperBound - 1)
                << ". Current position: " << pos;
    throw std::out_of_range(errorStream.str());

  }
}
ColElementItr &ColElementItr::operator++() {
  pos++;
  return *this;
}
ColElementItr &ColElementItr::operator++(int) {
  return ++(*this);
}
ColElementItr &ColElementItr::operator--() {
  pos--;
  return *this;
}
ColElementItr &ColElementItr::operator--(int) {
  return --(*this);
}
ColElementItr &ColElementItr::operator+=(const int &rhs) {
  pos += rhs;
  return *this;
}
ColElementItr ColElementItr::operator+(const int &rhs) {
  ColElementItr copy(*this);
  copy += rhs;
  return copy;
}
ColElementItr &ColElementItr::operator-=(const int &rhs) {
  pos -= rhs;
  return *this;
}
ColElementItr ColElementItr::operator-(const int &rhs) {
  ColElementItr copy(*this);
  copy -= rhs;
  return copy;
}
ColElementItr::operator bool() const {
  return pos >= lowerBound && pos < upperBound;
}
bool ColElementItr::operator!() const {
  return !static_cast<bool>(*this);
}
bool ColElementItr::operator==(const ColElementItr &rhs) const {
  if(colItr != rhs.colItr) {
    return false;
  } else if (!*this && !rhs) {
    return true;
  } else {
    return pos == rhs.pos;
  }
}
bool ColElementItr::operator!=(const ColElementItr &rhs) const {
  return !(*this == rhs);
}
bool ColElementItr::operator<(const ColElementItr &rhs) const {
  return colItr == rhs.colItr && pos < rhs.pos;
}
bool ColElementItr::operator>(const ColElementItr &rhs) const {
  return colItr == rhs.colItr && pos > rhs.pos;
}
bool ColElementItr::operator<=(const ColElementItr &rhs) const {
  return *this == rhs || *this < rhs;
}
bool ColElementItr::operator>=(const ColElementItr &rhs) const {
  return *this == rhs || *this > rhs;
}


