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
    actualItem = _items[3];
    rNegyzet = 255;
    gNegyzet = 255;
    bNegyzet = 255;
    open = false;
}

void LegorduloLista::draw()
{
    gout << color(rFrame, gFrame, bFrame) << move_to(_x, _y) << box(_size_x, _size_y);      //keret
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);     //hatter
    gout << color(0,0,0) << move_to(_x+4, _y+(_size_y/2)+ gout.cascent()/2 -1) << text(actualItem);     //szoveg
    gout << color(rNegyzet, gNegyzet, bNegyzet) << move_to(_x+_size_x-22, _y+2) << box(20, _size_y-4);       //haromszog hatter

    for (size_t i=0; i < 12; i++)                                                                   //le haromszog
    {
        gout << color(0,0,0) << move_to(_x+_size_x-18+i, _y+8) << line_to(_x+_size_x-12, _y+_size_y-10);
    }

    if (open)       //legordullo lista kirajzolas
    {
        if (_items.size() < maxItemPiece)
        {
            for (size_t i=0; i < _items.size(); i++)
            {
                gout << color(255,255,255) << move_to(_x, _y+_size_y + _size_y * i) << box(_size_x,_size_y);    //hatter
                gout << color(0,0,0) << move_to(_x +4, _y+_size_y + _size_y * (i+1) + gout.cascent()/2 -1 - _size_y/2) << text(_items[i]);  //szoveg
            }
        }
        else
        {
            for (int i=0; i < maxItemPiece; i++)
            {
                gout << color(255,255,255) << move_to(_x, _y+_size_y + _size_y * i) << box(_size_x,_size_y);        //hatter
                gout << color(0,0,0) << move_to(_x +4, _y+_size_y + _size_y * (i+1) + gout.cascent()/2 -1 - _size_y/2) << text(_items[i]);    //szoveg
            }
        }
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

int LegorduloLista::itemFelett(int mouse_x, int mouse_y)
{
    unsigned long long tmp=-1;
    if (_items.size() < maxItemPiece)
    {
        for (size_t i=0; i < _items.size(); i++)
        {
            if (mouse_x >= _x && mouse_x < _x+_size_x && mouse_y >= _y + _size_y*(i+1) && mouse_y < _y + _size_y*(i+1) + _size_y && open)
            {
                 tmp = i+1;
            }
        }
    }
    else
    {
        for (int i=0; i < maxItemPiece; i++)
        {
            if (mouse_x >= _x && mouse_x < _x+_size_x && mouse_y >= _y + _size_y*(i+1) && mouse_y < _y + _size_y*(i+1) + _size_y && open)
            {
                 tmp = i+1;
            }
        }
    }

    return tmp;

}


void LegorduloLista::handle(event ev)
{
    if (ev.type == ev_mouse && gombFolott(ev.pos_x, ev.pos_y))
    {
        std::cout << "gomb folott" << std::endl;
        rNegyzet = 190;
        gNegyzet = 190;
        bNegyzet = 190;
    }
    else
    {
        rNegyzet = 255;
        gNegyzet = 255;
        bNegyzet = 255;
    }

    if (ev.type == ev_mouse && gombFolott(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        open = true;
    }
    else if (open && ev.type == ev_mouse && ev.button == btn_left)
    {
        open = false;
    }


    if (ev.type == ev_mouse && itemFelett(ev.pos_x,ev.pos_y))
    {
        cout << "e folott:" << itemFelett(ev.pos_x, ev.pos_y) << endl;
        if (itemFelett(ev.pos_x,ev.pos_y) >= 0)
        {
            cout << "az elem:" << _items[itemFelett(ev.pos_x, ev.pos_y) -1] << endl;
        }
    }
}
