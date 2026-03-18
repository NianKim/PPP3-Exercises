#include<iostream>
#include <vector>
using namespace std;

int main(){
    //[1] Allocate an int, initialize it to 7, and assign its address to a variable p1.
    int* p1 = new int{7};
    //[2] Print out the value of p1 and of the int it points to.
    std::cout << p1 << " ";
    std::cout << *p1 << '\n';

    //[3] Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
    int* p2 = new int [7] {1, 2, 4, 8, 16, 32, 64};
    //[4] Print out the value of p2 and of the array it points to.
    std::cout << "{";
    for (int i = 0; i < 7; ++i){
        std::cout << p2[i] << ", ";
    }
    std::cout << "}\n";

    //[5] Declare an int* called p3 and initialize it with p2.
    int* p3 = p2;
    //[6] Assign p1 to p2.
    p2 = p1;
    //[7] Assign p3 to p2.
    p2 = p3;

    //[8] Print out the values of p1 and p2 and of what they point to.
    std::cout << "Address of p1: " << p1 << '\n';
    std::cout << "value of p1: {";
    for ( int i = 0; i < 7 ; ++i){
        if(i < 6){
            std::cout << p1[i] << ", ";
        }else{
            std::cout << p1[i];
        }
    }
    std::cout << "}\n";
    
    std::cout << "Adress of p2: " << p2 << '\n';
    std::cout << "value of p2: {";
    for ( int i = 0; i < 7 ; ++i){
        if(i < 6){
            std::cout << p2[i] << ", ";
        }else{
            std::cout << p2[i];
        }
    }
    std::cout << "}\n";

    //[9] Deallocate all the memory you allocated from the free store.
    delete p1;
    delete[] p3;
    //p1 points to int{7}
    //p2 and p3 point to int[7] array

    
//[10] Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to p1.
    p1 = new int [10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

//[11] Allocate an array of ten ints, and assign its address to a variable p2.
    p2 = new int [10];

//[12] Copy the values from the array pointed to by p1 into the array pointed to by p2.
    for(int i = 0; i < 10; ++i){
        p2[i] = p1[i];
    }
//[13] Repeat 10–12 using a vector rather than an array.
    vector<int> v1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> v2(10);
    v2 = v1;
}