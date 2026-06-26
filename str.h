#ifndef STR_H
#define STR_H

#include <stddef.h>

typedef struct {
    char* data;
    size_t length;
} Str;

Str Str_new(char* cStr);
Str Str_slice(Str str, size_t start, size_t end);
size_t Str_count(Str str, Str sep);
size_t Str_index(Str str, Str substring);
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

size_t Str_count(const Str str, const Str sep) {
    size_t count = 0;
    size_t sepIdx = 0;

    for (size_t i = 0; i < str.length; i++) {
        const char strChar = str.data[i];
        const char sepChar = sep.data[sepIdx];

        if (strChar == sepChar) {
            sepIdx++;

            if (sepIdx == sep.length) {
                sepIdx = 0;
                count++;
            }
        } else {
            sepIdx = 0;
        }
    }

    return count;
}

size_t Str_index(const Str str, const Str substring) {
    size_t sepIdx = 0;

    for (size_t i = 0; i < str.length; i++) {
        const char strChar = str.data[i];
        const char sepChar = substring.data[sepIdx];

        if (strChar == sepChar) {
            sepIdx++;

            if (sepIdx == substring.length)
                return i - substring.length + 1;
        } else {
            sepIdx = 0;
        }
    }

    return -1;
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