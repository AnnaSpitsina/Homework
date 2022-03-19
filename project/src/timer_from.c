#include "utils.h"

size_t timer_from(int from) {
    size_t counter = 0;
        if (from <0) {
            return counter;}
        else
            {for (int i = from; i>0; --i) {
            ++counter;
            printf("%d ", i);
            }
                printf("0\n");
                return ++counter;}
}

