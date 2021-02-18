#include "project02.h"

uint32_t convert_str_to_uint32(char *str, int base) {
    uint32_t result = 0;
    uint32_t place_value = 1;

    for (int i = strlen(str) - 1; i >= 0; i--) {
        char ch = tolower(str[i]);

        int digit;
        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else if (ch >= 'a' && ch <= 'f')
            digit = ch - 'a' + 0xA;

        result += digit * place_value;
        place_value *= base;
    }

    return result;
}
