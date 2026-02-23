#include "PPP/Simple_window.h"
#include "PPP/Graph.h"

using namespace Graph_lib;

int main()
//  draw two lines
{
    Application app;
    constexpr Point x {100,100};


    Simple_window win {x,800,1000,"grid"};

    const int x_size = win.x_max();
    int y_size = win.y_max();
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
        grid.add(Point{x,0},Point{x,y_size});         // vertical line
    for (int y = y_grid; y<y_size; y+=y_grid)
        grid.add(Point{0,y},Point{x_size,y});

    grid.set_style(Line_style{Line_style::dot, 3});
    grid.set_color(Color::dark_green);


    win.attach(grid);
    win.wait_for_button();    // display!

    Vector_ref<Rectangle> vr;

    for (int i = 0; i < x_size; i+=100){
            vr.push_back(make_unique<Rectangle>(Point{i, i}, 100, 100));
            vr[vr.size() - 1].set_fill_color(Color::red);
            win.attach(vr[vr.size() - 1]);
            win.wait_for_button();
    }



    Vector_ref<Rectangle> image_200;
    int offsets[2][2] = { {0, 200}, {200, 0} };

    for(int j = 0; j < 2; ++j){
        for (int i = 0; i < x_size; i+=200){
            int current_x = i + offsets[j][0];
            int current_y = i + offsets[j][1];

            image_200.push_back(make_unique<Rectangle>(Point{current_x, current_y}, 200, 200));
            image_200[image_200.size() - 1].set_fill_color(Color::blue);
            win.attach(image_200[image_200.size() - 1]);

            win.wait_for_button();
        }
    }
    for (int j = 0; j < y_size; j+=100){
        for (int i = 0; i < x_size; i+=100){
            Rectangle rect_ii {Point{i,j},100,100};
            rect_ii.set_fill_color(Color::white);
            win.attach(rect_ii);
            win.wait_for_button();
        }
    }
}
