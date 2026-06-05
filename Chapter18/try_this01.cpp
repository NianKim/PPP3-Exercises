

/*
Add try-blocks to this last example to ensure that all resources 
are properly released in all cases where an exception might be thrown.
*/

#include <iostream>
#include <vector>
#include <stdexcept>

namespace PPP {
    template<typename T>                                 // concept 'Element': constrain element types
    struct Checked_vector : public std::vector<T> {     //inherits from std::vector
        using size_type = typename std::vector<T>::size_type;
        using value_type = T;
        using std::vector<T>::vector;                     //std::vector constructors

        T& operator[](size_type i)                   // rather than return at(i);
        {
                return std::vector<T>::at(i);        //.at() throws an error if 'i' out of bounds
        }

        const T& operator[](size_type i) const
        {
                return std::vector<T>::at(i);
        }
    }; // Checked_vector
}// namespace PPP

int main() {
    PPP::Checked_vector<int> my_safe_numbers;

    my_safe_numbers.push_back(10);
    my_safe_numbers.push_back(20);

    try {
        // This is SAFE. It prints 10.
        std::cout << "First number: " << my_safe_numbers[0] << "\n"; 

        // This is OUT OF BOUNDS. 
        // Checked_vector will safely throw an exception here!
        std::cout << "Bad number: " << my_safe_numbers[5] << "\n"; 
        
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught an error: You tried to access memory outside the vector!\n";
    }

    return 0;
}