#include "project02.h"

/* TODO:
    "output side"
    build mask matching -w and apply to eval result
    convert_int_to_binstr
    convert_int_to_hex_str
    convert_int_to_dec_str
*/

/* convert_str_to_uint32 is called by the parser when processing
   an INTLIT, BINLIT, OR HEXLIT. "input side"
*/
uint32_t  convert_str_to_uint32(char *str, int base) {
    uint32_t result = 0;
    uint32_t place_value = 1; // base ** 0 is always 1

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
