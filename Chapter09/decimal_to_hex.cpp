
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