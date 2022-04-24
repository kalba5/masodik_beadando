#include "szambeallit.hpp"
#include "graphics.hpp"
#include "iostream"
#include <sstream>

using namespace genv;
Szambeallit::Szambeallit(Application* parent,  int x, int y, int sx, int sy, int lL, int uL)        //lL: lowerLimit, uL: upperLimit
    :Widget(parent, x, y, sx, sy)
{
    if (lL <= 0 && uL >= 0)
    {
        _value = 0;
    }
    else
    {
        _value = lL;
    }

    upperLimit = uL;
    lowerLimit = lL;

    rEgerFel =253;
    gEgerFel =239;
    bEgerFel =59;
    rEgerLe =155;
    gEgerLe =203;
    bEgerLe =227;
}

void Szambeallit::draw()
{
    gout << move_to(_x, _y) << color(rFrame,gFrame,bFrame) << box(_size_x, _size_y);                //keret
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);                 //hatter
    gout << color(rEgerFel, gEgerFel, bEgerFel) << move_to(_x+_size_x-22,_y+2) << box(20,(_size_y/2) -2);          //fel gomb hatter
    gout << color(rEgerLe, gEgerLe, bEgerLe) << move_to(_x+_size_x-22,_y+(_size_y/2)) << box(20,(_size_y/2) -2);  //le gomb hatter

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

    gout << color(0,0,0) << move_to(_x+4, _y+(_size_y/2)+ gout.cascent()/2 -1) << text(ss.str());     //szoveg kirajzol
}

int Szambeallit::gombFolott(int mouse_x, int mouse_y)
{
    if (mouse_x >= _x+_size_x-22 && mouse_x <= _x+_size_x-2 && mouse_y >= _y+2 && mouse_y <= _y+(_size_y/2))     //FEL GOMB
    {
        return 1;
    }
    else if (mouse_x >= _x+_size_x-22 && mouse_x <= _x+_size_x-2 && mouse_y > _y+(_size_y/2) && mouse_y <= _y+_size_y-2)     //LE GOMB
    {
        return 2;
    }
    else        //NEM GOMB
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
    //gomb kezeles
    if (gombFolott(ev.pos_x,ev.pos_y)==1 && ev.type == ev_mouse)
    {
        rEgerFel =253;
        gEgerFel =253;
        bEgerFel =150;
    }
    else
    {
        rEgerFel =253;
        gEgerFel =239;
        bEgerFel =59;
    }

    if (gombFolott(ev.pos_x,ev.pos_y)==2 && ev.type == ev_mouse)
    {
        rEgerLe =177;
        gEgerLe =217;
        bEgerLe =236;
    }
    else
    {
        rEgerLe =155;
        gEgerLe =203;
        bEgerLe =227;
    }



    if (gombFolott(ev.pos_x,ev.pos_y)==1 && ev.button == btn_left)      //FEL GOMB
    {
        //std::cout << "FEL GOMB" << std::endl;
        std::stringstream ss;
        int tmpValue = _value+1;
        ss << tmpValue;

        if (gout.twidth(ss.str()) >= _size_x-26)
        {
            std::cout << "Tul szeles lenne a szam, nem ferne ki a dobozba" << std::endl;
        }

        if (_value +1 <= upperLimit && gout.twidth(ss.str()) <= _size_x-26)
        {
            _value++;
        }
    }
    else if (gombFolott(ev.pos_x,ev.pos_y)==2 && ev.button == btn_left)     //LE GOMB
    {
        //std::cout << "LE GOMB" << std::endl;
        std::stringstream ss;
        int tmpValue = _value-1;
        ss << tmpValue;

        if (gout.twidth(ss.str()) >= _size_x-26)
        {
            std::cout << "Tul szeles lenne a szam, nem ferne ki a dobozba" << std::endl;
        }

        if (_value -1 >= lowerLimit && gout.twidth(ss.str()) <= _size_x-26)
        {
            _value--;
        }
    }


    if (ev.type == ev_key && ev.keycode == 82)      //FEL NYIL BILLENTYUGOMB
    {
        std::stringstream ss;
        int tmpValue = _value+1;
        ss << tmpValue;

        if (gout.twidth(ss.str()) >= _size_x-26)
        {
            std::cout << "Tul szeles lenne a szam, nem ferne ki a dobozba" << std::endl;
        }

        if (_value +1 <= upperLimit && gout.twidth(ss.str()) <= _size_x-26)
        {
            _value++;
        }
    }
    else if (ev.type == ev_key && ev.keycode == 81)       //LE NYIL BILLENTYUGOMB
    {
        std::stringstream ss;
        int tmpValue = _value-1;
        ss << tmpValue;

        if (gout.twidth(ss.str()) >= _size_x-26)
        {
            std::cout << "Tul szeles lenne a szam, nem ferne ki a dobozba" << std::endl;
        }

        if (_value -1 >= lowerLimit && gout.twidth(ss.str()) <= _size_x-26)
        {
            _value--;
        }
    }
    else if (ev.type == ev_key && ev.keycode == 75)       //PAGEUP BILLENTYUGOMB
    {
        std::stringstream ss;
        int tmpValue = _value+10;
        ss << tmpValue;

        if (gout.twidth(ss.str()) >= _size_x-26)
        {
            std::cout << "Tul szeles lenne a szam, nem ferne ki a dobozba" << std::endl;
        }

        if (_value +10 <= upperLimit && gout.twidth(ss.str()) <= _size_x-26)
        {
            _value = _value+10;
        }
    }
    else if (ev.type == ev_key && ev.keycode == 78)       //PAGEDOWN BILLENTYUGOMB
    {
        std::stringstream ss;
        int tmpValue = _value-10;
        ss << tmpValue;

        if (gout.twidth(ss.str()) >= _size_x-26)
        {
            std::cout << "Tul szeles lenne a szam, nem ferne ki a dobozba" << std::endl;
        }

        if (_value -10 >= lowerLimit && gout.twidth(ss.str()) <= _size_x-26)
        {
            _value = _value-10;
        }
    }
}


