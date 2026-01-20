#include<iostream>
using namespace std;

class Token{
public:
        char kind;                                                            // what kind of token
        double value;                                                      // for numbers: a value
        Token(char k) :kind{k}, value{0.0}{}                  // construct from one value
        Token(char k, double v) :kind{k}, value{v}{}    // construct from two values
};

Token get_token();     // read characters and compose tokens;       
//uses cin
double expression(){
//read an expression, see if it's followed by + or - (if yes: read the term)                                     
    double left = term(); 
    Token t = get_token();
    while(true){
        switch(t.kind){
            case '+':
            left += term();
            t = get_token();
            break;
        case '-':
            left -= term();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}
double term();     
//read an expression, see if it's followed by * or / (if yes: read the term)                                     
    double left = primary(); 
    Token t = get_token();
    while(true){
        switch(t.kind){
            case '*':
            left *= term();
            t = get_token();
            break;
        case '/':{ //{}required if we initialize variables within a switch statement
            double d = primary();
            if (d == 0){
                cout << "Error: divison by zero \n";
                return -1;
            }
            left /= d;
            t = get_token();
            break;
        }
        /*case '%': //not defined for floating-point values
            left %= primary(); 
            t = get_token();
            break;*/
        default:
            return left;
        }
    }
double primary()       // deal with numbers and parentheses;           
{
    Token t = get_token();
    switch (t.kind){
        case '(':
        //handle '(' expression ')'
        {
            double d = expression();
            t = get_token();
            if(t.kind != ')'){
                cout << "Error: ')' expected \n";
            }
            return d;
        }
        case '8': 
        //we use '8' to represent a number
            return t.value;
        default:
            cout << "Error: primary expected\n";
    }
}

vector<Token>tok;            // we’ll put the tokens here
int main()
{
         // ...
         while (cin) {
                 Token t = get_token(); //TODO: implement get_token
                 tok.push_back(t);
         }
         // ...
}

//try this: storing the tokens in a vector, ranking them by their priority of operator -> check adjacent objects to calculate
//input, terminated by type changing (char/double)
//variables will double the size of the project