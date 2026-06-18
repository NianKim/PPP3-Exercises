
//We again left a serious error in that program.
// Find it, fix it, and suggest a general remedy for that kind of problem.

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


template<typename Iter>
Iter high(Iter first, Iter last) {
    if (first == last) return last; 

    Iter high_ptr = first;
    ++first; // Start comparing from the second element
    for (Iter p = first; p != last; ++p) {
        if (*high_ptr < *p) {
            high_ptr = p;
        }
    }
    return high_ptr;
}

void fct()
{
        int jack_count = 0;
        double* jack_data = get_from_jack(&jack_count);
        std::vector<double> jill_data = get_from_jill();

        auto jack_high = high(jack_data,jack_data+jack_count);
        auto jill_high = high(jill_data.begin(),jill_data.end());

        // Protect against empty containers by checking against the 'end'
        if (jack_high != (jack_data + jack_count)) {
            std::cout << "Jack's high " << *jack_high << "\n";
        } else {
            std::cout << "Jack has no data.\n";
        }

        if (jill_high != jill_data.end()) {
            std::cout << "Jill's high " << *jill_high << "\n";
        } else {
            std::cout << "Jill has no data.\n";
        }
        delete[] jack_data;
}

int main(){
    fct();
    return 0;
}