#include<iostream>  //used for I/O
#include<vector>    //used for values
#include<algorithm> //used for std::sort

int main(){
    double current;
    char unit_abbreviated;
    std::string unit;
    std::vector<double> values;

    //must be seperated by whitespace
    std::cout << "Please enter an double, followed by a unit (cm, m, in, ft): \n";
    while(std::cin >> current >> unit){
        std::cout << "Your entered number: " << current << "\nYour entered unit: " << unit << '\n';
        
        //converting unit to a char so its usable in a switch statement
        if(unit == "cm"){
            unit_abbreviated = 'c';
        }else if(unit == "m"){
            unit_abbreviated = 'm';
        }else if(unit == "in"){
            unit_abbreviated = 'i';
        }else if(unit == "ft"){
            unit_abbreviated = 'f';
        }else{
            unit_abbreviated = 'x'; //error
        }

        //read the values (converted to meters) into the vector
        switch (unit_abbreviated)
        {
        case 'c':
            values.push_back(current*0.01);
            break;
        case 'm':
            values.push_back(current);
            break;
        case 'i': //conversion: 1inch = 2.54 cm
            values.push_back(current * 0.0254);
            break;
        case 'f': // conversion: 1 ft = 12 inch = 12*2.54 cm
            values.push_back(current* 0.0254*12);
            break;
        default:
            std::cout << "Sorry, I don't know any unit called " << unit << ".\n";
            break;
        }
    }
        //handling the output
        double sum = 0.0;

        //sort the vector -> ascending size
        std::sort(values.begin(), values.end());
   
        //printing the smallest value
        std::cout << "The smallest value you entered is: " << values[0] << "m.\n";
        //printing the largest value -- Needs to be size()-1 because it's zero indexed
        std::cout << "The largest value you entered is: " << values[values.size()-1] << "m.\n";
        
        //sum up the elements of vector values
        for (int i = 0; i < values.size(); i++){
            sum += values[i];
        }
        //printing the sum
        std::cout << "The sum of the values you entered is: " << sum << "m.\n";
        
        //printing the number of values
        std::cout << "The number of values you entered is: " << values.size() << ".\n";

        //printing the median
        std::cout << "The median of the values you entered is: " << sum/values.size() << ".\n";
    }

    //number of values is reading false numbers as well (like 'x')