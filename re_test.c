#define RE_IMPLEMENTATION
#include "re.h"
#define STR_IMPLEMENTATION
#include "str.h"


int main() {
    const Str str = Str_new("word (some more) another");
    const Str regex = Str_new("/(\\(.*?\\))/");

    size_t matchCount = 0;
    const Str* matches = RE_match(str, regex, &matchCount);

    for (size_t i = 0; i < matchCount; i++)
        Str_println(matches[i]);

    return 0;
}