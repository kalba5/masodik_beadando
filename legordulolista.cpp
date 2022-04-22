#include "legordulolista.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

LegorduloLista::LegorduloLista(Application* parent,  int x, int y, int sx, int sy, vector<string> items)
                :Widget(parent, x, y, sx, sy)
{
    _items = items;
    maxItemPiece = 5;
    _items.insert(_items.begin(), "--Select an item--");
    actualItem = _items[0];
    rNegyzet = 255;
    gNegyzet = 255;
    bNegyzet = 255;
}

void LegorduloLista::draw()
{
    gout << color(rFrame, gFrame, bFrame) << move_to(_x, _y) << box(_size_x, _size_y);      //keret
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);     //hatter
    gout << color(0,0,0) << move_to(_x+4, _y+(_size_y/2)+ gout.cascent()/2 -1) << text(actualItem);     //szoveg
    gout << color(rNegyzet, gNegyzet, bNegyzet) << move_to(_x+_size_x-22, _y+2) << box(20, _y-4);       //haromszog hatter

    for (size_t i=0; i < 12; i++)                                                                   //le haromszog
    {
        gout << color(0,0,0) << move_to(_x+_size_x-18+i, _y+8) << line_to(_x+_size_x-12, _y+_size_y-10);
    }
}

bool LegorduloLista::gombFolott(int mouse_x, int mouse_y)
{
    if (mouse_x >= _x+_size_x-22 && mouse_x <= _x+_size_x-2 && mouse_y >= _y+2 && mouse_y <= _y+_size_y-2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LegorduloLista::handle(event ev)
{
    if (ev.type == ev_mouse && gombFolott(ev.pos_x, ev.pos_y))
    {
        std::cout << "gomb folott" << std::endl;
        rNegyzet = 166;
        gNegyzet = 166;
        bNegyzet = 166;
    }
}
