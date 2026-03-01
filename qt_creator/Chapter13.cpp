#include "Simple_window.h"                       // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
#include <cmath>

using namespace Graph_lib;

double dsin(double d) {return std::sin(d);}
double slope(double x) { return 0.5*x; }           // the slope is 0.5
double square(double x) { return x*x; }
double one(double) { return 1; }

int main()
{
                               // our graphics facilities are in Graph_lib

    Application app;                                                    // start a Graphics/GUI application
   constexpr int xmax = 600;                         // window size
   constexpr int ymax = 400;

   constexpr int x_orig = xmax/2;                 // position of (0,0) is center of window
   constexpr int y_orig = ymax/2;
   constexpr Point orig {x_orig,y_orig};

   constexpr int r_min = (-10);                        // range [-10:11)
   constexpr int r_max = 11;

   constexpr int n_points = 400;                    // number of points used in range

   constexpr int x_scale = 30;                       // scaling factors
   constexpr int y_scale = 30;

   Simple_window win {Point{100,100},xmax,ymax,"Three functions"};

   Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
   Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
   Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};

   win.attach(s);
   win.attach(s2);
   win.attach(s3);
   win.wait_for_button();
}
