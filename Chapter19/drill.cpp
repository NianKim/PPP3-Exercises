
#include<iostream>
#include<vector>
#include<list>
#include<span>

//custom std::copy function using ranges
/*
template <typename Src, typename Dest>
void custom_copy(Src&& source, Dest&& destination) {
    auto src_it = std::begin(source);
    auto dest_it = std::begin(destination);

    while (src_it != std::end(source) && dest_it != std::end(destination)) {
        *dest_it = *src_it;
        ++src_it;
        ++dest_it;
    }
}
*/


int main(){
    int my_array[10] = {0,1,2,3,4,5,6,7,8,9}; // [1] Define an array of ints 
    std::vector<int> my_vector = {0,1,2,3,4,5,6,7,8,9}; // [2] Define a vector<int>
    std::list<int> my_list = {0,1,2,3,4,5,6,7,8,9}; // [3] Define a list<int> 
    std::vector<int> my_vector_copy = my_vector;
    std::list<int> my_list_copy = my_list;

    //array needs std::copy
    int my_array_copy[10];
    for (int i = 0; i< 10; ++i) {
        my_array_copy[i] = my_array[i];
    }

    std::cout << "Custom copy: Element 5 is : " << my_array_copy[5] << '\n';
    return 0;
}