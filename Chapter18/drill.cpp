#include<iostream>
#include<string>
#include<vector>

template<typename T> 
struct S {
    private:
        T value;
    
    public:
    S(T val) : value { val } { } 
    const T& access() const { return value; };    //read only
    T& non_const_access() {return value;};  //non-const

    S<T>& operator=(const T& x);
    void read_val(T& v);                    //reads from cin into v
};


template<typename T>
//assignment
S<T>& S<T>::operator=(const T& x){
    S<T> tmp = x; 
    std::swap(this->value, tmp.value);
    return *this;
}

template<typename T>
void read_val(T& v) {
    std::cin >> v;
}


int main() {

    using SString = S<std::string>;
    using SVector = S<std::vector<int>>;

    S<int> a = 0;
    std::cout << "Enter a new integer: ";
    read_val(a.non_const_access()); 

    S<char> b = ' ';
    std::cout << "Enter a new char: ";
    read_val(b.non_const_access()); 

    S<double> c = 0.0000;
    std::cout << "Enter a new double: ";
    read_val(c.non_const_access());  

    SString d{"Templates!"};
    SVector e{ { 1,2,3,4 }};

    std::cout <<    a.access() << " " <<
                    b.access() << " " <<
                    c.access() << " " <<
                    d.access() << '\n';
    for(int x : e.non_const_access()){
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::cout << "Successfully compiled!" << '\n';
    return 0;
}