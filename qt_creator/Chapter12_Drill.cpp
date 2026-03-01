#include<iostream>

using namespace std;

struct B1 {
public:
    virtual void vf() const { cout << "B1::vf "; }
    void f() const { cout << "B1::f "; }             // not virtual
};

struct D1 : B1 {
    void vf() const { cout << "D1::vf "; }           // overrides B1::vf
    //void f() const { cout << "D1::f "; }
};

int main()
{
    B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1& b1_ref = d1;
    b1_ref.vf();        //polymorphism
    b1_ref.f();         //not virtual in base class
}
