
#include <iostream>

int main() 
{
    //example of a shallow copy:
    int* p = new int{77};
    int* q = p;             //copy the pointer of p
    *p = 88;                // change the calue of the int pointed to by p and q
    std::cout << "Shallow - p: " << *p << ", q: " << *q << "\n";


    // example of a deep copy:
    int* p2 = new int{77};
    int* q2 = new int{*p};   //allocate new int, then copy the value pointed to by p
    *p2 = 88;                //change the value of the int pointed to by the p
    std::cout << "Deep - p2: " << *p2 << ", q2: " << *q2 << "\n";


}