#include<iostream>

template<typename T> 
struct S {
    T value;
    S(T val) : value { val } { } 
};


int main() {
    std::cout << "Successfully compiled!" << '\n';
    return 0;
}