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
    Vector(std::initializer_list<double> lst) //pass by value
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

    Vector (const Vector&);          //copy constructor: define copy
    Vector& operator=(const Vector&);
private:
    int sz;                     //size
    double* elem;               //pointer to elements
};

    Vector::Vector(const Vector& arg)            // allocate elements, then initialize them by copying
        :sz{arg.sz}, elem{new double[arg.sz]}
    {
        std::copy(arg.elem,arg.elem+sz,elem);  // copy elements [0:sz) from elem.arg into elem
    }

    Vector& Vector::operator=(const Vector& a)  //make assigned Vector a copy of a
    {
        double* p = new double[a.sz];           //allocate new space
        std::copy(a.elem,a.elem+a.sz,p);        //copy element [0:sz) from a.elem into p
        delete[] elem;                          //deallocate old space
        elem = p;                               //now we can reset elem
        sz = a.sz;
        return *this;                           //return a self-reference
    }

#include<iostream>

int main(){
    Vector v1 = {0,1,2};            //curly braces: element list 
    /* equivalent to : 
    Vector v1 {0,1,2};
    */
    Vector v2(3);                  // three elements each with the (default) value 0.0
    Vector v3 = v1;
    for (int i=0; i<v2.size(); ++i) {
        v2[i] = i;             // returns a reference
        std::cout << v2[i];
    }

    v1[1] = 99;                             
    v2[0] = 88;                               
    std::cout << "\nv2[0]: " << v2[0] << ", v1[1]: " << v1[1] << "\n";
    v3 = v3;
    for(int i = 0; i < v3.size(); ++i){
        std::cout << "v3[" << i << "]: " << v3[i] << '\n';
    }
}