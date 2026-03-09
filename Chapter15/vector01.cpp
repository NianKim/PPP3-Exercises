class Vector {  // a very simplyfied vector
    int sz;     //size
    double* elem;   //pointer to the first element
public:
    Vector(int s);  //constructor : allocate s doubles

    int size() const { return sz; } //current size
} ;