#include<iostream>
int main(){
    //prompt user to enter two integer values
    std::cout << "Please enter two integer values, seperated by a whitespace.\n";
    int val1, val2;
    std::cin >> val1 >> val2; //the first number entered (before the whitespace is val1)
    if(val1 > val2){ //if val1 is greater
        std::cout << val1 << " is greater than " << val2;
        std::cout << "\nThe sum is: " << val1+val2 << '\n';
        std::cout << "The difference is: " << val2-val1 << '\n';
        std::cout << "The product is: " << val1*val2 << '\n';
        std::cout << "The ratio is: " << val1 <<'/' << val2 << '=' << val1/val2 << '\n';
    }else if (val1 < val2){//if val2 is greater
        std::cout << val2 << " is greater than " << val1;
        std::cout << "\nThe sum is: " << val1+val2 << '\n';
        std::cout << "The difference is: " << val1-val2 << '\n';
        std::cout << "The product is: " << val1*val2 << '\n';
        std::cout << "The ratio is: " << val2 << '/' << val1 << '=' << val2/val1 << '\n'; 
    }else{
        std::cout << "Value 1: " << val1;
        std::cout << "\nValue 2: " << val2;
        std::cout << "\nThese are the same number.\n";
    }
    return 0;
}
