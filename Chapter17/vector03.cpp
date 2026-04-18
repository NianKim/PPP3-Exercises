#include <initializer_list> 
#include <iostream>
#include <algorithm>        //std::copy

class Vector {                  //very simplified vector of doubles
public:
    Vector(int s) :sz{s}, elem{new double[s]}  //constructor: assigns memory (s is element count)
    {
        for ( int i = 0; i < sz; ++i)
            elem[i] = 0.0;
    }     
    Vector(std::initializer_list<double> lst)
        : sz{static_cast<int>(lst.size())},
          elem{new double[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }
    ~Vector() { delete[] elem; } //destructor, return elements to the free store
    int size() const { return sz; }
    //double get(int n) const {return elem[n];}
    //void set(int n, double v) {elem[n]=v;}
    double& operator[](int n) { return elem[n]; } // return a reference
    const double& operator[] (int n) const { return elem[n]; }  //return a const& for a const
private:
    int sz;                     //size
    double* elem;               //pointer to elements
};


#include<iostream>

int main(){

    Vector v2(3);                  // three elements each with the (default) value 0.0
    for (int i=0; i<v2.size(); ++i) {
        //v2[i] = i;             // returns a reference
        std::cout << v2[i];
    }
}