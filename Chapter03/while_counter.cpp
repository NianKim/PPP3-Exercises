#include<iostream>
//outputs all characters from a-z and their corresponding int values
int main(){
    int a = 96;
    while (a < 123){
        std::cout << a << "     "  << char(a) << '\n';
        ++a;
    }  
}