#include<iostream>
#include<algorithm>

/*
Write a class Ptr that has as a double* 
private member called p. Give Ptr the 
essential operations as described in §17.5. 
A constructor should take a double argument, 
allocate a double on the free store, assign the pointer 
to it to p, and copy the argument into *p. $
Give Ptr an operator * that allows you to read and write *p. 
Test Ptr.
*/

class Ptr {
    public:
    // constructor
    explicit Ptr( double arg ) 
    {
        p = new double (arg);
    }

    // destructor
    ~Ptr() 
    {
        delete p;
    }

    //move 
    Ptr(Ptr&& target) //noexcept?
    {
        p = target.p;
        target.p = nullptr;
    }

    //copy constructor (deep)
    Ptr(const Ptr& target)
    {
        p = new double(*target.p);
    }

    //move assignment
    Ptr& operator=(Ptr&& target) 
    {
        if(this != &target)
        {
            delete p;
            p = target.p;
            target.p = nullptr;
        }
        return *this;
    }

    // * operator: read 
    double& operator*()
    {
        return *p;
    }

    // * opetator : write
    double operator*() const
    {
        return *p;
    }


    private:
    double* p;
};

int main() {
    Ptr p1(5.5);
    std::cout << "Original: " << *p1 << std::endl;

    *p1 = 10.2; // Schreiben über operator*
    std::cout << "Changed: " << *p1 << std::endl;

    Ptr p2 = p1; // Kopier-Konstruktor
    std::cout << "Copy: " << *p2 << std::endl;

    return 0;
}