#include<iostream>
using namespace std;

class Token{
public:
         char kind;                                                            // what kind of token
         double value;                                                      // for numbers: a value
         //Token(char k) :kind{k}, value{0.0}{}                  // construct from one value
        //Token(char k, double v) :kind{k}, value{v}{}    // construct from two values
};

Token get_token();            // function to read a token from cin

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