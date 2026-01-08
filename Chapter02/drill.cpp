//program to build a letter for the user
#include<iostream>

int main(){
    std::cout << "Enter the name of the person you want to write to:";
    std::string first_name; 
    std::cin >> first_name;
    std::cout << "Dear " << first_name << ",\n";
    std::cout << "  How are you? I am fine. I miss you. \n";
    std::cout << "I almost forgot to tell gruncle Stanley he shouldn't shoot the bird.\n";
    //prompt user to enter another name
    std::cout << "Enter another friends name: ";
    std::string friend_name;
    std::cin >> friend_name;
    std::cout << "Have you seen " << friend_name << " lately?\n";
    //prompt user to enter their age
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    //checks if user is entering a valid age
    if(age <= 0 || age > 110){
        std::cout << "You're kidding!"; //missing function simple_error() from PPP.h header
    }else{
        std::cout << "I hear you just had a birthday and you are " << age << " years old. \n";
        if(age < 12){ //check different age brackets, this should be a switch statement
            std::cout << "Next year you will be " << age+1 << " years old.\n";
        }else if(age == 17){
            std::cout << "Next year you will be able to vote.\n";
        }else if(age > 70){
            std::cout << "Are you retired yet?\n";
        }
    }
    //signature
    std::cout << "Yours sincerely, \n\nNian";
}