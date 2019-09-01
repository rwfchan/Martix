#include <stdexcept>
#include <sstream>
#include "RowElementItr.h"
#include "RowItr.h"
#include "Matrix.h"

RowElementItr::RowElementItr(RowItr& rowItr, const int pos) : rowItr(rowItr), lowerBound(0), upperBound(rowItr.getMatrix().getNumCols()), pos(pos){}

double &RowElementItr::operator*() {
  if(*this) {
    return rowItr.getMatrix().getMat().at(static_cast<unsigned int>(rowItr.getIndex())).at(static_cast<unsigned int>(pos));
  } else {
    std::stringstream errorStream;
    errorStream << "RowElementItr dereferenced out of bounds. Acceptable values 0 -" << (upperBound - 1)
                << ". Current position: " << pos;
    throw std::out_of_range(errorStream.str());

  }
}
RowElementItr &RowElementItr::operator++() {
  pos++;
  return *this;
}
RowElementItr &RowElementItr::operator++(int) {
  return ++(*this);
}
RowElementItr &RowElementItr::operator--() {
  pos--;
  return *this;
}
RowElementItr &RowElementItr::operator--(int) {
  return --(*this);
}
RowElementItr &RowElementItr::operator+=(const int &rhs) {
  pos += rhs;
  return *this;
}
RowElementItr RowElementItr::operator+(const int &rhs) {
  RowElementItr copy(*this);
  copy += rhs;
  return copy;
}
RowElementItr &RowElementItr::operator-=(const int &rhs) {
  pos -= rhs;
  return *this;
}
RowElementItr RowElementItr::operator-(const int &rhs) {
  RowElementItr copy(*this);
  copy -= rhs;
  return copy;
}
RowElementItr::operator bool() const {
  return pos >= lowerBound && pos < upperBound;
}
bool RowElementItr::operator!() const {
  return !static_cast<bool>(*this);
}
bool RowElementItr::operator==(const RowElementItr &rhs) const {
  if(rowItr != rhs.rowItr) {
    return false;
  } else if (!*this && !rhs) {
    return true;
  } else {
    return pos == rhs.pos;
  }
}
bool RowElementItr::operator!=(const RowElementItr &rhs) const {
  return !(*this == rhs);
}
bool RowElementItr::operator<(const RowElementItr &rhs) const {
  return rowItr == rhs.rowItr && pos < rhs.pos;
}
bool RowElementItr::operator>(const RowElementItr &rhs) const {
  return rowItr == rhs.rowItr && pos > rhs.pos;
}
bool RowElementItr::operator<=(const RowElementItr &rhs) const {
  return *this == rhs || *this < rhs;
}
bool RowElementItr::operator>=(const RowElementItr &rhs) const {
  return *this == rhs || *this > rhs;
}


