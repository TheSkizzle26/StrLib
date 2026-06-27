#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>
#include <stddef.h>


int main(void) {
    const Str msg = Str_new("Hello, world!");
    printf("length: %zu\n", msg.length);
    Str_println(msg);
    Str_println(Str_take(msg, 7));
    Str_println(Str_drop(msg, 7));

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

    const Str data = Str_new("IMPORTANT_VALUE=IuseArchbtw");
    const Str value = Str_drop(data, Str_index(data, Str_new("=")) + 1);
    Str_println(value);

    const Str toSplit = Str_new("Hello, these are, random,words,,Hello,");
    size_t splitCount = 0;
    const Str* splits = Str_split(toSplit, Str_new(","), &splitCount);

    printf("splits:\n");
    for (size_t i = 0; i < splitCount; i++) {
        printf("%zu: ", i);
        Str_println(splits[i]);
    }

    return 0;
}
