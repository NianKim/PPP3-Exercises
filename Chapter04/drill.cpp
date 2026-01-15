#include <iostream>   // For cin, cout, cerr
#include <vector>     // For vector
#include <string>     // For string
#include <cmath>      // For math functions like sqrt()
#include <stdexcept>  // For exception, runtime_error, out_of_range
#include <algorithm>  // For sort()

using namespace std;

int main()
try{
        cout << "Success!\n";
        return 0;
}
catch (exception& e){
         cerr << "error: " << e.what() << '\n';
         return 1;
}
catch (...) {
         cerr << "Oops: unknown exception!\n";
         return 2;
}