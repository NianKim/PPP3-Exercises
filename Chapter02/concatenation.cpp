#include <iostream>

//testing concatenation and comparison operator for string types

int main(){
    std::cout << "Please enter your first and second name \n";
    std::string first;
    std::string second;
    std::cin >> first >> second;

    std::string name = first + ' ' + second; //concatenation is the "merging" of strings
    std::cout << "Hello, " << name << '\n';

    //read and compare two names
    std::cout << "\nPlease enter two names\n";
    std::string first_name;
    std::string second_name;
    std::cin >> first_name >> second_name;
    
    if (first_name == second_name){
        std::cout << "That's the same name twice.\n";
    }
    if (first_name < second_name){
        std::cout << first_name << " is alphabetically before " << second_name << ".\n";
    }
    if(first_name > second_name){
        std::cout << second_name << " is alphabetically before " << first_name << ".\n";
    }
}