#include "utils.h"

 size_t timer_from(int from) {
    size_t counter = 0;
        if (from >0)
                {printf("%d", from);
                for (int i = from; i-->0; ) 
                {
                ++counter;
                printf(" %d", i);
                }
                    printf("\n");
                    return ++counter;
                }
                else return counter;
}

// TODO(Spitsina Anna): Implement `power of` function
/*
int custom_pow(int base, int power) {
    return 0;
}
*/
