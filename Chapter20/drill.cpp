#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

struct Item {
    string name;
    int iid;
    double value;
    /*...*/
};

istream& operator>>(istream& is, Item& item) {
    // Assumes file format looks like: Apple 101 1.99
    is >> item.name >> item.iid >> item.value;
    return is;
}

ostream& operator<<(ostream& os, const Item& item) {
    os << item.name << " " << item.iid << " " << item.value;
    return os;
}

bool operator<(const Item& a, const Item& b) {
    return a.name < b.name; // Sorting alphabetically by name, for example
}

int main() {
    string from, to;
    cout << "Enter source and target file names: ";
    cin >> from >> to;
    ifstream is {from};                                     // open input stream
    ofstream os {to};                                       // open output stream

    istream_iterator<Item> ii {is};                 // make input iterator for stream
    istream_iterator<Item> eos;                   // input sentinel
    ostream_iterator<Item> oo {os,"\n"};     // make output iterator for stream

    vector<Item> vi;
    for (int i = 0; i < 10 && ii != eos; ++i) {
        vi.push_back(*ii);
        ++ii;
    }

    // Sort the vector using the operator< we defined above
    sort(vi.begin(), vi.end()); 

    // Copy sorted items back out to the target file
    copy(vi.begin(), vi.end(), oo);

    return 0;
}