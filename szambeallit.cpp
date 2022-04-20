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
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,0,0) << box(_size_x-4, _size_y-4);
}

void Szambeallit::handle(event ev)
{
    if (is_selected(ev.pos_x, ev.pos_y))
    {
        std::cout << "itt vagyok" << std::endl;                                     ///majd torolni kell
    }
}

int Szambeallit::getValue()
{
    return _value;
}
