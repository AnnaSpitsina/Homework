#include "utils.h"

int prostoe(int num) {
    if (num > 1) {
        for (int i = 2; i < num; i++)
            if ((num % i) == 0)
                return 0;
        return 1;}
    else
        return 0;
    return 1;
}
