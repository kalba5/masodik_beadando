#include "szambeallit.hpp"
#include "graphics.hpp"
#include "iostream"

using namespace genv;
Szambeallit::Szambeallit(Application* parent,  int x, int y, int sx, int sy)
    :Widget(parent, x, y, sx, sy)
{

}



void Szambeallit::draw()
{
    gout << move_to(_x, _y) << color(red,0,blue) << box(_size_x, _size_y);                          //keret
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);                 //hatter
    gout << color(166, 166, 166) << move_to(_x+_size_x-22,_y+2) << box(20,(_size_y/2) -2);          //fel gomb hatter
    gout << color(166, 0, 166) << move_to(_x+_size_x-22,_y+(_size_y/2)) << box(20,(_size_y/2) -2);  //le gomb hatter

    for (size_t i=0; i < 12; i++)                                                                   //fel haromszog
    {
        gout << color(255,255,255) << move_to(_x+_size_x-18+i,_y+(_size_y/2)-4) << line_to(_x+_size_x-12,_y+6);
    }

    for (size_t i=0; i < 12; i++)                                                                   //le haromszog
    {
        gout << color(255,255,255) << move_to(_x+_size_x-18+i,_y+(_size_y/2)+4) << line_to(_x+_size_x-12,_y-6+_size_y);
    }

}

void Szambeallit::handle(event ev)
{
    if (is_selected(ev.pos_x, ev.pos_y))
    {
        std::cout << "itt vagyok" << std::endl;                                     ///majd torolni kell
        red = 0;
        blue = 255;
    }
    else if(!is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        red = 255;
        blue = 0;
    }
}

int Szambeallit::getValue()
{
    return _value;
}
