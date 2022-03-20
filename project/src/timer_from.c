#include "utils.h"

size_t timer_from(int limit) {
size_t counter = 0;
    if (limit < 0) {
        return counter;
    }
    for (int i = limit; i > 0; --i) {
        ++counter;
        printf("%d ", i);
    }
    printf("0\n");
    return ++counter;
}
