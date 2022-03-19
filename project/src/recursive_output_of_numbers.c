#include "utils.h"

void recursive_output_of_numbers(int border) {
    if (border == 1) {
        printf("%d", border);}
    if (border > 1) {
        recursive_output_of_numbers(border-1);
        printf(" %d", border);}
    if (border < 1)  {
        recursive_output_of_numbers(border+1);
        printf(" %d", border);
        }
}
