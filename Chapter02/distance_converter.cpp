#include<iostream>

int main(){
    //this program converts a user-given number of miles to kilometers.
    std::cout << "Please enter a number of miles to convert to kilometers: \n";
    double miles;
    std::cin >> miles;
    std::cout << miles << " miles are " << miles * 1.609 << " kilometers.";
    return 0;
}