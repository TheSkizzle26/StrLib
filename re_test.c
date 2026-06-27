#define RE_IMPLEMENTATION
#include "re.h"
#include <stdio.h>


int main() {
    RETokenVec vec = RETokenVec_new();
    RETokenVec_push(&vec, (REToken) { .type = RE_GROUP, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_OR, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_GROUP, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_GROUP, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_OR, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_OR, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_OR, .data = 0 });
    RETokenVec_push(&vec, (REToken) { .type = RE_GROUP, .data = 0 });

    for (size_t i = 0; i < vec.length; i++)
        printf("%u\n", vec.tokens[i].type);

    return 0;
}