//This program is testing the possibilities of the character '\n' and std::endl
#include <iostream>

int main(){
    std::cout << "This is a line of text!" << std::endl;
    std::cout << "This is too!\n";
    std::cout << "Can you spot the difference here?\n" << std::endl;
    std::cout << "\nThere's much" << '\n' << "to be played around with~" << std::endl;
    //return 0;
    //int main(){} is the only function that doesn't require us to call return 0;
}