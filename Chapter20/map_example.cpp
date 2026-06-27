#include<map>
#include<string>
#include<utility>
#include<iostream>

int main() {
    std::cout << "Write any words you like! To see what you wrote how many times, hit Ctrl + Z for Windows and Ctrl + D on Unix. \n";
    std::map<std::string, int> words;
    for (std::string s; std::cin >> s; ) 
        ++words[s];
    for (const std::pair<const std::string, int>& p : words)
        std::cout << p.first << ": " << p.second << '\n';
}