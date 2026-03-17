#include<iostream>
#include<string>

//[1] Allocate an array of ten ints on the free store using new.
//[2] Print the values of the ten ints to cout.
//[3] Deallocate the array (using delete[]).
int main(){
    int* int_array = new int[10];
    for ( int i = 0; i < 10; ++i){
        std::cout << "Entry " << i << ": " << int_array[i] << '\n';
    }
    delete[] int_array;
}