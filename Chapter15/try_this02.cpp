/*
    Write a little program using base classes 
    and members where you define the constructors 
    and destructors to output a line of information 
    when they are called. Then, create a few objects 
    and see how their constructors and destructors 
    are called.
*/

#include<iostream>

class base {
    public:
    base(){
        std::cout << "Default constructor base is called. \n";
    };
    virtual ~base(){ //entry in the v-table (one per class)
        std::cout << "Default destructor base is called. \n";
    }
};

class derived : public base {
    public:
    derived(){
        std::cout << "Default constructor derived is called. \n";
    }
    ~derived(){ 
        std::cout << "derived destructor base is called. \n"; 
    }

    //compiler silently generates an empty destructor
};

int main() {
    base b;
    derived d; //line 2 and 3 are constructed (base first, then the next layer)
}