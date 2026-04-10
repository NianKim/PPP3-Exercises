#include <string>
#include <iostream>

// POST: return true if we reach the middle without finding a difference
bool is_palindrome ( const std::string& s )
{
    int first = 0;                  // index of first letter
    int last = s.length() - 1;      // index of last letter
    while ( first < last )          // we haven't reched the middle
    {
        if ( s[first] != s[last] )
            return false;           
        ++first;                    // move forward
        --last;                     // move backward
    }
    return true;
}

int main ()
{
    for ( std::string s; std::cin >> s; )
    {
        std::cout << s << " is";
        if ( !is_palindrome(s) )
            std::cout << " not";
        std::cout << " a palindrome\n";
    }
}