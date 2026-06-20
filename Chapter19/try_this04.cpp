//The standard-library vector doesn’t provide push_front(). 
//Why not? Implement push_front() for vector and compare it to push_back().

#include<vector>
#include<iostream>

template <typename T>
void push_front(std::vector<T>& v, const T& val){
    v.insert(v.begin(),val);
};

int main(){
    std::vector<int> v(5);
    push_front(v, 453);
    
    std::cout << "[";
    for(int i = 0; i < v.size(); ++i){
        if (i != v.size()-1)
            std::cout << v[i] << ",";
        else   
            std::cout << v[i] << "]";
    }

    return 0;
}