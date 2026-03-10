class Vector {                  //very simplyfied vector of doubles
public:
    Vector(int s);              //constructor
    Vector() { delete[] elem; } //destructor
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

Vector::Vector()                //destructor
{
    delete[] elem;              //return elements to free store
}