#include <string>
#include <iostream>

using namespace std;

#include <cctype> // for isspace

istream& read_word(istream& is, char* buffer, int max)
{
    // 1. Skip leading whitespace
    char ch;
    while (is.get(ch) && isspace(ch)) 
        ; // do nothing

    if (!is) return is; // Check if we hit end-of-file (EOF)

    // 2. Read characters into buffer
    int i = 0;
    // We stop if we hit whitespace, EOF, or reach max-1 (to leave room for '\0')
    do {
        buffer[i] = ch;
        i++;
    } while (i < max - 1 && is.get(ch) && !isspace(ch));

    buffer[i] = '\0'; // 3. Always null-terminate C-style strings!
    return is;
}

// POST: determines palindromes using pointers
// first points to the first letter, last to the last letter
bool is_palindrome1(const char* first, const char* last)
{
         while (first < last) {          // we haven’t reached the middle
                 if (*first!=*last)
                         return false;
                 ++first;                    // move forward
                 --last;                    // move backward
         }
         return true;
}

bool is_palindrome2(const char* first, const char* last)
        // first points to the first letter, last to the last letter
{
        if (first<last)
                return (*first==*last) ? is_palindrome2(first+1,last-1) : false;
        return true;
}

// is_palindrome making 

int main()
{
        const int max = 128;
        for (char s[max]; read_word(cin,s,max); ) {
                cout << s << " is";
                if (strlen(s) > 0 && !is_palindrome1(&s[0], &s[strlen(s) - 1]))
                       cout << " not";
                cout << " a palindrome\n";
        }
}