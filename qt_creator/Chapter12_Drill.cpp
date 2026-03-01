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
public:
    virtual void pvf() const =0;
};

struct D21 : B2{
    string data_member = "some string ";
    virtual void pvf() const override { cout << data_member; }
};

struct D22 : B2{
    int some_int = 782434;
    virtual void pvf() const override { cout << some_int; }
};

void f(B2& arg){
    arg.pvf();
}

int main()
{
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    B1& b1_ref = d2;
    b1_ref.vf();        //polymorphism
    b1_ref.f();         //not virtual in base class

    D21 d21;
    D22 d22;
    f(d21);     //f can handle both, behaves differently depending on the actual argument type.
    f(d22);
}
