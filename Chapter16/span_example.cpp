#include <iostream>
#include <span>
#include <vector>

using namespace std;


void print_n (span <int> s) //a span points to an array and "remembers" its number of elements
{
    for (int x :s)
        cout << x << ' ';
    cout << endl;
}

void user()
{
    int a[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<int> v(10, 1);  // Initialized with 10 ones

    print_n(a); //prints 12 ints
    print_n(v); //prints 10 ints
}

int main()
{
    user();
    return 0;
}