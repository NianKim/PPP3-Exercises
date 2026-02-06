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
#include<vector>
using namespace std;


//types first
enum class Month {
         jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int to_int(Month m)
{
         return static_cast<int>(m);
}
Month operator++(Month& m){
    m = (m==Month::dec) ? Month::jan : Month{to_int(m)+1}; //arithmetic if
    return m;
}
//see line 42
ostream& operator<<(ostream& os, Month m){
    static const vector<string> month_tbl = {
        "Not_A_Month", "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    return os << month_tbl[to_int(m)];
}


//helper functions

class Date{
    public:
        class Invalid{}; //exception
        //check for valid date and initialize 
        Date(int yy, Month mm, int dd) //constructor
            :y{yy}, m{mm}, d{dd}            //note: member initializers
            {
                if(!is_valid()){
                    throw Invalid{};
                }
            }
        Month month() const{return Date::m;} //getting the value shouldn't change it
        int day() const{return Date::d;}
        int year() const{return Date::y;}

        //prevent invalid dates:
        bool is_valid();
        void add_day(int n);

    private:
        int y; // year
        Month m;
        int d; //day
};

//help from Stroustrup
//passing into ostream& os (console window) whenever you see '<< Date_obj'
ostream& operator<<(ostream& os, Date d)
    {
            return os << d.year() << '/' << d.month() << '/' << d.day();
    }

//ignoring leap years and different month lengths
bool Date::is_valid(){
    //NEW: tried implementing day checks for the different months (ignoring leap years)
    
    //if(d<1||d>31){return false;}
    switch (to_int(m))
    {
    case 1: //Jan, Mar, May, Jul, Aug,oct, dec can have 31 days
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(d >0 && d < 32){return true;}
        else{return false;}
        break;
    case 4: // apr, jun sep nov can have 30 days
    case 6:
    case 9:
    case 11:
        if(d>0&&d<31){return true;}
        else{return false;}
        break;
    case 2: //feb can have up to 28 days
        if(d>0&& d <29){return true;}
        else{return false;}
        break;
    default:
        return false;
        break;
    }
}

void Date::add_day(int n){
    d+=n;
    while (d>31){
    ++m;
    d-=31;
    if(m==Month::jan)++y;
    }
}

void error(string s){
    throw runtime_error{s};
}

int main(){
    try{
        Date today{2025, Month::feb, 4};
        cout << "Today is: " << today << '\n'; 

        Date tomorrow = today;
        tomorrow.add_day(1);
        cout << "Tomorrow is: " << tomorrow << '\n';

        cout << "\nTesting Month Wrap: \n";   
        Month m = Month::dec;
        cout << "Current: " << m << '\n';
        ++m;
        cout << "Next:    " << m << " (Should be Jan)\n";
    }
    catch(Date::Invalid){
        cerr << "Error: INvalid Date!\n";
        return 1;
    }
    catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        return 2;
    }
    return 0;
}
