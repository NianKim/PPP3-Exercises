#include<iostream>
#include<string>
#include<vector>

template<typename T> 
struct S {
    T value;
    S(T val) : value { val } { } 
};


int main() {

    using SString = S<std::string>;
    using SVector = S<std::vector<int>>;

    S<int> a = 67;
    S<char> b = 'v';
    S<double> c = 3.14;

    SString d{"Templates!"};
    SVector e{ { 1,2,3,4 }};

    //std::cout << a << b << c << d << e << '\n';

    std::cout << "Successfully compiled!" << '\n';
    return 0;
}