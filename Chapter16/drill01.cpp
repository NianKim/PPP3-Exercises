// array drill

#include <iostream>

//[1] Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.

int ga[10] = { 1, 2, 4, 8 , 16, 32, 64, 128, 256, 512 };

//[2] Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.

void f(int arg[], int nr_of_elements)
{
    int la[10];
    // copying ga into la and printing the contents of la
    std::cout << "The content of la: {";
    for ( int i = 0; i < nr_of_elements; i++ )
    {
        la[i] = ga[i];
        if(i < nr_of_elements - 1 )   std::cout << la[i] << ", ";
        else        std::cout << la[i] << "}\n";
    }

    //Define a pointer p to int and initialize it with an array allocated on the free store with the same number of elements as the argument array.
    int* p = new int[nr_of_elements];

    //Copy the values from the argument array into the free-store array.
    //Print out the elements of the free-store array.
    std::cout << "Elements of free store array: {";
    for ( int i = 0; i < nr_of_elements; i++ )
    {
        p[i] = arg[i];
        if(i < nr_of_elements - 1 )   std::cout << p[i] << ", ";
        else        std::cout << p[i] << "}\n";
    }
    //Deallocate the free-store array.
    delete[] p;
}

int main() 
{
    f(ga, 10);
    //Define an array aa with ten elements and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    int aa[10] = { 1, 2, 6, 24 , 120, 720, 5040, 40320, 362880, 328800 }; 
    f(aa, 10);
}