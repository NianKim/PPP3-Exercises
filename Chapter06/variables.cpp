
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/
//utilities
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

constexpr char number = '8';    // t.kind==number means that t is a number Token
constexpr char quit = 'q';      // t.kind==quit means that t is a quit Token
constexpr char prin = ';';     // t.kind==print means that t is a print Token
constexpr string prompt = "> ";
constexpr string result = "= "; // used to indicate that what follows is a result

// eg. error("putback() into a full buffer");
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

// eg. keep_window_open("~1")
inline void keep_window_open(string s)
{
	if (s=="") return;
	cin.clear();
	cin.ignore(120,'\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss!=s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}


//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token() :kind{0} {}
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n ) :kind{ch}, name{n} {}
};
//------------------------------------------------------------------------------
class Variable{
    public: 
        string name;
        double value;
};

//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s){
    //return the value of the Variable named s
    for (const Variable& v : var_table){ //v is a reference to Variable in the var_table, rather than a copy
        if (v.name == s){
            return v.value;
        }
    }
    error("trying to read undefined variable");
}
//------------------------------------------------------------------------------
void set_value(string s, double d){
    //set the Variable named s to d
    for (Variable& v : var_table){
        if(v.name ==s){
            v.value = d;
            return;
        }
    }
    error("trying to write undefined variable ");
}

//------------------------------------------------------------------------------

class Token_stream {
public:
    //Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);       //discards characters up to and including a c
private:
    bool full = false;        // is there a Token in the buffer?
    Token buffer = 0;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c){
    //c represents the kind of Token
    if(full && c ==buffer.kind){
        full = false;
        return;
    }
    full = false;

    //now search input:
    char ch = 0;
    while (cin >> ch){
        if(ch ==c){
            return;
        }
    }
}

//------------------------------------------------------------------------------
const char name = 'a';
const char let = 'L';
const string declkey = "let";

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case prin: 
    case quit: 
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '%':
    case '=':
        return Token(ch);        // let each character represent itself
    case '.':                       //floating point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4': //numeric literal
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    default:
        if(isalpha(ch)){ //is ch a letter)
            string s;
            s+= ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch))){
                s+=ch;
            }
            cin.putback(ch);
            if (s == declkey){
                return Token{let};
            }
            return Token{name,s};
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case number:    
        return t.value;  // return the number's value
    case '-':
        return - primary();
    case '+':
        return + primary();
    case '=':
        return get_value(t.name);
    case name: 
        return get_value(t.name);
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d==0){error("%:divide by zero");}
            left = fmod(left, d);
            t = ts.get();
            break;  
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}
//------------------------------------------------------------------------------

double define_name(string var, double val); //promise

//------------------------------------------------------------------------------
double declaration(){
    /*
    assume we have seen "let"
    handle: name = expression
    declare a variable called "name" with the initial value "expression"*/
    Token t = ts.get();
    if(t.kind != name){
        error("name expected in declaration");
    }
    Token t2 = ts.get();
    if(t2.kind != '='){
        error("=missing in declaration of variable");
    }
    double d = expression();
    define_name(t.name,d);
    return d;
}
//------------------------------------------------------------------------------
double statement(){
    Token t = ts.get();
    switch(t.kind){
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

//------------------------------------------------------------------------------

//This Function purges all tokens from current calculation of Token_Stream
void clean_up_mess(){
    ts.ignore(prin);
}
void calculate(){
    while (cin) {
        try{
            cout << prompt;
            Token t = ts.get();
            while (t.kind == prin){
                t = ts.get();
            }
            if (t.kind == quit) {return;} // 'x' for quit
                ts.putback(t);
                cout << result << statement() << '\n';
        }
        catch(exception& e){
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
    return;
}

//------------------------------------------------------------------------------
bool is_declared(string var){
    //is this already in var_table?
    for (const Variable& v : var_table){
        if(v.name == var){
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
double define_name(string var, double val){
    //add {var,val} to var_table
    if(is_declared(var)){
        error("Variable declared twice");
    }
    var_table.push_back(Variable{var,val});
    return val;
}


//------------------------------------------------------------------------------


int main(){
    cout << "Welcome to our simple calculator. \n Please enter expressions using floating−point numbers.\n";
    cout << "You can use Brackets, Operators +-*/%, ; to get an output and q to terminate the program.\n";
    cout << "Variables can be declared using let name = value; \n";
    try{
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}
//------------------------------------------------------------------------------