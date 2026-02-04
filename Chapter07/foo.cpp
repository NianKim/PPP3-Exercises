#include "foo.h"
#include <iostream>

int foo = 0;

void print_foo(){
    std::cout << foo << '\n';
}

void set_foo(int x){
    foo = x;
}

int get_foo(){
    return foo;
}