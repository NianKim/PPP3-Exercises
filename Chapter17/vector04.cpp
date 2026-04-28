#include <initializer_list> 
#include <iostream>
#include <algorithm>        //std::copy

class Vector {                  //very simplified vector of doubles
public:

    Vector() : sz{0}, elem{nullptr}, space{0} {}  //default constructor

    explicit Vector(int s) :sz{s}, elem{new double[s]}, space{s}  //constructor: assigns memory (s is element count)
    {
        for ( int i = 0; i < sz; ++i)
            elem[i] = 0.0;
    }     
    Vector(std::initializer_list<double> lst) //pass by value
        : sz{static_cast<int>(lst.size())},
          elem{new double[sz]},
          space{sz}
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

    Vector& operator=(const Vector&);//assingment

    Vector(Vector&& arg);              //move constructor
    Vector& operator=(Vector&& arg); //move assignment

        
    //iteration support
    double* begin() const { return elem; }
    double* end() const { return elem+sz; }

    //comparator
    friend bool operator==(const Vector& v1, const Vector& v2);

    //reserve(): add space for new elements
    void reserve(int newalloc);

    //capacity: nr of elements

    int capacity() const { return space; }

    void resize( int newsize );

    void push_back( double d );
    
private:
    int sz;                     //size
    double* elem;               //pointer to elements
    int space;
};

    Vector::Vector(const Vector& arg)            
    :sz{arg.sz}, elem{new double[arg.sz]}, space{arg.sz}
    {
        std::copy(arg.elem,arg.elem+sz,elem);  // copy elements [0:sz) from elem.arg into elem
    }

    Vector& Vector::operator=(const Vector& a){  //like copy constructor, but we must deal with old elem

        if ( this == &a )
            return *this;
        if ( a.sz <= space ){
            for ( int i = 0; i < a.sz; ++i )
                elem[i] = a.elem[i];
            sz = a.sz;
            return *this;
        }

        double* p = new double[a.sz];           //allocate new space
        for (int i = 0; i < a.sz; ++i)
            p[i] = a.elem[i];
        
        delete[] elem;                          //deallocate old space

        space = sz = a.sz;                      //set new size
        elem = p;                               //now we can reset elem
        return *this;                           //return a self-reference
    }

    Vector::Vector(Vector&& arg)                //move constructor
        :sz{arg.sz}, elem{arg.elem}, space{arg.space}//copy arg's elem and sz
    {
        arg.sz = 0;                             //make arg the empty vector
        arg.elem = nullptr;
    }

    Vector& Vector::operator=(Vector&& arg)     //move arg to this Vector 
    {
        if ( this != &arg)                      // protect against self-assignment
        {
            delete[] elem;                      // deallocate old space
            elem = arg.elem;                    // copy arg's elem and sz  
            sz = arg.sz;                        
            arg.elem = nullptr;                 // make arg the empty vector
            arg.sz = 0;
        } 
        return *this;                           //return a self-reference
    }

    //comparators:
    bool operator==(const Vector& v1, const Vector& v2){
    if (v1.size()!=v2.size())
            return false;
    for (int i = 0; i<v1.size(); ++i)
            if (v1[i]!=v2[i])
                    return false;
    return true;

    //alternatively thanks to friend we could write:
    //return std::equal(v1.elem, v1.elem + v1.sz, v2.elem);
}

void Vector::reserve(int newalloc)
{
        if (newalloc<=space)                                // never decrease allocation
                return;
        double* p = new double[newalloc];         // allocate new space
        for (int i=0; i<sz; ++i)                                // copy old elements
                p[i] = elem[i];
        delete[] elem;                                          // deallocate old space
        elem = p;
        space = newalloc;
}

void Vector::resize(int newsize) 
    // make the vector have newsize elements
    //initialize each new element with the default value 0.0
{
    if (newsize < 0) throw std::runtime_error("Negative resize"); //avoid huge memory usage (underflow)
    reserve(newsize);
    for ( int i = sz; i < newsize; ++i )
        elem[i] = 0;
    sz = newsize;
}

void Vector::push_back(double d)
    //increase the size by one, initialize new variable with d
{
    if (space == 0)
        reserve(8);     //start with size 8
    else if( sz == space )
        reserve(space*2);
    
    elem[sz] = d;
    ++sz;
}

int main(){
    Vector v1 = {0,1,2};            //curly braces: element list 
    Vector v2(3);                  // three elements each with the (default) value 0.0
    Vector v3 = v1;
    for (int i=0; i<v2.size(); ++i) {
        v2[i] = i;             // returns a reference
        std::cout << v2[i];
    }

    v3.resize(6);
    //v2.resize(-99);

    v1[1] = 99;                             
    v2[0] = 88;                               
    std::cout << "\nv2[0]: " << v2[0] << ", v1[1]: " << v1[1] << "\n";
    //v3 = v3;
    v3.push_back(67.89);
    for(int i = 0; i < v3.size(); ++i){
        std::cout << "v3[" << i << "]: " << v3[i] << '\n';
    }
}