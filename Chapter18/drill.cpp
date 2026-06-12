#include<iostream>
#include<string>
#include<vector>

template<typename T> 
struct S {
    private:
        T value;
    
    public:
        S(T val) : value { val } { } 
        const T& access() const { return value; };  //read only
        T& access() {return value;};                //non-const

        S<T>& operator=(const T& x);                  
};


template<typename T>
//assignment
S<T>& S<T>::operator=(const T& x){
    S<T> tmp = x; 
    std::swap(this->value, tmp.value);
    return *this;
}

template<typename T>                                //reads from cin into v
void read_val(T& v) {
    std::cin >> v;
}



template<typename T>                                // Output Operator (<<) for vector<T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "{ ";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i < v.size() - 1) os << ", ";           //trailing comma
    }
    os << " }";
    return os;
}

// 2. Input Operator (>>) for vector<T>
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    char ch1 = 0;
    char ch2 = 0;
    
    // Read the opening '{'
    is >> ch1;
    if (ch1 != '{') {
        is.clear(std::ios_base::failbit);             //failed input
        return is;
    }

    v.clear(); // Clear existing elements before reading new ones
    T elem;
    
    // Read elements until we hit the closing '}'
    while (is >> elem) {
        v.push_back(elem);
        is >> ch2;
        if (ch2 == '}') break; // Finished successfully
        if (ch2 != ',') {      // Must be a comma separating elements
            is.clear(std::ios_base::failbit);
            return is;
        }
    }
    return is;
}


int main() {
    using SVector = S<std::vector<int>>;

    SVector e{ {1, 2, 3, 4} };

    std::cout << "Current vector: " << e.access() << '\n';

    std::cout << "Enter a new vector in format { 10, 20, 30 }: ";
    read_val(e.access());

    std::cout << "New vector is: " << e.access() << '\n';

    std::cout << "Successfully compiled!" << '\n';
    return 0;
}