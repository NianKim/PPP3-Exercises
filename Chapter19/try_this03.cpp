#include <iostream>
#include <vector>


//We again left a serious error in that program.
// Find it, fix it, and suggest a general remedy for that kind of problem.

double* get_from_jack(int* count);           // Jack fills an array and puts the number of elements in *count
std::vector<double> get_from_jill();                // Jill fills the vector

void fct()
{
        int jack_count = 0;
        double* jack_data = get_from_jack(&jack_count);
        std::vector<double> jill_data = get_from_jill();

        double* jack_high = high(jack_data,jack_data+jack_count);
        double* jill_high = high(jill_data.begin(),jill_data.end());

        std::cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high;
        delete[] jack_data;
}