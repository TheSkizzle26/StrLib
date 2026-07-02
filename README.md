# StrLib
A simple, single-header library for working with string slices in C.

# Features
- single-header library
- slicing
- splitting
- removal of prefixes and suffixes
- trimming
- counting of substrings
- index of substring
- checking for equality
- check if it's alphanumeric, lowercase, erc.
- printing

# Simple Example
```C
#define STR_IMPLEMENTATION
#include "str.h"
#include <stddef.h>

int main() {
    const Str message = Str_new("Hello, world!");
    
    size_t count = 0;
    const Str* parts = Str_split(message, Str_new(" "), &count);
    
    for (size_t i = 0; i < count; i++)
        Str_println(parts[i]);
        
    return 0;
}
```