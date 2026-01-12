#include<iostream>
#include<vector>

int main(){
    //this program reads strings the user would like to censor
    std::vector<std::string> blacklist;
    int word_counter;
    std::cout << "Please enter the number of words you would like to censor: ";
    std::cin >> word_counter;

    //read all the blacklisted words into the vector - TODO: what if the user writes the same word many times?
    std::cout << "Please enter the words you would like to censor, seperated by whitespace: "; 
    std::string temp_word;
    for(int i = 0; i < word_counter ; ++i){
        std::cin >> temp_word;
        blacklist.push_back(temp_word);
    }

    //iterate over the user string to bleep words
    int string_counter;
    std::cout << "Please enter the number of words in your sentence: ";
    std::cin >> string_counter;

    //read the sentence
    std::cout << "Please enter the sentence you would like to censor:\n";
    std::vector<std::string> user_string;
    std::string temp_string;
    for(int i = 0; i < string_counter ; ++i){
        std::cin >> temp_string;
        user_string.push_back(temp_string);
    }

    for(int j = 0 ; j < user_string.size(); ++j){
        bool is_censored = false;
        for(int k = 0; k < blacklist.size(); ++k){
            if(blacklist[k] == user_string[j]){
                is_censored = true;
                break;
            }
        }
        if(is_censored){
            std::cout << "BLEEP ";
        }else{
            std::cout << user_string[j] << " "; 
        }
    }

    std::cout << "\nBig Brother is watching you!\n";
    return 0;
}