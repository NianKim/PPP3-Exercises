//this program is meant to illustrate the effect of type conversion in the context of narrowing and widening
#include<iostream>
int main(){
    double d = 0;
    while(std::cin >> d){ //as long as we write numbers
        int i = d;
        char c = i;
        std::cout 
        << "d==" << d 
        << "\ni==" << i 
        << "\nc==" << c 
        << "\nchar(" << c << ") \n";
    }
}