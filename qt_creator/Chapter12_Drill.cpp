#include<iostream>

using namespace std;

struct B1 {

    virtual void vf() const { cout << "B1::vf "; }
    void f() const { cout << "B1::f "; }             // not virtual
};

struct D1 : B1 {
    void vf() const { cout << "D1::vf "; }           // overrides B1::vf
    //void f() const { cout << "D1::f "; }
};

int main()
{
    B1 B1;
    B1.vf();
    B1.f();

    D1 D1;
    D1.vf();
    D1.f();
}
