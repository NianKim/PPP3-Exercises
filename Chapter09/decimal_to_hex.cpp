
#include<iostream>
#include<fstream>
#include<stdexcept>

using namespace std;

void error(string s){
    throw runtime_error{s};
}

void skip_to_int(){
    if(cin.fail()){
        cin.clear();
        for(char ch; cin >> ch; ){
            if(isdigit(ch) || ch == '-'){
                cin.unget();
                return;
            }
        }
    }
    error("no input");
}

int get_int() //make sure to catch exceptions here!
{
         int n = 0;
         while (true) {
                  if (cin >> n)
                           return n;
                  cout << "Sorry, that was not a number; please try again\n";
                  skip_to_int();
         }
}


int get_int_range(int low, int high)
{
        cout << "Please enter an integer in the range " << low << "to " << high << " (inclusive):\n";
        while (true) {
            int n = get_int();                                    // we got an integer; now check it
            if (low<=n && n<=high)
                        return n;
                cout << "Sorry " << n << " is not in the [" << low << ":" << high << "] range; please try again\n";
            }
}

int get_int_range_greeting(int low, int high, const string& greeting, const string& sorry)
{
        cout << greeting << ":[" << low << ":" << high << "]\n";
        while (true) {
            int n = get_int();                                    // we got an integer; now check it
            if (low<=n && n<=high)
                        return n;
                cout << sorry << ": [" << low << ":" << high << "]\n";
            }
}

void end_of_loop(istream& ist, char term, const string& message)
{
         if (ist.fail()) {                                // use term as terminator and/or separator
                  ist.clear();
                  char ch = 0;
                  if (ist>>ch && ch==term)
                           return;                       // all is fine
                  error(message);
         }
}