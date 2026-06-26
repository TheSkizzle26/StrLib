#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>


int main(void) {
    const Str msg = Str_new("Hello, world!");
    printf("length: %zu\n", msg.length);
    Str_println(msg);
    Str_println(Str_slice(msg, 7, msg.length));

    return 0;
}
