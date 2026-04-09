#include<iostream>
#include<span>

using namespace std;

//std::span is not guaranteed to range check.
void test (span<int> s)
{
    cout << "size: " << s.size() << '\n';
    for (int x : s)
        cout << x << '\n';
    try {
        int y = s[size()];
    }
    catch (...){
        cout << "we have range checking \n";
        return;
    }
    cout << "ERROR: no range checking! ";
    terminate();        //exit the program
}