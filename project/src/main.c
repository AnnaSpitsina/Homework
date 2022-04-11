#include <assert.h>
#include "matrix.h"

int main(void) {
  Matrix* m;
  // Matrix* n;
  // Matrix* k;
  m = create_matrix_from_file(
      "/mnt/c/Users/user/Desktop/technopark/Homework/mytest.txt");
  // n =
  // create_matrix_from_file("/mnt/c/Users/user/Desktop/technopark/Homework/mytesttwo.txt");
  // size_t row = 1;
  // size_t col = 1;
  // double val = 5;
  // get_rows(m, &rows);
  // set_elem(m, row, col, val);
  // assert(m->arr[m->cols * col + row] == 5);
  // n = transp(m);
  // n = mul_scalar(m, val);
  // assert(n->arr[0]==m->arr[0]);
  // for (size_t i = 0; i < n->rows; ++i) {
  // for (size_t j = 0; j < n->cols; ++j) {
  // printf("%lf ", n->arr[n->cols * i + j]);
  // }
  // }
  // k = sub(m, n);
  // free_matrix(n);
  // for (size_t i = 0; i < k->rows; ++i) {
  // for (size_t j = 0; j < k->cols; ++j) {
  // printf("%lf ", k->arr[k->cols * i + j]);
  // }
  // }
  // k = mul(m, n);
  // free_matrix(m);
  // free_matrix(n);
  for (size_t i = 0; i < m->rows; ++i) {
    for (size_t j = 0; j < m->cols; ++j) {
      printf("%lf ", m->arr[(m->cols) * i + j]);
    }
  }
  free_matrix(m);
}
