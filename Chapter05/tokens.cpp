#include<iostream>
//a very simple user-defined type (pair)
class Token {
    public:
    char kind;
    double value;
};

int main(){
    Token t;
    t.kind = '+'; //t represents a +
    Token t2;
    t2.kind = '8'; //digit '8' as the kind for numbers
    t2.value = 3.14;
}