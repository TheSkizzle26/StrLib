#define STR_IMPLEMENTATION
#include "str.h"
#include <stdio.h>
#include <stddef.h>


int main() {
    const Str data = Str_new(
        "3,1,2,3\n"
        "\n"
        "1,1\n"
        "2,1,2\n"
    );

    size_t lineCount = 0;
    const Str* lines = Str_splitLines(data, &lineCount);
    for (size_t i = 0; i < lineCount; i++) {
        const Str line = lines[i];
        if (Str_isEmpty(line))
            continue;

        size_t partCount = 0;
        const Str* parts = Str_split(line, Str_new(","), &partCount);

        Str_print(parts[0]);
        printf(":\n");

        for (size_t j = 1; j < partCount; j++) {
            printf("  ");
            Str_println(parts[j]);
        }
    }

    free(lines);
    return 0;
}