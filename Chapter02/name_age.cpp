//This program reads the name and age of the user, then reads out the months

#include <iostream>

int main(){
    std::cout << "Please enter your first and second names \n";
    std::string first;
    std::string second;
    std::cin >> first >> second;
    std::cout << "Please type in how old you are: (in decimal value)\n";
    double age; 
    //why do I get an error from Intellisense when I write std::double? -> because fundamental types are not part of the std library
    std::cin >> age; //due to string reading termination, if you write a middle name eg. "Nian Deho Kim", this leads to "Kim" being read into double age and returning 0, becaise it's the wrong type
    //I wanna figure out how to clear the "pipeline" of inputs to make sure the right thing is read to the next variable
    age = age * 12;
    std::cout << "Hello, " << first << " " << second << ". you are " << age << " months old.\n";
    return 0;
}