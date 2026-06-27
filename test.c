#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>


int main(void) {
    const Str msg = Str_new("Hello, world!");
    printf("length: %zu\n", msg.length);
    Str_println(msg);
    Str_println(Str_slice(msg, 7, msg.length));

    const size_t count = Str_count(msg, Str_new("l"));
    printf("l count: %zu\n", count);

    const size_t index = Str_index(msg, Str_new("l"));
    printf("l first index: %zu\n", index);

    printf("numeric: %u\n", Str_isNumeric(msg));
    printf("alpha: %u\n", Str_isAlpha(msg));
    printf("alnum: %u\n", Str_isAlNum(msg));
    printf("lower: %u\n", Str_isLower(msg));
    printf("upper: %u\n", Str_isUpper(msg));

    printf("starts with Hello: %u\n", Str_startsWith(msg, Str_new("Hello")));
    printf("ends with world!: %u\n", Str_endsWith(msg, Str_new("world!")));

    Str_toLower(msg);
    Str_println(msg);
    // Str_toUpper(msg);
    // Str_println(msg);

    return 0;
}
