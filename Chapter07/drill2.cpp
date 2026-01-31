/*


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