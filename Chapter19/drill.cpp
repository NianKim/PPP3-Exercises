
#include<iostream>
#include<vector>
#include<list>
#include<span>

//custom copy function using ranges
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
//custom copy function using iterators
template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    //(f: first), (e: end)
    while(f1 != e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

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

    //step 5
    for (int& x : my_array_copy) {
        x += 2;
    }
    for (int& x : my_vector_copy) {
        x += 3;
    }
    for (int& x : my_list_copy) {
        x += 5;
    }

    //step 7:
    my_copy(std::begin(my_array_copy), std::end(my_array_copy), std::begin(my_vector_copy));
    my_copy(std::begin(my_list_copy), std::end(my_list_copy), std::begin(my_array_copy));

    std::cout << "Array copy element 0 (should be 5): " << my_array_copy[0] << "\n";
    std::cout << "Vector copy element 0 (should be 2): " << my_vector_copy[0] << "\n";
    std::cout << "List copy element 0 (should be 5): " << my_list_copy.front() << "\n";

    //step 8
    auto vec_it = std::find(my_vector_copy.begin(), my_vector_copy.end(), 3);
    if (vec_it != my_vector_copy.end()) {
        auto position = std::distance(my_vector_copy.begin(), vec_it);
        std::cout << "Vector contains 3 at position: " << position << "\n";
    } else {
        std::cout << "Vector does not contain 3\n";
    }
    auto list_it = std::find(my_list_copy.begin(), my_list_copy.end(), 27);
    if (list_it != my_list_copy.end()) {
        auto position = std::distance(my_list_copy.begin(), list_it);
        std::cout << "List contains 27 at position: " << position << "\n";
    } else {
        std::cout << "List does not contain 27\n";
    }

    return 0;
}