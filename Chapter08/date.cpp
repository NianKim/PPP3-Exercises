/*
Write Day, Month, and their associated functions as described above. 
Complete the final version of Date with default constructor, is_valid(), 
Month, Year, etc. Define a Date called today initialized to February 2, 
2020. Then, define a Date called tomorrow and give it a value by copying 
today into it and increasing its day by one using add_day(). Finally, 
output today and tomorrow using a << defined as in §9.6 and §9.7.

Your check for a valid date, is_valid(), may be very simple. Feel free 
to ignore leap years. However, don’t accept a month that is not in the 
[1,12] range or a day of the month that is not in the [1,31] range. 
Test each version with at least one invalid date (e.g., 2004, 13, -5).
*/

#include<iostream>
using namespace std;

class Date{
    public:
        //Date(int y, int m, int d); //check for valid date and initialize 
        Date(int yy, int mm, int dd) //constructor
            :y{yy}, m{mm}, d{dd}            //note: member initializers
            {}
        int month() {return Date::m;}
        int day() {return Date::d;}
        int year() {return Date::y;}
    private:
        int y, m, d; //year, month, day
};

//help from Stroustrup
ostream& operator<<(ostream& os, Date d)
    {
            return os << d.year() << '/' << d.month() << '/' << d.day();
    }


void init_day(Date& dd, int y, int m, int d){
    //check that (y,m,d) is a valid date. If it is, use it to init dd
}

void add_day(Date& dd, int n){
    //increase dd by n days
}
int main(){
    Date today{2025, 2, 4};

    cout << "Today is: " << today << '\n';
    return 0;
}
