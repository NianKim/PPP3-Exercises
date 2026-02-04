#ifndef FOO_H //if not defined
#define FOO_H //creates a flag in the compilers memory

#include<iostream>

extern int foo;
void print_foo(); //function declarations, no body
void set_foo(int x);
void print(int);

#endif