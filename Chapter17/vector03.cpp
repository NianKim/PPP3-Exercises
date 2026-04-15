class Vector {                  //very simplyfied vector of doubles
public:
    Vector(int s);              //constructor
    Vector() { delete[] elem; } //destructor, return elements to the free store
    int size() const { return sz; }
    double get(int n) const {return elem[n];}
    void set(int n, double v) {elem[n]=v;}
    double& operator[](int n) { return elem[n]; } // return a reference
    const double& operator[] (int n) const { return elem[n]; }  //return a const& for a const
private:
    int sz;                     //size
    double* elem;               //pointer to elements
};
Vector::Vector(int s)           //constructor
    :sz{s},
    elem{new double[s]}         //initialize to elements on the free store
{
    for (int i=0; i<s; ++i)     //initialize elements
        elem[i] = 0;
}

#include<iostream>

int main(){

    Vector v(10);
    for (int i=0; i<v.size(); ++i) {
        v[i] = i;             // returns a reference
        std::cout << v[i];
    }
}