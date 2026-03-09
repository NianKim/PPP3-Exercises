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
}