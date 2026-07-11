#include <iostream>
#include <vector>

template<typename R1, typename R2, typename T>
T inner_product(const R1& r1, const R2& r2, T init) {
    auto first1 = std::begin(r1);
    auto last1 = std::end(r1);
    auto first2 = std::begin(r2);
    auto last2 = std::end(r2);

    // Loop stops safely if EITHER range runs out of elements
    while (first1 != last1 && first2 != last2) {
        init = init + (*first1) * (*first2);
        ++first1;
        ++first2;
    }
    return init;
}

int main() {
    // Example data: Share prices of 3 companies
    std::vector<double> dow_price = { 150.0, 42.5, 89.1 };
    
    // Example data: Corresponding weights for the index calculation
    std::vector<double> dow_weight = { 0.5, 0.2, 0.3 };

    double dji_index = inner_product(dow_price, dow_weight, 0.0);

    std::cout << "DJI value " << dji_index << '\n'; 

    return 0;
}