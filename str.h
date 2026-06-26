#ifndef STR_H
#define STR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    char* data;
    size_t length;
} Str;

Str Str_new(char* cStr);
Str Str_slice(Str str, size_t start, size_t end);
size_t Str_count(Str str, Str sep);
size_t Str_index(Str str, Str substring);
bool Str_isNumeric(Str str);
bool Str_isAlpha(Str str);
bool Str_isAlNum(Str str);
bool Str_isLower(Str str);
bool Str_isUpper(Str str);
void Str_print(Str str);
void Str_println(Str str);

#endif

#ifdef STR_IMPLEMENTATION

#include <stdbool.h>
#include <stddef.h>
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

bool Str_isNumeric(const Str str) {
    for (size_t i = 0; i < str.length; i++) {
        const char cur = str.data[i];
        if ('0' > cur || cur > '9')
            return false;
    }

    return true;
}

bool Str_isAlpha(const Str str) {
    for (size_t i = 0; i < str.length; i++) {
        const char cur = str.data[i];
        if (('a' > cur || cur > 'z') && ('A' > cur || cur > 'Z'))
            return false;
    }

    return true;
}

bool Str_isAlNum(const Str str) {
    for (size_t i = 0; i < str.length; i++) {
        const char cur = str.data[i];
        if (('a' > cur || cur > 'z') && ('A' > cur || cur > 'Z') && ('0' > cur || cur > '9'))
            return false;
    }

    return true;
}

bool Str_isLower(const Str str) {
    for (size_t i = 0; i < str.length; i++) {
        const char cur = str.data[i];
        if ('A' <= cur && cur <= 'Z')
            return false;
    }

    return true;
}

bool Str_isUpper(const Str str) {
    for (size_t i = 0; i < str.length; i++) {
        const char cur = str.data[i];
        if ('a' <= cur && cur <= 'z')
            return false;
    }

    return true;
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