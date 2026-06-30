#include<map>
#include<string>
#include<iostream>

//up to date according to slickcharts.com 29. Jun, 2026

std::unordered_map<std::string,double> dow_price = {  // Dow Jones Industrial index (symbol,price);
                                                
        {"MMM",164.01},
        {"AAPL",283.78},
        {"MSFT",372.97},
        {"KO", 82.63}
        // ...
};
std::unordered_map<std::string,double> dow_weight = {          // Dow (symbol,weight)
        {"MMM", 1.95},
        {"AAPL",3.37},
        {"MSFT",4.43},
        {"KO", 0.98}
};
std::unordered_map<std::string,std::string> dow_name = {   // Dow (symbol,name)
       {"MMM","3M Co"},
       {"AAPL","Apple"},
       {"MSFT","Microsoft"},
       {"KO", "Coca-Cola Co"}
};


int main() {

    std::cout << "Some select companies in the Dow Jones index, prices based on 29th of June 2026. \n";
    for (const auto& [symbol,price] : dow_price)
        std::cout << symbol << '\t' << price << '\t' << dow_name[symbol] << '\n';
}