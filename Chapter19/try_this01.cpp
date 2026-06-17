#include <vector>
#include <iostream>

double* get_from_jack(int* count){
    *count = 3;
    double* data = new double[3] { -12312.3, 4.32, -432.32 };
    return data;
}
//Jack fills an array and puts the number of elements in *count

std::vector<double> get_from_jill(){
    return {-32.33, -234.33, 654.3};
}     //Jill fills a vector


double* high(double* first, double* last){
    // return a pointer to the element in [first:last) that has the highest value
    if( first == last ) return nullptr;

    double* high_ptr = first;

    for (double* p = first + 1; p != last; ++p){
        if( *high_ptr < *p ){
            high_ptr = p;
        }
    }
    return high_ptr;
}

void fct(){
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    std::vector<double> jill_data = get_from_jill();

    double* jack_high = nullptr;
    //will point to the element with the highest value, crashes if empty

    double* jill_high = nullptr;      
    //will point to the element with the highest value

    if (jack_data != nullptr && jack_count > 0) {
        jack_high = high(jack_data, jack_data + jack_count);
    }

    if ( !jill_data.empty() ){
        jill_high = high(jill_data.data(), jill_data.data() + jill_data.size());
    }
    
    if (!jill_data.empty()) {
        auto modern_jill_high = std::max_element(jill_data.begin(), jill_data.end());
        std::cout << "Modern Jill's max: " << *modern_jill_high << "\n";
    }

    if (jack_high) std::cout << "Jack's max: " << *jack_high << '\n';
    if (jill_high) std::cout << "Jill's max: " << *jill_high << '\n';

    //std::vector<double>& v = jill_data;

    
    // ...
    delete[] jack_data;
}

int main(){
    fct();
    return 0;
}