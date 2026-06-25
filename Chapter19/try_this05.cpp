/*
What does that list of differences mean in real code? 
For each of char[], vector<char>, list<char>, and string, 
define one with the value "Hello", pass it to a function 
as an argument, write out the number of characters in the 
string passed, try to compare it to "Hello" in that function 
(to see if you really did pass "Hello"), and compare the 
argument to "Howdy" to see which would come first in a dictionary. 
Copy the argument into another variable of the same type.
*/
#include<vector>
#include<list>
#include<array>
#include<string>
#include<iostream>
#include<algorithm>

void process_string(const std::string& s) {
    std::cout << "String size: " << s.size() << '\n';
    if (s == "Hello") std::cout << "This is a Hello!\n";
    if (s == "Howdy") std::cout << "Comes before Howdy!\n";

    std::string my_copy = s;
}

void process_vector(const std::vector<char>& v) {
    
    std::cout << "Vector size: " << v.size() << "\n";

    std::vector<char> hello = {'H', 'e', 'l', 'l', 'o'};
    if (v == hello) {
        std::cout << "Vector matches Hello!\n";
    }

    std::vector<char> howdy = {'H', 'o', 'w', 'd', 'y'};
    //lexicographical_compare is in std lib algorithm
    if (std::lexicographical_compare(v.begin(), v.end(), howdy.begin(), howdy.end())) {
        std::cout << "Vector comes before Howdy\n";
    }

    std::vector<char> v_copy = v;
}

void process_list(const std::list<char>& l) {
    std::cout << "List size: " << l.size() << '\n';

    std::list<char> hello = {'H','e','l','l','o'};
    if (l == hello) {
        std::cout << "List matches Hello!\n";
    }

    std::list<char> howdy = {'H','o','w','d','y'};
    //if (std::)

    std::list<char> l_copy = l;
}

//array of chars decays to a pointer. Therefore I need helper functions
int get_size(const char* a) {
    int size = 0;
    while (a[size] != '\0') {
        size++;
    }
    return size;
}

void manual_copy(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';  //terminates new string
}

//returns 0 if perfectly equal
//returns positive number if a[i] > b[i] (b comes first in dictionary)
//returns negative number if a[i] < b[i] (a comes first in dictionary)
int manual_compare (const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]){
        i++;
    }
    return a[i] - b[i];
}

void process_raw_array(const char* a) {
    std::cout << "Array size: " << get_size(a) << '\n';

    if(manual_compare(a, "Hello") == 0) {
        std::cout << "Array matches Hello!\n";
    }

    if(manual_compare(a, "Howdy") < 0) {
        std::cout << "Array comes before Howdy in alphabetical order\n";
    }
}

int main() {
    char my_array[6] = "Hello"; // {'H','e','l','l','o', '\0'}; // size 6 due to null terminator
    std::vector<char> my_vector = {'H','e','l','l','o'};
    std::list<char> my_list = {'H','e','l','l','o'};
    std::string my_string = "Hello";

    //first all non-array types:
    //easier thanks to helper function lexicographical_compare
    process_string(my_string);
    process_vector(my_vector);
    process_list(my_list);

    //then array
    //requires way more helper functions
    process_raw_array(my_array);

}
