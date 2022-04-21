#include "szambeallit.hpp"
#include "graphics.hpp"
#include "iostream"
#include <sstream>

using namespace genv;
Szambeallit::Szambeallit(Application* parent,  int x, int y, int sx, int sy)
    :Widget(parent, x, y, sx, sy)
{
    _value = 0;
}

void Szambeallit::draw()
{
    gout << move_to(_x, _y) << color(rFrame,gFrame,bFrame) << box(_size_x, _size_y);                //keret
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

    std::stringstream ss;                   //_value atalakitas stringre
    ss << _value;

    gout << color(0,0,0) << move_to(_x+4, _y+(_size_y/2)) << text(ss.str());
}

int Szambeallit::gombFolott(int mouse_x, int mouse_y)
{
    if (mouse_x > _x+_size_x-22 && mouse_x < _x+_size_x-2 && mouse_y > _y+2 && mouse_y < _y+(_size_y/2)-2)
    {
        return 1;
    }
    else if (mouse_x > _x+_size_x-22 && mouse_x < _x+_size_x-2 && mouse_y > _y+(_size_y/2)+2 && mouse_y < _y+_size_y-2)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int Szambeallit::getValue()
{
    return _value;
}

void Szambeallit::handle(event ev)
{
    /*if (is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        std::cout << "itt vagyok" << std::endl;                                     ///majd torolni kell
        red = 0;
        blue = 255;
    }
    else if(!is_selected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        red = 255;
        blue = 0;
    }*/

    //gomb kezeles
    if (gombFolott(ev.pos_x,ev.pos_y)==1 && ev.button == btn_left)
    {
        std::cout << "FEL GOMB" << std::endl;
        _value++;
    }
    else if (gombFolott(ev.pos_x,ev.pos_y)==2 && ev.button == btn_left)
    {
        std::cout << "LE GOMB" << std::endl;
        _value--;
    }
    else if (gombFolott(ev.pos_x,ev.pos_y)==-1 && ev.button == btn_left)
    {
        std::cout << "NEM GOMB" << std::endl;
    }

}


