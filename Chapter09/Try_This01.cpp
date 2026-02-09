#include<iostream>
#include<vector>
#include<stdexcept>
#include<fstream>

using namespace std;

void error(string s1, string s2 = ""){
    throw runtime_error{s1+s2};
}

const int birthyear = 2005;
const int current_year = 2026;

//output birth year in different forms and formatted
int main(){
    cout << birthyear << " - " << hex << setw(4) << birthyear << " - " << oct << birthyear << '\n';
    cout << "You will be: " << dec << (current_year - birthyear) << " years old in " << (current_year) << '\n';
}