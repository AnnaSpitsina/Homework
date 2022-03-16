#include "utils.h"

void rek(int gran) {
if (gran > 1) {
        int out = gran;
        --gran;
        rek(gran);
        printf(" %d", out);
    }
if (gran < 1) {
int out = gran;
++gran;
rek(gran);
printf(" %d", out);
}
}
