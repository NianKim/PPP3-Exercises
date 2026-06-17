/*
    Write a function void copy(int* f1, int* e1, int* f2) 
    that copies the elements of an array of ints defined by 
    [f1:e1) into another [f2:f2+(e1−f1)). Use only the iterator
    operations mentioned above (not subscripting).
*/

#include <iostream>

void copy(int* f1, int* e1, int* f2){

    while(f1 != e1){
        *f2 = *f1;

        ++f2;
        ++f1;
    }
    return;
}

int main(){
    int first_array[6] = {4,2,12,5435,12,42};
    int second_array[6] = {0}; //initialize with 0

    int* f1 = &(first_array[0]);
    int* e1 = &(first_array[6]);

    int* f2 = &(second_array[0]);

    copy (f1, e1, f2);
    for(int i = 0; i < 6; ++i) {
        std::cout << second_array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
