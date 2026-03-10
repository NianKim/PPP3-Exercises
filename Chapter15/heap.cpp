#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 5;
    
    int* pi = new int;                      // allocate one int
    int* qi = new int[4];                  // allocate 4 ints (an array of 4 ints)

    double* pd = new double;              // allocate one double
    double* qd = new double[n];          // allocate n doubles (an array of n doubles)

    double* p = new double[4];             // allocate 4 doubles on the free store. pointer q points to an array
    double x = *p;                               // read the (first) object pointed to by p
    double y = p[0];                             // read the 1st object pointed to by p
    double z = p[2];                             // read the 3rd object pointed to by p

    cout << "A small heap test: \n";
    cout << "*p: " << x << '\n'; // is the same as p[0]
    cout << "p[0]: " << y << '\n';
    cout << "p[2]: " << z << '\n';  

    //accessing a class member through a pointer
    vector<int>* vecp = new vector<int>{7,8,9};
    cout << vecp->size(); //access using ->
    cout << (*vecp).size();  //access using .
}
