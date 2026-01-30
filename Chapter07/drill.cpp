//this program should illustrate why certain things won't compile
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

// eg. error("putback() into a full buffer");
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

// eg. keep_window_open("~1")
inline void keep_window_open(string s)
{
	if (s=="") return;
	cin.clear();
	cin.ignore(120,'\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss!=s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}

//TODO: Write three functions:

//Swap_v(int,int)
void swap_v(int a, int b){ //creates copies of the parameters
    int temp = a; //temporarily store a's value
    a = b;
    b = temp; //ghost swap: activation record (stack), a and b are destroyed upon stack frame destruction
}
//swap_r (int&,int&)
void swap_r(int& a, int& b){ //pass by reference
    int temp = a;
    a = b;
    b = temp;
}
//swap_cr(const int& const int&)
void swap_cr(const int& a, const int& b){ //pass by const reference, will not actually swap
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    //try to call the swaps like this
    int x = 7;
    int y = 9;
    swap_r(x,y);    //variables are swapped
    swap_v(7,9);    //swaps only copies
    const int cx = 7;
    const int cy = 9;
    swap_cr(cx,cy);    //no swap, cannot assign to const
    swap_v(7.7,9.9); //truncation be careful
    double dx = 7.7;
    double dy = 9.9;
    swap_cr(dx,dy); //can't get a reference 
    swap_v(7.7,9.9); //truncation be careful
}