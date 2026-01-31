
// dangerously ugly code: what suspicious bugs can you find?
#include<iostream>
using namespace std;

struct X {
    void f(int x) {
        struct Y {
            int f() { 
                return 1; 
            } 
            int m; //useless declaration
        };
        int m = x; 
        Y m2; //can't construct
        return f(m2.f()); 
    }
    int m; //equally useless m
    void g(int m) {
        if (0<m) f(m+2);
        else {
            g(m+2.3);
        }
    }
    X() { } int m3() { //?
    }
};

void main() {
    X a;    //X not constructing
    a.f(2);
}
//}; historicalfalling through the bottom of main() is equivalent to returning the value 0