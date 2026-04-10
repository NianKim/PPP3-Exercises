/*
Look up the definition of std::strlen() to see what the standard requires.
*/

#include <cstring>
#include <iostream>

int main ()
{
    char* p = nullptr;
    size_t x = strlen(p);
    //classic segfault: strlen tries to read the number of blocks of memory in p.
    //p is a nullptr (address at 0), OS will force terminate the illegal action
}