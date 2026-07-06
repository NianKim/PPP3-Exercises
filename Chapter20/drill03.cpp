#include <map>
#include <string>
#include <iostream>

//[5] Write a function that reads value pairs from cin and places them in msi.

void read_pairs(std::map<std::string, int>& m) {
    std::string key;
    int value;
    
    std::cout << "Enter key-value pairs (e.g., 'quiz 5'). Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to stop:\n";
    
    while (std::cin >> key >> value) {
        m[key] = value;
    }
}

int main() {
    std::map<std::string, int> msi;
    //step 2:
    msi["lecture"] = 21;
    msi["seminar"] = 14;
    msi["project"] = 8;
    msi["exam"] = 5;
    msi["lab"] = 12;
    msi["workshop"] = 3;
    msi["tutorial"] = 18;
    msi["course"] = 22;
    msi["homework"] = 10;
    msi["research"] = 7;

    std::cout << "--- Content of msi (sorted alphabetically) ---\n";
    for (const auto& [name, value] : msi) {
        std::cout << name << " -> " << value << "\n";
    }

    msi.clear();

    read_pairs(msi);

    std::cout << "\n--- New Content of msi ---\n";
    for (const auto& [name, value] : msi) {
        std::cout << name << " -> " << value << "\n";
    }

    int sum = 0;
    for (const auto& [name, value] : msi) {
        sum += value;
    }
    std::cout << "The sum of all values: " << sum << '\n';

    std::map<int,std::string> mis;
    //[10] Enter the values from msi into mis; that is, if 
    //msi has an element ("lecture",21), mis should have an element (21,"lecture").
    for (const auto& [name, value] : msi) {
        mis[value] = name;
    }

    std::cout << "--- Content of mis (sorted alphabetically) ---\n";
    for (const auto& [name, value] : mis) {
        std::cout << name << " -> " << value << "\n";
    }

    return 0;
}