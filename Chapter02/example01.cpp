//reads and writes first name

#include <iostream>

int main(){
    std::cout << "Please enter your first name:\n";
    //first_name is a variable of type string
    std::string first_name;
    //read characters into your first_name
    std::cin >> first_name;
    std::cout << "Hello, " << first_name << "!\n";
    return 0;
}