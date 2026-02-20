#include "PPP/Simple_window.h"
#include "PPP/Graph.h"

using namespace Graph_lib;

int main()
//  draw two lines
{
    Application app;
    constexpr Point x {100,100};


    Simple_window win {x,800,1000,"grid"};

    int x_size = win.x_max();                                     // get the size of our window
    int y_size = win.y_max();
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
        grid.add(Point{x,0},Point{x,y_size});         // vertical line
    for (int y = y_grid; y<y_size; y+=y_grid)
        grid.add(Point{0,y},Point{x_size,y});

    grid.set_style(Line_style::dot);
    grid.set_color(Color::dark_green);

    win.attach(grid);
    win.wait_for_button();    // display!


}
/*
[1] Make an 800-by-1000 Simple_window.

[2] Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).

[3] Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).

[4] Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it on the grid (each image covering four squares
 If you can’t find an image that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of a larger image. Don’t obscure the red squares.

[5] Add a 100-by-100 image. Have it move around from square to square when you click the “Next” button. Just put wait_for_button() in a
loop with some code that picks a new square for your image.
*/
