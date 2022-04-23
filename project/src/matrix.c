#include "matrix.h"
#include <stdlib.h>

Matrix* create_matrix_from_file(const char* path_file) {
  FILE* file_with_matrix;
  file_with_matrix = fopen(path_file, "r");
  if (file_with_matrix == NULL) {
    fprintf(stderr, "Error: Cannot open file %s for reading\n", path_file);
    return NULL;
  }
  Matrix* matrix = malloc(1 * sizeof(Matrix));
  if (matrix == NULL) {
    fclose(file_with_matrix);
    return NULL;
  }
  int k = fscanf(file_with_matrix, "%zu %zu", &matrix->rows, &matrix->cols);
  if (k != 2) {
    fprintf(stderr, "Error: Cannot find out the number of rows and cols");
  }
  matrix->array = malloc(matrix->rows * matrix->cols * sizeof(double));
  if (matrix->array == NULL) {
    fclose(file_with_matrix);
    free(matrix);
    return NULL;
  }
  for (size_t i = 0; i < matrix->rows; ++i) {
    for (size_t j = 0; j < matrix->cols; ++j) {
      int q = fscanf(file_with_matrix, "%lf",
                     &matrix->array[(matrix->cols) * i + j]);
      if (q != 1) {
        fprintf(stderr, "Error: Cannot find out the number of rows and cols");
      }
    }
  }
  fclose(file_with_matrix);
  return matrix;
}

Matrix* create_matrix(size_t rows, size_t cols) {
  Matrix* new_matrix = malloc(1 * sizeof(Matrix));
  if (new_matrix == NULL) {
    return NULL;
  }
  new_matrix->rows = rows;
  new_matrix->cols = cols;
  new_matrix->array = calloc(rows * cols, sizeof(double));
  return new_matrix;
}

void free_matrix(Matrix* matrix) {
  free(matrix->array);
  free(matrix);
}

int get_rows(const Matrix* matrix, size_t* rows) {
  if (rows == NULL || matrix == NULL) {
    return -1;
  }
  *rows = matrix->rows;
  return 0;
}

int get_cols(const Matrix* matrix, size_t* cols) {
  if (cols == NULL || matrix == NULL) {
    return -1;
  }
  *cols = matrix->cols;
  return 0;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
  if (val == NULL || matrix == NULL || row >= matrix->rows ||
      col >= matrix->cols) {
    return -1;
  }
  *val = matrix->array[matrix->cols * row + col];
  return 0;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
  if (matrix == NULL || row >= matrix->rows || col >= matrix->cols) {
    return -1;
  }
  matrix->array[matrix->cols * row + col] = val;
  return 0;
}

Matrix* mul_scalar(const Matrix* matrix, double val) {
  if (matrix == NULL) {
    return NULL;
  }
  Matrix* new_matrix = create_matrix(matrix->rows, matrix->cols);
  for (size_t i = 0; i < ((matrix->rows) * (matrix->cols)); ++i) {
    new_matrix->array[i] = val * matrix->array[i];
  }
  return new_matrix;
}

Matrix* transp(const Matrix* matrix) {
  if (matrix == NULL) {
    return NULL;
  }
  Matrix* new_matrix = create_matrix(matrix->cols, matrix->rows);
  for (size_t i = 0; i < matrix->rows; ++i) {
    for (size_t j = 0; j < matrix->cols; ++j) {
      new_matrix->array[new_matrix->cols * j + i] =
          matrix->array[matrix->cols * i + j];
    }
  }
  return new_matrix;
}

static double sum_element(double a, double b) {
  return a + b;
}

static double sub_element(double a, double b) {
  return a - b;
}

static Matrix* sum_or_sub(const Matrix* l,
                          const Matrix* r,
                          double (*operation)(double, double)) {
  Matrix* new_matrix = create_matrix(l->rows, l->cols);
  for (size_t i = 0; i < ((l->rows) * (l->cols)); ++i) {
    new_matrix->array[i] = operation(l->array[i], r->array[i]);
  }
  return new_matrix;
}

Matrix* sum(const Matrix* l, const Matrix* r) {
  if (l == NULL || r == NULL || l->rows != r->rows || l->cols != r->cols) {
    return NULL;
  }
  return sum_or_sub(l, r, sum_element);
}

Matrix* sub(const Matrix* l, const Matrix* r) {
  if (l == NULL || r == NULL || l->rows != r->rows || l->cols != r->cols) {
    return NULL;
  }
  return sum_or_sub(l, r, sub_element);
}

Matrix* mul(const Matrix* l, const Matrix* r) {
  if (l == NULL || r == NULL || l->cols != r->rows) {
    return NULL;
  }
  Matrix* new_matrix = create_matrix(l->rows, r->cols);
  for (size_t i = 0; i < l->rows; i++)
    for (size_t j = 0; j < r->cols; j++) {
      for (size_t k = 0; k < l->cols; k++)
        new_matrix->array[new_matrix->cols * i + j] +=
            (l->array[l->cols * i + k]) * (r->array[r->cols * k + j]);
    }
  return new_matrix;
}

static Matrix* delete_string_and_line() {}

int det(const Matrix* matrix, double* val) {
  if (matrix == NULL || (matrix->cols) != (matrix->rows)) {
    return -1;
  }

  if (matrix->cols == 1) {
    *val = matrix->array[0];
  }
  if (matrix->cols == 2) {
    *val = (matrix->array[0] * matrix->array[3]) -
           (matrix->array[1] * matrix->array[2]);
  }
  if (matrix->cols > 2) {
    for (int i = 0; i < matrix->cols; i++) {
      Matrix* minor_matrix = create_matrix(matrix->rows - 1, matrix->cols - 1);
      minor_matrix = delete_string_and_line(matrix, i);

      int sign = 1;
      for (int i = 0; i < matrix->cols; ++i) {
        int result =+(sign * matrix->array[matrix->cols] * det(minor_matrix, val));
        sign *= -1;
      }
    }
  }
  // *val = matrix->array[0] * det(matrix_new, val);
  return 0;
}

// Matrix* new_matrix = create_matrix(matrix->rows, matrix->cols);
// if (new_matrix->cols == 1) {
//   return *val = new_matrix->array[0];
// }
// return 0;

// Matrix* adj(const Matrix* matrix) {
//   Matrix* new_matrix = create_matrix(matrix->rows, matrix->cols);
//   return new_matrix;
// }

// Matrix* inv(const Matrix* matrix) {
//   Matrix* new_matrix = create_matrix(matrix->rows, matrix->cols);
//   return new_matrix;
// }
