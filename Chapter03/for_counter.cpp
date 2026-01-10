#include<iostream>
//outputs all characters from a-z and their corresponding int values
int main(){
    for (int A = 66; A < 90; A++) //uppercase letters
    {
        std::cout << A << "     "  << char(A) << '\n';
    } 
    for (int a = 96; a < 122; a++) //lowercase letters
    {
        std::cout << a << "     "  << char(a) << '\n';
    }
}