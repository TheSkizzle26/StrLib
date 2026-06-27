#ifndef RE_H
#define RE_H

#include "str.h"
#include <stddef.h>

typedef unsigned int reTokenType;

typedef enum {
    RE_GROUP,
    RE_BRACKET,
    RE_OR,
    RE_REPEAT,
    RE_LITERAL
} RETokenTypes;

typedef struct {
    reTokenType type;
    void* data;
} REToken;

typedef struct {
    size_t length;
    size_t capacity;
    REToken* tokens;
} RETokenVec;

typedef struct {
    size_t pos;
    RETokenVec tokens;
} REParseContext;

RETokenVec RETokenVec_new();
void RETokenVec_push(RETokenVec* vec, REToken token);
Str* RE_match();

#endif

#ifdef RE_IMPLEMENTATION

#include "str.h"
#include <stddef.h>
#include <stdlib.h>

RETokenVec RETokenVec_new() {
    return (RETokenVec) {
        .length = 0,
        .capacity = 1,
        .tokens = malloc(sizeof(REToken))
    };
}

void RETokenVec_push(RETokenVec* vec, const REToken token) {
    if (vec->length == vec->capacity) {
        REToken* new = realloc(vec->tokens, sizeof(REToken) * (vec->capacity <<= 2));
        if (!new) exit(13);
        vec->tokens = new;
    }

    vec->tokens[vec->length++] = token;
}

Str* RE_match() {

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