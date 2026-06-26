#ifndef STR_H
#define STR_H

#include <stddef.h>

typedef struct {
    char* data;
    size_t length;
} Str;

Str Str_new(char* cStr);
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