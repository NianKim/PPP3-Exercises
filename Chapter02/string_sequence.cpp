#include<iostream>
int main(){
    std::cout << "Please enter three Names seperated by whitespace. \n";
    std::string a,b,c;
    std::cin >> a >> b >> c;
    std::cout << "Your output ordered alphabetically: "; //uses the fact that comparators compare words alphabetically
    if(a < b && a < c){ //a is the smallest
        if(b < c){// a < b < c
            std::cout << a << ", " << b << ", " << c;
        }else{ //a < c < b
           std::cout << a << ", " << c << ", " << b; 
        }
    }else if(b < c && b < a){ //b is the smallest
        if(a < c){// b < a < c
            std::cout << b << ", " << a << ", " << c;
        }else{ //b < c < a
           std::cout << b << ", " << c << ", " << a; 
        }
    }else{ //c is the smallest
        if(b < a){// c < b < a
            std::cout << c << ", " << b << ", " << a;
        }else{ //c < a < b
           std::cout << c << ", " << a << ", " << b; 
        }
    }
}