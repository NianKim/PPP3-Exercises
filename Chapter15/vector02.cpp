class Vector {                  //very simplyfied vector of doubles
public:
    Vector(int s);              //constructor
    Vector() { delete[] elem; } //destructor, return elements to the free store
    int size() const { return sz; }
    double get(int n) const {return elem[n];}
    void set(int n, double v) {elem[n]=v;}
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
    Vector v(5);
for (int i=0; i<v.size(); ++i) {
        v.set(i,1.1*i);
        std::cout << "v[" << i << "]==" << v.get(i) << '\n';
}
}