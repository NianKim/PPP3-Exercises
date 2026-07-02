#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <random>
#include <ranges>
#include <chrono>
#include <algorithm>
#include <map>

// Helper to handle random number generation cleanly, from PPP3 header
std::mt19937& get_rng() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}

// Replaces PPP's random_int(max)
int random_int(int max) {
    std::uniform_int_distribution<int> dist(0, max);
    return dist(get_rng());
}

// Replaces PPP's random_letters(min, max)
std::string random_letters(int min_len, int max_len) {
    // Determine a random length between min_len and max_len
    std::uniform_int_distribution<int> len_dist(min_len, max_len);
    int length = len_dist(get_rng());

    // Character pool to pull letters from
    const std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> char_dist(0, letters.size() - 1);

    std::string result;
    result.reserve(length); // Optimize memory allocation
    for (int i = 0; i < length; ++i) {
        result += letters[char_dist(get_rng())];
    }
    return result;
}


std::vector<std::pair<std::string, int>> generate(int n) {
    std::vector<std::pair<std::string, int>> res;
    for (int i = 0; i < n; ++i) {
        res.push_back({random_letters(4, 24), random_int(1'000'000)});
    }
    return res;
}


int main() {
    std::vector<std::pair<std::string,int>> v = generate(1000000);      //generate some data
    std::string x = v[v.size()/2].first;                                //string to search for

    auto t0 = std::chrono::system_clock::now();                                                      // the point of time of the call
    auto pv = std::ranges::find_if(v, [&x](const auto& s) { return s.first == x; });
    auto t1 = std::chrono::system_clock::now();
    std::cout << "vector: " << pv->second << '\n';
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count() << "us\n\n";         // count() is a number of "clock ticks"

    std::map<std::string, int> m {v.begin(), v.end()}; ;
    auto t2 = std::chrono::system_clock::now();
    auto vm = m[x];                                                                           // tree search; may add an element
    auto t3 = std::chrono::system_clock::now();
    std::cout << "map[]: " << vm << '\n';
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t3-t2).count() << "us\n\n";
    return 0;
}