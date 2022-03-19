#include "utils.h"

void recursion(int border) {
    if (border>0) {
        if (border == 1) {
            printf("%d", border);}
        else {recursion(border-1);
        printf(" %d", border);
        }
        }    
    else
    {recursion(border+1);
    printf(" %d", border);
    }
}
