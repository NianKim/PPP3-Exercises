//[1] Read some floating-point values (at least 16 values) from a file 
//into a vector<double> called vd.

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

int main() {

    string from, to;
    cout << "Enter source and target file names: ";
    cin >> from >> to;
    ifstream is {from};                                     // open input stream
    ofstream os {to};                                       // open output stream

    if (!is) {
        cerr << "Error: Could not open input file " << from << '\n';
        return 1;
    }

    istream_iterator<double> ii {is};                 // make input iterator for stream
    istream_iterator<double> eos;                   // input sentinel

    vector<double> vd(ii, eos);

    // [2] Output vd to cout
    cout << "\n--- Vector Contents ---\n";
    for (double d : vd) {
        cout << d << '\n';
    }
}