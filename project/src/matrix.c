#include "matrix.h"
#include <stdlib.h>

Matrix* create_matrix_from_file(const char* path_file) {
  FILE* fp;
  fp = fopen(path_file, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: Cannot open file %s for reading\n", path_file);
  }
  Matrix* matrix = malloc(1 * sizeof(Matrix));
  fscanf(fp, "%zu %zu", &matrix->rows, &matrix->cols);
  matrix->arr = malloc(matrix->rows * matrix->cols * sizeof(double));
  for (size_t i = 0; i < matrix->rows; ++i) {
    for (size_t j = 0; j < matrix->cols; ++j) {
      fscanf(fp, "%lf", &matrix->arr[matrix->cols * i + j]);
    }
  }
  return matrix;
}

Matrix* create_matrix(size_t rows, size_t cols) {
  Matrix* new_matrix = malloc(1 * sizeof(Matrix));
  new_matrix->rows = rows;
  new_matrix->cols = cols;
  new_matrix->arr = calloc(rows * cols, sizeof(double));
  return new_matrix;
}

void free_matrix(Matrix* matrix) {
  free(matrix->arr);
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
  if (val == NULL || matrix == NULL) {
    return -1;
  }
  if (row >= matrix->rows || col >= matrix->cols) {
    return -2;
  }
  *val = matrix->arr[matrix->cols * col + row];
  return 0;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
  if (row >= matrix->rows || col >= matrix->cols || matrix == NULL) {
    return -1;
  }
  matrix->arr[matrix->cols * col + row] = val;
  return 0;
}

Matrix* mul_scalar(const Matrix* matrix, double val) {
  Matrix* new_matrix = create_matrix(matrix->rows, matrix->cols);
  for (size_t i = 0; i < ((matrix->rows) * (matrix->cols)); ++i) {
    new_matrix->arr[i] = val * matrix->arr[i];
  }
  return new_matrix;
}

Matrix* transp(const Matrix* matrix) {
  Matrix* new_matrix = create_matrix(matrix->cols, matrix->rows);
  for (size_t i = 0; i < matrix->rows; ++i) {
    for (size_t j = 0; j < matrix->cols; ++j) {
      new_matrix->arr[new_matrix->cols * j + i] = matrix->arr[matrix->cols * i + j];
    }
  }
  return new_matrix;
}

Matrix* sum(const Matrix* l, const Matrix* r) {
  if (l->rows != r->rows || l->rows != r->rows) {
    return NULL;
  }
 Matrix* new_matrix = create_matrix(l->cols, l->rows);
 for (size_t i = 0; i < ((l->rows) * (l->cols)); ++i) {
    new_matrix->arr[i] = l->arr[i] + r->arr[i];
  }
  return new_matrix;
}

Matrix* sub(const Matrix* l, const Matrix* r) {
  if (l->rows != r->rows || l->cols != r->cols) {
    return NULL;
  }
 Matrix* new_matrix = create_matrix(l->cols, l->rows);
 for (size_t i = 0; i < ((l->rows) * (l->cols)); ++i) {
    new_matrix->arr[i] = l->arr[i] - r->arr[i];
  }
  return new_matrix;
}

Matrix* mul(const Matrix* l, const Matrix* r) {
  if (l->cols != r->rows) {
    return NULL;
  }
  Matrix* new_matrix = create_matrix(l->rows, r->cols);
    for(size_t i = 0; i < l->rows; i++)
    for(size_t j = 0; j < (r->cols); j++)
    {
        for(size_t k = 0; k <l->cols; k++)
            new_matrix->arr[new_matrix->cols * i + j] += (l->arr[l->cols*i+k]) * (r->arr[r->cols*k+j]);
    }
  return new_matrix;
}