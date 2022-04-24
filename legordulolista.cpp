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
    rEger = 255;
    gEger = 255;
    bEger = 255;
    open = false;
    egerItem = 0;
    eltolas = 0;
    felsoElem = eltolas;
    if (_items.size() < maxItemPiece)
    {
        alsoElem = _items.size()-1;
    }
    else
    {
        alsoElem = eltolas + maxItemPiece -1;
    }
}

void LegorduloLista::draw()
{
    if (kifer_e())
    {
        gout << color(rFrame, gFrame, bFrame) << move_to(_x, _y) << box(_size_x, _size_y);      //keret
        gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);     //hatter
        gout << color(0,0,0) << move_to(_x+4, _y+(_size_y/2)+ gout.cascent()/2 -1) << text(actualItem);     //szoveg
        gout << color(rEger, gEger, bEger) << move_to(_x+_size_x-22, _y+2) << box(20, _size_y-4);       //haromszog hatter



        if (_size_y < 25)
        {
            for (int i=0; i < 12; i++)                                                                   //le haromszog
            {
                gout << color(0,0,0) << move_to(_x+_size_x-18+i, _y+(_size_y/2)-6) << line_to(_x+_size_x-12, _y+(_size_y/2)+6);
            }
        }
        else if (_size_y > 35)
        {
            for (int i=0; i < 12; i++)                                                                   //le haromszog
            {
                gout << color(0,0,0) << move_to(_x+_size_x-18+i, _y+(_size_y/2)-10) << line_to(_x+_size_x-12, _y+(_size_y/2)+10);
            }
        }
        else
        {
            for (int i=0; i < 12; i++)                                                                   //le haromszog
            {
                gout << color(0,0,0) << move_to(_x+_size_x-18+i, _y+8) << line_to(_x+_size_x-12, _y+_size_y-10);
            }
        }





        if (open)       //legordullo lista kirajzolas
        {
            if (_items.size() < maxItemPiece)
            {
                for (size_t i=0; i < _items.size(); i++)
                {
                    if (i == egerItem)
                    {
                        rEger = 190;
                        gEger = 190;
                        bEger = 190;
                    }
                    /*else if(_items[i] == actualItem)
                    {
                        rEger = 153;
                        gEger = 204;
                        bEger = 255;
                    }*/
                    else
                    {
                        rEger = 255;
                        gEger = 255;
                        bEger = 255;
                    }

                    gout << color(rEger,gEger, bEger) << move_to(_x, _y+_size_y + _size_y * i) << box(_size_x,_size_y);    //hatter
                    gout << color(0,0,0) << move_to(_x +4, _y+_size_y + _size_y * (i+1) + gout.cascent()/2 -1 - _size_y/2)  //szoveg
                         << text(_items[i+ eltolas]);  //szoveg
                }
            }
            else
            {
                for (int i=0; i < maxItemPiece; i++)
                {
                    if (i == egerItem)
                    {
                        rEger = 190;
                        gEger = 190;
                        bEger = 190;
                    }
                    /*else if(_items[i] == actualItem)
                    {
                        rEger = 153;
                        gEger = 204;
                        bEger = 255;
                    }*/
                    else
                    {
                        rEger = 255;
                        gEger = 255;
                        bEger = 255;
                    }

                    gout << color(rEger,gEger, bEger) << move_to(_x, _y+_size_y + _size_y * i) << box(_size_x,_size_y);   //hatter
                    gout << color(0,0,0) << move_to(_x +4, _y+_size_y + _size_y * (i+1) + gout.cascent()/2 -1 - _size_y/2)  //szoveg
                         << text(_items[i+ eltolas]);    //szoveg
                }
            }
        }
    }
    else
    {
        cout << "ez a lista widget nem fer ki erre a hatterre" << endl;
    }
}


bool LegorduloLista::kifer_e()
{
    bool kifer=false;
    if (_items.size() < maxItemPiece)
    {
        for (size_t i=0; i < _items.size(); i++)
        {
            if (_y + _size_y*(i+1) < 600)
            {
                kifer = true;
            }
            else
            {
                kifer = false;
            }
        }
    }
    else
    {
        for (int i=0; i < maxItemPiece; i++)
        {
            if (_y + _size_y*(i+1) < 600)
            {
                kifer = true;
            }
            else
            {
                kifer = false;
            }
        }
    }

    return kifer;
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



///handle event
void LegorduloLista::handle(event ev)
{
    if (ev.type == ev_mouse && gombFolott(ev.pos_x, ev.pos_y))
    {
        //std::cout << "gomb folott" << std::endl;
        rEger = 190;
        gEger = 190;
        bEger = 190;
    }
    else
    {
        rEger = 255;
        gEger = 255;
        bEger = 255;
    }


    if (ev.type == ev_mouse && itemFelett(ev.pos_x,ev.pos_y))
    {
        //cout << "e folott:" << itemFelett(ev.pos_x, ev.pos_y) << endl;
        egerItem = itemFelett(ev.pos_x, ev.pos_y)-1;
        if (itemFelett(ev.pos_x,ev.pos_y) >= 1 && ev.button == btn_left && ev.type == ev_mouse)
        {
            //cout << "az elem:" << _items[itemFelett(ev.pos_x, ev.pos_y) -1] << endl;
            actualItem = _items[itemFelett(ev.pos_x, ev.pos_y) -1 + eltolas];

        }
    }


    if (ev.type == ev_mouse && gombFolott(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        open = !open;
    }
    else if (open && ev.type == ev_mouse && ev.button == btn_left)
    {
        open = false;
    }


    if (open && _items.size() > maxItemPiece && ev.type == ev_mouse)
    {
        if (ev.button == 5 && (alsoElem+1 <= _items.size()-1))    //LE GORGO
        {
            eltolas++;
            alsoElem++;
        }
        else if (ev.button == 4 && eltolas-1 >= 0)
        {
            eltolas--;
            alsoElem--;
        }
    }
    cout << "eltolas:" << eltolas << endl;
    cout << "alsoelem:" << alsoElem << endl;



}
