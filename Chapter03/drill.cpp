#include <iostream>
int main(){
    double number1;
    double number2;
    std::cout << "Please enter two integers: (any other character to terminate)\n";
    while(std::cin >> number1 >> number2){
        if(number1 == number2){
            std::cout << "The numbers are equal.\n";
        }else if(abs(number1-number2) < 0.01){
            std::cout << "The numbers are almost equal. \n";
        }else{
            if(number1 > number2){
                std::cout << "The smaller value is: " << number2 << "\nThe larger value is: " << number1 << '\n';
            }else{
                std::cout << "The smaller value is: " << number1 << "\nThe larger value is: " << number2 << '\n';
            }
        }   
    }
}