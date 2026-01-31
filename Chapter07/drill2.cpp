/*
    [2] Write a program using a single file containing 
    three namespaces X, Y, and Z so that the following main() 
    works correctly:

    Each namespace needs to define a variable called var and a
     function called print() that outputs the appropriate var using cout.

    [3] Create a module foo with the suffix appropriate to your system:
        int foo = 0;
        export void print_foo() { ... };
        export void set_foo(int x} { foo = x; }
        export int get_foo() { return x; }
    Add what it takes to get the ... part to print foo. Write 
    file use.cpp that imports foo and tests it. Get the resulting 
    program to compile and run.

    [4] Create a header file: foo.h:
    extern int foo;
    void print_foo();
    void print(int);
    
    Write a file foo.cpp that implements the functions declared 
    in foo.h. Write file use.cpp that #includes foo.h and tests it. 
    Get the resulting program to compile and run.
*/
#include<iostream>

namespace X
{
    int var = 0;
    void print(){
        std::cout << var;
    };
}

namespace Y
{
    int var = 0;
    void print(){
        std::cout << var;
    };
} 

namespace Z
{
    int var = 0;
    void print(){
        std::cout << var;
    };
}



int main()
{
         X::var = 7;
         X::print();                  // print X’s var
         using namespace Y;
         var = 9;
         print();                       // print Y’s var
         {
                  using Z::var;
                  using Z::print;
                  var = 11;
                  print();              // print Z’s var
         }
         print();                       // print Y’s var
         X::print(); // print X’s var
}