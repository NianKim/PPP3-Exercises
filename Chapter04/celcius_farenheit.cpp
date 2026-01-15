#include<iostream>

using namespace std;

double ctok(double c)                   // converts Celsius to Kelvin
{
        double K = c + 273.25;
        return K;
}

int main()
{
         double c = 0;                  // declare input variable
         cin >> c;                      // retrieve temperature to input variable
         double K = ctok(c);            // convert temperature
         cout << K << '\n' ;            // print out temperature
}