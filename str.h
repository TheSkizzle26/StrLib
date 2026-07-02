#ifndef STR_H
#define STR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    char* data;
    size_t length;
} Str;

Str Str_new(char* cStr);
char Str_char(Str str, size_t idx);
Str Str_take(Str str, size_t end);
Str Str_drop(Str str, size_t start);
Str Str_slice(Str str, size_t start, size_t end);
Str Str_removePrefix(Str str, Str prefix);
Str Str_removeSuffix(Str str, Str prefix);
Str Str_trim(Str str);
Str* Str_split(Str str, Str delimiter, size_t* outCount);
Str* Str_splitLines(Str str, size_t* outCount);
size_t Str_count(Str str, Str sep);
size_t Str_index(Str str, Str substring);
bool Str_equal(Str a, Str b);
bool Str_startsWith(Str str, Str prefix);
bool Str_endsWith(Str str, Str suffix);
bool Str_isNumeric(Str str);
bool Str_isAlpha(Str str);
bool Str_isAlNum(Str str);
bool Str_isLower(Str str);
bool Str_isUpper(Str str);
bool Str_isEmpty(Str str);
void Str_print(Str str);
void Str_println(Str str);

#endif

#ifdef STR_IMPLEMENTATION
#undef STR_IMPLEMENTATION

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

Str Str_new(char* cStr) {
    char* start = cStr;
    while (*cStr) cStr++;

    return (Str) {
        .data = start,
        .length = cStr - start
    };
}

char Str_char(Str str, size_t idx) {
    if (idx >= str.length)
        return 0;
    return str.data[idx];
}

Str Str_take(const Str str, const size_t end) {
    return (Str) {
        .data = str.data,
        .length = end < str.length ? end : str.length
    };
}

Str Str_drop(const Str str, const size_t start) {
    return (Str) {
        .data = str.data + start,
        .length = start < str.length ? str.length - start : 0
    };
}

Str Str_slice(const Str str, const size_t start, size_t end) {
    if (end > str.length) end = str.length;

    return (Str) {
        .data = str.data + start,
        .length = start < end ? end - start : 0
    };
}

Str Str_removePrefix(Str str, const Str prefix) {
    if (Str_startsWith(str, prefix))
        str.data += prefix.length;
    return str;
}

Str Str_removeSuffix(Str str, const Str prefix) {
    if (Str_endsWith(str, prefix))
        str.length -= prefix.length;
    return str;
}

Str Str_trim(Str str) {
    while (str.length && (str.data[0] == ' ' || str.data[0] == '\n' || str.data[0] == '\t'))
        str = Str_drop(str, 1);
    while (str.length && (str.data[str.length-1] == ' ' || str.data[str.length-1] == '\n' || str.data[str.length-1] == '\t'))
        str = Str_take(str, str.length-1);

    return str;
}

Str* Str_split(Str str, const Str delimiter, size_t* outCount) {
    Str* out = malloc(sizeof(Str));
    size_t count = 0;
    size_t capacity = 1;

    size_t i = 0;
    while (i < str.length) {
        if (Str_startsWith((Str) { .data = str.data + i, .length = str.length - i }, delimiter)) {
            if (count == capacity)
                out = realloc(out, sizeof(Str) * (capacity <<= 2));

            out[count++] = Str_take(str, i);
            str = Str_drop(str, i + delimiter.length);
            i = 0;
        } else {
            i++;
        }
    }

    if (count == capacity)
        out = realloc(out, sizeof(Str) * (capacity <<= 2));

    out[count++] = Str_take(str, i);
    *outCount = count;
    return out;
}

Str* Str_splitLines(const Str str, size_t* outCount) {
    return Str_split(str, Str_new("\n"), outCount);
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

bool Str_equal(const Str a, const Str b) {
    if (a.length != b.length)
        return false;

    for (size_t i = 0; i < a.length; i++) {
        if (a.data[i] != b.data[i])
            return false;
    }

    return true;
}

bool Str_startsWith(const Str str, const Str prefix) {
    if (prefix.length > str.length)
        return false;

    for (size_t i = 0; i < prefix.length; i++) {
        if (str.data[i] != prefix.data[i])
            return false;
    }

    return true;
}

bool Str_endsWith(const Str str, const Str suffix) {
    if (suffix.length > str.length)
        return false;

    for (size_t i = 0; i < str.length; i++) {
        if (str.data[str.length - i - 1] != suffix.data[suffix.length - i - 1])
            return false;
    }

    return true;
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

bool Str_isEmpty(const Str str) {
    for (size_t i = 0; i < str.length; i++) {
        const char cur = str.data[i];
        if (cur != ' ' && cur != '\n' && cur != '\t')
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

/*
------------------------------------------------------------------
        LICENSE
------------------------------------------------------------------
Copyright (c) 2026 Timo Barth

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you
   must not claim that you wrote the original software. If you
   use this software in a product, an acknowledgment in the
   product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and
   must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source
   distribution.
-----------------------------------------------------------------
*/