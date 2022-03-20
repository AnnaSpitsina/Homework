#include "utils.h"

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_MOD_REK     4

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    int test_case = atoi(argv[1]);
    const char* data;
    data = argv[2];

    switch (test_case) {
        case TST_FOO_FIX: {
            int limit = atoi(data);
            size_t ticks_count = timer_from(limit);
            printf("%zu\n", ticks_count);
            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                int base = atoi(data);
                int power =  atoi(argv[3]);
                int result = custom_power(base, power);
                printf("%i\n", result);
            } else {
                return ERR_ARGS_COUNT;}
            break;
        }
        case TST_MOD_IMPL: {
            int number = atoi(data);
            int result = is_prime_number(number);
            printf("%i\n", result);
            break;
        }
        case TST_MOD_REK: {
            int border = atoi(data);
            recursive_output_of_numbers(border);
            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}
