/*
Try This

First get the program as written to work and test it with a small file of,
 say, a few hundred words. Then try the emphatically not recommended version 
 that guesses about the size of input and see what happens when the input 
 buffer b overflows. Note that the worst-case scenario is that the overflow 
 led to nothing bad in your particular example, so that you would be tempted 
 to ship it to users.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    string from, to;
    cout << "Enter source and target file names: ";
    cin >> from >> to;                                     // get source and target file names

    ifstream is {from};                                     // open input stream
    ofstream os {to};                                       // open output stream

    if (!is || !os) {
            cerr << "Error opening files!" << endl;
            return 1;
    }                             // open output stream

    istream_iterator<string> ii {is};                 // make input iterator for stream
    istream_iterator<string> eos;                   // input sentinel
    ostream_iterator<string> oo {os,"\n"};     // make output iterator for stream

    vector<string> b {ii,eos};                          // b is a vector initialized from input
    sort(b.begin(),b.end());                            // sort the buffer
    copy(b.begin(),b.end(),oo);                    // copy buffer to output
}