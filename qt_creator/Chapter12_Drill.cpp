#include<iostream>

using namespace std;

struct B1 {
public:
    virtual void vf() const { cout << "B1::vf "; }
    void f() const { cout << "B1::f "; }             // not virtual
    virtual void pvf() const =0;                     // pure virtual function
};

struct D1 : B1 {                                    //inherits pvf()
    void vf() const { cout << "D1::vf "; }           // overrides B1::vf
    void f() const { cout << "D1::f "; }
};

struct D2 : D1{
    void pvf() const override { cout << "D2::pvf "; }
};

struct B2 {
    virtual void pvf() const =0;
};

int main()
{
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    B1& b1_ref = d2;
    b1_ref.vf();        //polymorphism
    b1_ref.f();         //not virtual in base class
}
