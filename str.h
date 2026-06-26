#ifndef STR_H
#define STR_H

#include <stddef.h>

typedef struct {
    char* data;
    size_t length;
} Str;

Str Str_new(char* cStr);
Str Str_slice(Str str, size_t start, size_t end);
void Str_print(Str str);
void Str_println(Str str);

#endif

#ifdef STR_IMPLEMENTATION

#include <stdio.h>

Str Str_new(char* cStr) {
    char* start = cStr;
    while (*cStr) cStr++;

    return (Str) {
        .data = start,
        .length = cStr - start
    };
}

Str Str_slice(const Str str, const size_t start, size_t end) {
    if (end > str.length) end = str.length;

    return (Str) {
        .data = str.data + start,
        .length = start < end ? end - start : 0
    };
}

void Str_print(const Str str) {
    for (size_t i = 0; i < str.length; i++)
        putchar(str.data[i]);
}

void Str_println(const Str str) {
    for (size_t i = 0; i < str.length; i++)
        putchar(str.data[i]);

    putchar('\n');
}

#endif