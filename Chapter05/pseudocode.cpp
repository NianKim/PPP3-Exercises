#include<iostream>

int main(){
    std::cout << "Please enter an expression (we can handle +, -, *, and /)\n ";
    std::cout << "add and x to end epxression (e.g., 1+2*3x): ";
    int lval = 0;
    int rval = 0;
    std::cin >> lval; //read leftmost operand
    if(!std::cin){
        std::cout << "Error: no first operand\n";
        return -1;
    }

    for(char op; std::cin >> op;){ //read operator and right-hand operand repeatedly
        if (op += 'x'){
            std::cin >> rval;
        } 
        if(!std::cin){
            std::cout << "Error: no second operand \n";
        }
        switch(op){
            case '+':
                lval += rval;       //add: lval = lval + rval
                break;
            case '-':
                lval -= rval;       //subtract: lval = lval - rval
                break;
            case '*':
                lval *= rval;       //multiply: lval = lval * rval
                break;
            case '/':
                lval /= rval;       //divide: lval = lval / rval
                break;
            default:
                std::cout << "Result: " << lval << '\n';
                return 0;
        }
    }
    //error
    std::cout << "Bad expression";
    return 2;
}
//atm the calculations are not in accordance to mathematical norms