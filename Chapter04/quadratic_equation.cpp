/*
[7] Quadratic equations are of the form 
a*x2 + b*x + c = 0. To solve these, 
one uses the quadratic formula: x=−b±b2−4ac2a. 
There is a problem, though: if b2- 4ac is less 
than zero, then it will fail. Write a program 
that can calculate x for a quadratic equation. 
Create a function that prints out the roots of a 
quadratic equation, given a, b, c. When the program
 detects an equation with no real roots, have it 
 print out a message. How do you know that your 
 results are plausible? Can you check that they
  are correct?
*/
#include<iostream>
#include<algorithm>

int check_discriminant(int a, int b, int c){
    if ((4*a*c) >= (b*b)){
        //this is a valid input
        return 0;
    }else{
        return -1;
    }
}

int main(){
    double a;
    double b;
    double c;
    //reading the input equation
    std::cout << "Please enter the coefficients of your formula a*x^2 + b*x + c.";
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
/*
    try{
        if()
        {
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }*/
    
}