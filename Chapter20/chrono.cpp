#include<chrono>
#include<iostream>

//using namespace std::chrono;

int do_something() {
    int sum = 0;
    for(int i =0; i < 1000000; ++i)
        sum += i;
    return sum;
}
int main() {
    //can be high_resolution_clock and steady_clock
    auto t0 = std::chrono::system_clock::now();
    auto x = do_something();
    auto t1 = std::chrono::system_clock::now();
    std::cout << "res: " << x << '\n';
    auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "Time taken: " << duration_us.count() << " us\n";
}