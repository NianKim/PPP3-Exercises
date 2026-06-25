/*
    Do the previous TRY THIS for an array of int,
     vector<int>, and list<int> each with the value {1,2,3,4,5}. 
*/
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>


void process_vector(const std::vector<int>& v) {
    std::cout << "Vector size: " << v.size() << "\n";

    std::vector<int> target = {1, 2, 3, 4, 5};
    if (v == target) {
        std::cout << "Vector matches {1,2,3,4,5}!\n";
    }

    std::vector<int> alternative = {1, 6, 3, 4, 5}; // instead of "Howdy"
    if (std::lexicographical_compare(v.begin(), v.end(), alternative.begin(), alternative.end())) {
        std::cout << "Vector comes before alternative numerically\n";
    }

    std::vector<int> v_copy = v;
}

// ==================== 2. LIST OF INTS ====================
void process_list(const std::list<int>& l) {
    std::cout << "List size: " << l.size() << "\n";

    std::list<int> target = {1, 2, 3, 4, 5};
    if (l == target) {
        std::cout << "List matches {1,2,3,4,5}!\n";
    }

    std::list<int> alternative = {1, 6, 3, 4, 5};
    if (std::lexicographical_compare(l.begin(), l.end(), alternative.begin(), alternative.end())) {
        std::cout << "List comes before alternative numerically\n";
    }

    std::list<int> l_copy = l;
}

// ==================== 3. RAW INT ARRAY HELPERS ====================

// Checks if two integer arrays of known sizes match or determines sequence order
int manual_compare(const int* a, int a_size, const int* b, int b_size) {
    int i = 0;
    // Walk through both arrays as long as elements match and within bounds
    while (i < a_size && i < b_size && a[i] == b[i]) {
        i++;
    }
    
    // If we reached the end of both safely, check which one ran out of elements first
    if (i == a_size && i == b_size) return 0;  // Perfectly identical
    if (i == a_size) return -1;                // Array 'a' is shorter, so it comes first
    if (i == b_size) return 1;                 // Array 'b' is shorter, so it comes first

    return a[i] - b[i]; // Return difference of mismatching elements
}

void process_raw_array(const int* a, int size) {
    std::cout << "Raw Array size: " << size << "\n";

    int target[5] = {1, 2, 3, 4, 5};
    if (manual_compare(a, size, target, 5) == 0) {
        std::cout << "Raw Array matches {1,2,3,4,5}!\n";
    }

    int alternative[5] = {1, 6, 3, 4, 5};
    if (manual_compare(a, size, alternative, 5) < 0) {
        std::cout << "Raw Array comes before alternative numerically\n";
    }

    // Dynamic copy since stack allocation needs a fixed compile-time size
    int* a_copy = new int[size];
    for (int i = 0; i < size; ++i) {
        a_copy[i] = a[i];
    }

    delete[] a_copy; // Clean up memory allocation
}

// ==================== MAIN ====================
int main() {
    int my_array[5] = {1, 2, 3, 4, 5};
    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    std::list<int> my_list = {1, 2, 3, 4, 5};

    process_vector(my_vector);
    process_list(my_list);
    
    // Explicitly passing the size 5 since the array decays to a pointer
    process_raw_array(my_array, 5); 

    return 0;
}