#include<iostream>

class Vector {  // a very simplyfied vector
    int sz;     //size
    double* elem;   //pointer to the first element
public:
    Vector(int s);  //constructor : allocate s doubles

    int size() const { return sz; } //current size
} ;

int main() {
    int x = 17;
    int* pi = &x;    //pointer to int

    double e = 2.71828;
    double* pd = &e; //pointer to double

    std::cout << "pi == " << pi << "; contents of pi == " << *pi << "\n";
    std::cout << "pd == " << pd << "; contents of pd == " << *pd << "\n";

    *pi = 27;            // OK: you can assign 27 to the int pointed to by pi
    std::cout << "pi == " << pi << "; contents of pi == " << *pi << "\n";
    std::cout << "pd == " << pd << "; contents of pd == " << *pd << "\n";
    
    *pd = 3.14159;       // OK: you can assign 3.14159 to the double pointed to by pd
    std::cout << "pi == " << pi << "; contents of pi == " << *pi << "\n";
    std::cout << "pd == " << pd << "; contents of pd == " << *pd << "\n";
    
    *pd = *pi;           // OK: you can assign an int (*pi) to a double (*pd)
    std::cout << "pi == " << pi << "; contents of pi == " << *pi << "\n";
    std::cout << "pd == " << pd << "; contents of pd == " << *pd << "\n";

    //careful with assigning pointers of different types to each other: 
    //their memory is almost never the same size and leads to memory corruption
}