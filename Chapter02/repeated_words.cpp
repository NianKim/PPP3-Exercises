#include <iostream>

//this program compares the repeated words of an input. It is case sensitive. It can also be interrupted in the case of "he he he!"
int main(){
    std::string previous;
    std::string current;
    std::cin >> previous;
    int counter = 1; //counts the number of repetitions of a singular word
    while (std::cin >> current){
        if(previous == current){
            //std::cout << "repeated words: " << current << '\n';
            previous = current;
            counter++;
        }
        if (previous != current){
            std::cout << "The word " << previous << " appeared " << counter << " times.\n";   
            previous = current;
            counter = 1;
        }
    }
    return 0;
}
