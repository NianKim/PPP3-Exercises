#include<iostream>
#include<format>
using namespace std;

int main(){
    constexpr double d = 1234.56789;
    //a hexfloat, e scientific, f fixed, g general with precision 6
    cout << format("format: {} − {:a} − {:e} − {:f} − {:g}\n", d, d, d, d, d);

    //will print d at width 12, then in fixed point precision 8, width 12, then 30 width (20e precision)
    cout << format("− {:12} − {:12.8f} − {:30.20e} −\n", d, d, d);
}