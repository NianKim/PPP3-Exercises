#include<iostream>
#include<vector>
#include<stdexcept>
#include<fstream>

using namespace std;

void error(string s1, string s2 = ""){
    throw runtime_error{s1+s2};
}

const int birth_year = 2005;
const int current_year = 2026;

//output birth year in different forms and formatted
int main(){
    try{
        cout << "decimal:\t" << birth_year << "\t-\thexadecimal:\t" << hex << setw(4) << birth_year << "\t-\toctadecimal:\t" << oct << birth_year << '\n';
        cout << "You will be: " << dec << (current_year - birth_year) << " years old in " << (current_year) << '\n';
        
        /*step 8
        // a is read decimal, b oct, c and d as hexadecimal, '\t' is tab
        int a,b,c,d;
        cin >> a >>oct >> b >> hex >> c >> d;
        cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n';
        */

        //step 9
        constexpr float step_9= 1234567.89;
        cout << format("format: {} − {:f} − {:e}\n", step_9, step_9, step_9);

        //step 10

        cout << "┌──────────┬────────────┬──────────────────────────┐\n"
                "│   name   │   number   │       email-adress       │\n"
                "├──────────┼────────────┼──────────────────────────┤\n";
        cout << left
        << "│ " << setw(8) << "Nian Kim" <<  setw(8) << " │  043f5470  │ "
        << setw(24) << fixed  << "nijfdsla@sd.com" <<            " │\n"
        << "│ " << setw(8) << "Briz" <<      " │ sadf07193  │ "
        <<  setw(24) << scientific << "whatdaa@hell.com" <<        " │\n"
        << "│ " <<  setw(8) << "Weey" <<  setw(8) <<" │    homie   │ "
        <<  setw(24) << hexfloat << "absolute@lingang.gulli" <<          " │\n"
        << "│ " <<  setw(8) << "Bur" <<   setw(8) << " │    homie   │ "
        <<  setw(24) << defaultfloat << "skibidi@sigma.com" <<      " │\n"
        << "└──────────┴────────────┴──────────────────────────┘\n";
    }
    /*catch(){
        cerr << "Error: INvalid Date!\n";

        return 1;
    }*/
    catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        return 2;
    }
    return 0;
}