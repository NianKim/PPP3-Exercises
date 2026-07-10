//Define a vector<Record>, initialize it with four records 
//of your choice, and compute their total price using the functions above

#include<numeric>
#include<vector>
#include<iostream>


struct Record {
        double unit_price;
        int units;           // number of units sold
        // ...
};

double price(double v, const Record& r)
{
        return v + r.unit_price * r.units;                // calculate price and accumulate
}

void f(const std::vector<Record>& vr)
{
        double total = std::accumulate(vr.begin(), vr.end(), 0.0, price);
        std::cout << total << '\n';
}

int main() {
    std::vector<Record> records;
    Record rec1 = {243.4554, 43};
    Record rec2 = {666.6, 934};
    Record rec3 = {4382.444, 1};
    Record rec4 = {3.333, 28493};

    records.push_back(rec1);
    records.push_back(rec2);
    records.push_back(rec3); 
    records.push_back(rec4);

    //computing total price:
    f(records);

}