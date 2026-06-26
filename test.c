#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>


int main(void) {
    const Str message = Str_new("Hi!");
    printf("length: %zu\n", message.length);
    Str_println(message);

    return 0;
}
