#include <map>
#include <string>
#include <iostream>

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
    return 0;
}