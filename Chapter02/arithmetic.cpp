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
                            << "\n square root of n == " << sqrt(n)
                            << '\n';
}