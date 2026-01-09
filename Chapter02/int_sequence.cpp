#include<iostream>
int main(){
    std::cout << "Please enter three integers seperated by whitespace. \n";
    int a,b,c;
    std::cin >> a >> b >> c;
    std::cout << "Your output ordered: ";
    if(a < b && a < c){ //a is the smallest
        if(b < c){// a < b < c
            std::cout << c << ", " << b << ", " << a;
        }else{ //a < c < b
           std::cout << b << ", " << c << ", " << a; 
        }
    }else if(b < c && b < a){ //b is the smallest
        if(a < c){// b < a < c
            std::cout << c << ", " << a << ", " << b;
        }else{ //b < c < a
           std::cout << a << ", " << c << ", " << b; 
        }
    }else{ //c is the smallest
        if(b < a){// c < b < a
            std::cout << a << ", " << b << ", " << c;
        }else{ //c < a < b
           std::cout << b << ", " << a << ", " << c; 
        }
    }
}