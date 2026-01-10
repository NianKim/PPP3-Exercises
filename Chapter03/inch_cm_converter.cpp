
// convert from inches to centimeters or centimeters to inches
// a suffix ’i’ or ’c’ indicates the unit of the input

#include<iostream>

int main(){
    constexpr double cm_per_inch = 2.54;             // number of centimeters in an inch
    double length = 1;                                               // length in inches or centimeters
    char unit = ' ';
    std::cout<< "Please enter a length followed by a unit (c or i):\n";
    std::cin >> length >> unit;
    if (unit == 'i'){
            std::cout << length << "in == " << length*cm_per_inch << "cm\n";
    }else{ //will default to cm conversion, even if neither of the two chars is entered.
            std::cout << length << "cm == " << length/cm_per_inch << "in\n";
    }
}