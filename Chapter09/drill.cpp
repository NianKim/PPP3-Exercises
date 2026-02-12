/*
[11] Defining a data type Point that has two coordinate members x and y. Define << and >> for Point as discussed in §9.3.1.

[12] Using the code and discussion in §9.3.1, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a vector<Point> called original_points.

[13] Print the data in original_points to see what it looks like.

[14] Open an ofstream and output each point to a file named mydata.txt. We suggest the .txt suffix to make it easier to look at the data with an ordinary text editor if you are using Windows.

[15] Open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new vector called processed_points.

[16] Print the data elements from both vectors.

[17] Compare the two vectors and print “Something’s wrong!” if the number of elements or the values of elements differ.
*/
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void error(string s1){
    throw runtime_error{s1};
}

class Point{
    public:
        //check for valid date and initialize 
        Point(double xx, double yy) //constructor
            :x{xx}, y{yy}  {}         //missed the final body

    double get_x() const{return x;}
    double get_y() const{return y;}

    private:
    double x,y;
};

ostream& operator<<(ostream& os, const Point& p)
{
        return os 
            << '('
            << p.get_x()
            << ',' 
            << p.get_y()
            << ')';
}

istream& operator >>(istream& is, Point& p){
    double x,y;
    char ch1, ch2, ch3;

    is >> ch1 >> x >> ch2 >> y >> ch3;

    if(!is) return is;
    if(ch1 != '(' || ch2 != ',' || ch3 != ')') {
        // If format is wrong, set the stream to "fail"
        is.clear(ios_base::failbit);
        return is;
    }
// If successful, update the Point p
    p = Point(x, y);
    return is;
}

// ---------------------------------------------------------
// Steps 12-17: Main Execution
// ---------------------------------------------------------
int main() {
    // --- Step 12: Get 7 points from user ---
    vector<Point>original_points;
    cout << "Please enter 7 points in the format (x,y):" << endl;
    
    for (int i = 0; i < 7; ++i) {
        double x, y;
        char ch1, comma, ch2;
        cin >> ch1 >> x >> comma >> y >> ch2; // Reads ( 1 , 2 )
        original_points.push_back(Point(x,y));
    }

    // --- Step 13: Print original points ---
    cout << "\nOriginal Points:" << endl;
    for (const auto& p : original_points) {
        cout << p << endl;
    }

    // --- Step 14: Write to file ---
    string filename = "mydata.txt";
    ofstream ost(filename); 
    if (!ost) error("Could not open file for writing");
    
    for (const auto& p : original_points) {
        ost << p << endl; 
    }
    ost.close(); // closing ostream

    // --- Step 15: Read from file ---
    vector<Point> processed_points;
    ifstream ist(filename);
    if (!ist) error("Could not open file for reading");
    
    Point p(0,0); // Temp variable
    while (ist >> p) { // Uses our operator>> 
        processed_points.push_back(p); //could be emplace
    }

    // --- Step 16: Print both ---
    cout << "\nProcessed Points (from file):" << endl;
    for (const auto& p : processed_points) {
        cout << p << endl;
    }

    // --- Step 17: Compare ---
    if (original_points.size() != processed_points.size()) {
        cout << "Something's wrong! Sizes differ." << endl;
    } else {
        // Check values
        bool same = true;
        for(size_t i = 0; i < original_points.size(); ++i) {
            if(original_points[i].get_x() != processed_points[i].get_x() ||
               original_points[i].get_y() != processed_points[i].get_y()) {
                same = false;
                break;
            }
        }
        if(!same) cout << "Something's wrong! Values differ." << endl;
        else cout << "Success! Vectors are identical." << endl;
    }

    return 0;
}

//todo: clear up ost.close()