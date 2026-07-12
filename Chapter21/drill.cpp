//[1] Read some floating-point values (at least 16 values) from a file 
//into a vector<double> called vd.

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <numeric>
#include <algorithm>

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

    //[3] Make a vector vi of type vector<int> with the same number 
    //of elements as vd; copy the elements from vd into vi.
    vector<int> vi(vd.begin(), vd.end());


    // [4] Output (vd[i],vi[i]) to cout
    cout << "\n--- Vector Contents ---\n";
    for (int i = 0; i < 16; ++i) {
        cout << '(' << vd[i] << ", " << vi[i] << ')' << '\n';
    }

    //[5] Output the sum of the elements of vd.
    double vd_total = std::accumulate(vd.begin(), vd.end(), 0.0);
        std::cout << "Total sum: " << vd_total << '\n';

    //[6] Output the difference between the sum of the elements of vd and the sum of the elements of vi.
    int vi_total = std::accumulate(vi.begin(), vi.end(), 0); 
        std::cout << "Difference in sums: " << vi_total - vd_total << '\n';

    //[7] There is a standard-library algorithm called reverse that takes a sequence (pair of iterators) as arguments; reverse vd, and output vd to cout.
    reverse(vd.begin(), vd.end());
    cout << "\n--- Reversed vd ---\n";
    for (double d : vd) cout << d << ' ';
    cout << '\n';

    // [8] Compute the mean value of the elements in vd; output it.
    double mean = vd_total / vd.size();
    cout << "\nMean value of vd: " << mean << '\n';

    // [9] Make a new vector<double> called vd2 and copy all elements of vd 
    // with values lower than (less than) the mean into vd2.
    vector<double> vd2;
    std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), [mean](double x) {
        return x < mean;
    });

    cout << "\n--- Elements in vd2 (less than mean) ---\n";
    for (double d : vd2) cout << d << ' ';
    cout << '\n';
}