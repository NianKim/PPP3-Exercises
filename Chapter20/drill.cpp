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

// Sort by Name (Alphabetical)
bool sortByName(const Item& a, const Item& b) {
    return a.name < b.name;
}

// Sort by ID (Numerical ascending)
bool sortById(const Item& a, const Item& b) {
    return a.iid < b.iid;
}

// Sort by Value (Price ascending)
bool sortByValueAscend(const Item& a, const Item& b) {
    return a.value < b.value;
}
bool sortByValueDescend(const Item& a, const Item& b) {
    return a.value > b.value;
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

    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    for (auto it = vi.begin(); it != vi.end(); ) {
        if (it->name == "Cat" || it->name == "Shoes") {
            it = vi.erase(it); // erase() removes the element and moves 'it' to the next one
        } else {
            ++it; // Only move forward manually if we DIDN'T erase anything
        }
    }


    // Sort the vector using the operator< we defined above
    sort(vi.begin(), vi.end(), sortByValueDescend); 

    // Copy sorted items back out to the target file
    copy(vi.begin(), vi.end(), oo);

    return 0;
}