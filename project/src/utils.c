#include "utils.h"

size_t timer_from(int from) {
    size_t counter = 0;
        if (from >0) {
                printf("%d", from);
                for (int i = from; i-->0;) {
                ++counter;
                printf(" %d", i);
                }
                    printf("\n");
                    return ++counter;}
        else
            return counter;
}



int custom_pow(int base, int power) {
    int result = 1;
    for (int i=1; i <= power; ++i) {
        result = result*base;
    }
    return result;
}

