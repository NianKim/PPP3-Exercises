#include<iostream>

int main(){
    constexpr double chf_per_usd = 0.80;             // prices of 10.01.2026
    constexpr double yen_per_usd = 157.89;
    constexpr double krone_per_usd = 10.10;
    double amount = 1;                                               // length in inches or centimeters
    char unit = ' ';
    std::cout<< "Please enter a amount followed by a currency (k = krone, c = chf or y = yen):\n";
    std::cin >> amount >> unit;
    switch (unit){
        case 'c': //chf
            std::cout << amount << "usd == " << amount * chf_per_usd << "chf\n";
            break;

        case 'k': // krone
            std::cout << amount << "usd == " << amount *krone_per_usd << "k\n";
            break;
        
        case 'y': //yen
            std::cout << amount << "usd == " << amount * yen_per_usd << "yen\n";
            break;
        
        default:
            std::cout << "Sorry, I don't know a currency called '" << unit << "'\n";
            break;
    }
}