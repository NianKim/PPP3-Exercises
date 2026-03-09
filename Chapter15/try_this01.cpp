#include<iostream>
using namespace std;

void sizes()
{
        cout << "the size of char in bytes is " << sizeof(char) << '\n';
        cout << "the size of bool in bytes is " << sizeof(bool) << '\n';
        
        cout << "the size of unsigned int in bytes is " << sizeof(unsigned int) << '\n';
        cout << "the size of int in bytes is " << sizeof(int) << '\n';

        cout << "the size of float in bytes is " << sizeof(float) << '\n';

        cout << "the size of int* in bytes is " << sizeof(int*) << '\n'; 
        cout << "the size of double in bytes is " << sizeof(double) << '\n';
        cout << "the size of double* in bytes is " << sizeof(double*) << '\n';
}

int main() {
    sizes();
    return 0;
}