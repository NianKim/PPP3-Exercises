#include <iostream>

int main(){ //simple program to exercise operations
    std::cout << "Please enter a floating-point value: ";
    double n = 0;
    std::cin >> n;
    std::cout << "n == "    << n 
                            << '\n' << "n+1 == " << n+1
                            << "\nthree times n == " << 3*n
                            << "\ntwice n == " << n+n
                            << "\nn squared == " << n*n
                            << "\nhalf of n == " << n/2
                            << "\nsquare root of n == " << sqrt(n)
                            << '\n';
    //adding some things I personally want to try:
    std::cout << "Now please enter two integers:\n";
    int a = 0;
    int b = 0; 
    std::cout << "Integer: ";
    std::cin >> a;
    std::cout << "Integer: ";
    std::cin >> b;
    //after reading inputs, checking if
    int result = a/b *b+a%b;
    std::cout << "Check if " << result << " == " << a << ".\n";
}