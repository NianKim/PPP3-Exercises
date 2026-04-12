#include <iostream>
#include <span>

using namespace std;

// Pointer-based version 
bool is_palindrome_ptr( const char* first, const char* last ) 
{
    while ( first < last ) {
        if (*first != *last) return false;
        ++first;
        --last;
    }
    return true;
}

// Span version calling the pointer version
bool is_palindrome1(span<const char> s) {
    if (s.empty()) return true;
    // .data() + .size() - 1 points to the actual last character
    return is_palindrome_ptr(s.data(), s.data() + s.size() - 1);
}

bool is_palindrome2(const char* first, const char* last) {
    return is_palindrome1(span<const char>{first, static_cast<size_t>(last - first + 1)});
}

bool is_palindrome3(span<const char> s) {
    if (s.size() < 2) return true;
    if (s.front() != s.back()) return false;
    
    return is_palindrome3(s.subspan(1, s.size() - 2));
}