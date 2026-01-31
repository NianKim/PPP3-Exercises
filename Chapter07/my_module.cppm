module; //first module fragment
#include<iostream>

export module my_module; //this is the interface called "my_module"

int foo = 0;

export void print_foo() { 
    std::cout << foo <<'\n';
};
export void set_foo(int x) {
    foo = x; 
}
export int get_foo() {
    return foo; 
}

/*
    Errors generated:
        clang++ -std=c++20 -x c++-module my_module.cppm --precompile -o my_module.pcm
    my_module.cppm:1:1: error: a type specifier is required for all declarations
        1 | module; //first module fragment
        | ^
    my_module.cppm:5:8: error: expected template
        5 | export module my_module; //this is the interface
        |        ^
    my_module.cppm:5:8: error: unknown type name 'module'
    my_module.cppm:9:8: error: expected template
        9 | export void print_foo() {
        |        ^
    my_module.cppm:12:8: error: expected template
    12 | export void set_foo(int x) {
        |        ^
    my_module.cppm:15:8: error: expected template
    15 | export int get_foo() {
        |        ^
    6 errors generated.
*/