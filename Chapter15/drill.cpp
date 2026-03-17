#include<iostream>
#include<string>

//[1] Allocate an array of ten ints on the free store using new.
//[2] Print the values of the ten ints to cout.
//[3] Deallocate the array (using delete[]).

void print_array(std::ostream& os, int* a, int n){
    //print out values of a assuming n entries
    for(int i = 0; i < n; ++i){
        os << a[i] << " ";
    }
    os << std::endl;
}

int main(){
    //[7] Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    int* int_array = new int[20];
    for ( int i = 0; i < 20; ++i){
        int_array[i] = 100 + i;
    }
    print_array(std::cout, int_array, 20);
    delete[] int_array;
}