// vector drill

#include <iostream>
#include <vector>

//[1] Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.

std::vector<int> gv = { 1, 2, 4, 8 , 16, 32, 64, 128, 256, 512 };

//[2] Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.

void f( std::vector<int> arg )
{
    std::vector<int> lv ( arg.size() );
    // copying gv into lv and printing the contents of la
    std::cout << "The content of lv: {";
    for ( int i = 0; i < arg.size(); i++ )
    {
        lv[i] = gv[i];
        if(i < arg.size() - 1 )   std::cout << lv[i] << ", ";
        else        std::cout << lv[i] << "}\n";
    }

    // Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
    std::vector<int> lv2 = arg; 

    
    // Print out the elements of lv2.
    std::cout << "The content of lv2: {";
    for ( int i = 0; i < arg.size(); i++ )
    {
        lv[i] = gv[i];
        if(i < arg.size() - 1 )   std::cout << lv2[i] << ", ";
        else        std::cout << lv2[i] << "}\n";
    }
}

int main() 
{
    f(gv);
    //Define an array aa with ten elements and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    std::vector<int> vv = { 1, 2, 6, 24 , 120, 720, 5040, 40320, 362880, 328800 }; 
    f(vv);
}