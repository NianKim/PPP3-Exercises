#include<iostream>
#include<string>
#include<vector>

template<typename T> 
struct S {
    private:
        T value;
    
    public:
    S(T val) : value { val } { } 
    const T& access() { return value; };    //read only

    S<T>& operator=(const T& x);
};


template<typename T>
//assignment
S<T>& S<T>::operator=(const T& x){
    S<T> tmp = x; 
    std::swap(this->value, tmp.value);
    return *this;
}


int main() {

    using SString = S<std::string>;
    using SVector = S<std::vector<int>>;

    S<int> a = 67;
    S<char> b = 'v';
    S<double> c = 3.14;

    SString d{"Templates!"};
    SVector e{ { 1,2,3,4 }};

    std::cout <<    a.access() << " " <<
                    b.access() << " " <<
                    c.access() << " " <<
                    d.access() << '\n';
    for(int x : e.access()){
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::cout << "Successfully compiled!" << '\n';
    return 0;
}