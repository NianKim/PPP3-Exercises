#include <iostream>
int main(){
    double smallest = 0;
    double largest = 0;
    double current;


    std::cout << "Please enter an double: (any other character to terminate)\n";
    while(std::cin >> current){
        std::cout << "Your entered number: " << current << '\n';
        if(0 == smallest && 0 == largest){
            smallest = current;
            largest = current;
            std::cout << "The largest number so far: " << largest << "\nThe smallest number so far: " << smallest << '\n';
        }else{
            if(current > largest){
                largest = current;
            }else if(current < smallest){
                smallest = current;
            }
            std::cout << "The largest number so far: " << largest << "\nThe smallest number so far: " << smallest << '\n';
        }   
    }
}