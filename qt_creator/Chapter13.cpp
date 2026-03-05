#include "Simple_window.h"                       // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
#include <cmath>

using namespace Graph_lib;

double dsin(double d) {return std::sin(d);}
double slope(double x) { return 0.5*x; }           // the slope is 0.5
double square(double x) { return x*x; }
double one(double) { return 1; }
double dcos(double d) { return cos(d); }          // dcos() chooses cos(double)
double sloping_cos(double x) { return cos(x)+slope(x); }
double fac(int n)               // factorial(n); n!
{
    int r = 1;
    while (n>1) {
        r*=n;
        --n;
    }
    return r;
}
double term(double x, int n) { return pow(x,n)/fac(n); }    // nth term of series
double exp_n(double x, int n)             // sum of n terms for x
{
    double sum = 0;
    for (int i=0; i<n; ++i)
        sum+=term(x,i);
    return sum;
}

int main()
{
                               // our graphics facilities are in Graph_lib

    Application app;                                                    // start a Graphics/GUI application
   constexpr int xmax = 600;                         // window size
   constexpr int ymax = 600;

   constexpr int x_orig = xmax/2;                 // position of (0,0) is center of window
   constexpr int y_orig = ymax/2;
   constexpr Point orig {x_orig,y_orig};

   constexpr int r_min = (-10);                        // range [-10:11)
   constexpr int r_max = 11;

   constexpr int n_points = 400;                    // number of points used in range

   constexpr int x_scale = 30;                       // scaling factors
   constexpr int y_scale = 30;

   Simple_window win {Point{100,100},xmax,ymax,"Function Graphs"};

   //plots
   /*
   Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
   Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
   Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};

   win.attach(s);
   win.attach(s2);
   win.attach(s3);
   win.wait_for_button();
    */

   /*
   //labels
   Text ts {Point{100,y_orig-40},"one"};
   Text ts2 {Point{100,y_orig+y_orig/2-20},"0.5*x"};
   Text ts3 {Point{x_orig-100,20},"x*x"};
   win.set_label("Function graphing: label functions");
   win.attach(ts);
   win.attach(ts2);
   win.attach(ts3);
   win.wait_for_button();
   */


   //axis
   constexpr int xlength = xmax-40; // make the axis a bit smaller than the window
   constexpr int ylength = ymax-40;


   Axis x {Axis::x,Point{20,y_orig}, xlength, xlength/x_scale, "1 == 20 pixels"};
   Axis y {Axis::y,Point{x_orig, ylength+20}, ylength, ylength/y_scale, "1 == 20 pixels"};
   x.set_color(Color::red);
   y.set_color(Color::red);
   win.attach(x);
   win.attach(y);
   win.wait_for_button();

   //plot graph
   Function line_one {one, r_min, r_max, orig, 400, 20, 20};
   win.attach(line_one);
      win.wait_for_button();

   Function line_slope{slope, r_min, r_max, orig, 400, 20, 20};
    win.attach(line_slope);
   win.wait_for_button();

    Function line_square {square, r_min, r_max, orig, 400, 20,20};
   win.attach(line_square);
    win.wait_for_button();

   //cosine

   Function s4 {dcos,r_min,r_max,orig,400,30,30};
   s4.set_color(Color::blue);

   Function s5 {sloping_cos, r_min,r_max,orig,400,30,30};
   s5.set_color(Color::green);
/*
   x.label.move(-160,0);
   x.notches.set_color(Color::dark_red);

   win.attach(s4);
   win.attach(s5);
   win.wait_for_button();
    */

   //Function s5 {[](double x) −> double { return cos(x)+slope(x); },r_min,r_max,orig,400,30,30};
   // this contains a lamda function.
   //[] lambda introducer (used to give access to local variables)
   //(argument list) -> return type (suffix notation)
   //{function body}
   /*

   for (int n = 0; n<50; ++n) {
       ostringstream ss;
       ss << "exp approximation; n==" << n ;
       win.set_label(ss.str());

       // get next approximation:
       Function e {[n](double x) { return exp_n(x,n); },r_min,r_max,orig,200,x_scale,y_scale};

       win.attach(e);
       win.wait_for_button();
       win.detach(e);
       //this starts breaking for n == 15 and completely breaks after n== 19 crashes after n== 50
   }

    */
}
