#include "utils.h"

int custom_pow(int base, int power) {
    int result = 1;
    for (int i=1; i <= power; ++i) {
        result = result*base;
    }
    return result;
}