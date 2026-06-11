#include<iostream>


template<typename T> 
struct S {
    T value;
    S(T val) : value { val } { } 
};


int main() {

    S<int> a = 67;
    S<char> b = 'v';
    S<double> c = 3.14;


    std::cout << "Successfully compiled!" << '\n';
    return 0;
}