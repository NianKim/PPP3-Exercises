#include <list>   // Added for std::list
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
};

istream& operator>>(istream& is, Item& item) {
    is >> item.name >> item.iid >> item.value;
    return is;
}

ostream& operator<<(ostream& os, const Item& item) {
    os << item.name << " " << item.iid << " " << item.value;
    return os;
}

bool sortByName(const Item& a, const Item& b) {
    return a.name < b.name;
}

bool sortById(const Item& a, const Item& b) {
    return a.iid < b.iid;
}

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
    ifstream is {from};                                     
    ofstream os {to};                                       

    istream_iterator<Item> ii {is};                 
    istream_iterator<Item> eos;                    
    ostream_iterator<Item> oo {os,"\n"};     

    // 1. Change the container type from vector to list
    list<Item> vi; 
    for (int i = 0; i < 10 && ii != eos; ++i) {
        vi.push_back(*ii);
        ++ii;
    }

    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    // list::erase() also returns a valid iterator to the next node.
    for (auto it = vi.begin(); it != vi.end(); ) {
        if (it->name == "Cat" || it->name == "Shoes") {
            it = vi.erase(it); 
        } else {
            ++it; 
        }
    }

    for (auto it = vi.begin(); it != vi.end(); ) {
        if (it->iid == 108 || it->iid == 106) {
            it = vi.erase(it); 
        } else {
            ++it; 
        }
    } 

    //Use the member sort function instead of std::sort
    vi.sort(sortByValueDescend); 

    std::copy(vi.begin(), vi.end(), oo);

    return 0;
}