#include<iostream>
#include<vector>
#include<stdexcept>
#include<fstream>

using namespace std;

void error(string s1, string s2 = ""){
    throw runtime_error{s1+s2};
}


struct Reading {                // a temperature reading
         int hour;                             // hour after midnight [0:23]
         double temperature;         // in Fahrenheit
};
int main()
{
         cout << "Please enter input file name: ";
         string iname;
         cin >> iname;
         ifstream ist {iname};                          // ist reads from the file named iname
         if (!ist)
                  error("can't open input file ",iname);

         string oname;
         cout << "Please enter name of output file: ";        
         
         
         cin >> oname;

         ofstream ost {oname};                       // ost writes to a file named oname
         if (!ost)
                  error("can't open output file ",oname);

         vector<Reading> temps;                   // store the readings here
         int hour = -1;
         double temperature = -700;
         while (ist >> hour >> temperature) {
                  if (hour < 0 || 23 <hour)
                           error("hour out of range");
                  temps.push_back(Reading{hour,temperature});
         }

        for (const Reading& x : temps)
                  ost << '(' << x.hour << ',' << x.temperature << ")\n";
}