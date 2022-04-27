#include "matrix.h"
#include "exceptions.h"

namespace prep {
Matrix::Matrix(size_t rows, size_t cols) {
  rows_ = rows;
  cols_ = cols;
  array_ = new double[rows * cols];
}

Matrix::Matrix(std::istream& is) {
  is >> rows_;
  is >> cols_;
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < cols_; ++j) {
      is >> array_[(cols_)*i + j];
    }
  }
}

size_t Matrix::getRows() const {
  return rows_;
}

size_t Matrix::getCols() const {
  return cols_;
}

double Matrix::operator()(size_t i, size_t j) const {
  return array_[cols_ * i + j];
}

double& Matrix::operator()(size_t i, size_t j) {
  return array_[cols_ * i + j];
}

bool Matrix::operator==(const Matrix& rhs) const {
  if (cols_ != rhs.cols_ || rows_ != rhs.rows_) {
    OutOfRange;
  }
  for (size_t i = 0; i < rows_ * cols_; ++i) {
    if (array_[i] == rhs.array_[i])
      return true;
  }
}

bool Matrix::operator!=(const Matrix& rhs) const {
   if (cols_ != rhs.cols_ || rows_ != rhs.rows_) {
    OutOfRange;
  }
  for (size_t i = 0; i < rows_ * cols_; ++i) {
    if (array_[i] != rhs.array_[i])
      return true;
  } 
}

}  // namespace prep
