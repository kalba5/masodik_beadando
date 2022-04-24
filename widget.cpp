#include "widget.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
Widget::Widget(Application* parent, int x, int y, int sx, int sy) :
          _x(x), _y(y), _size_x(sx), _size_y(sy), _parent(parent)
{
    rFrame=255;
    gFrame=0;
    bFrame=0;
    _parent->register_widget(this);
}
bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::setColorBasic()
{
    rFrame=255;
    gFrame=0;
    bFrame=0;
}

void Widget::setColorSelected()
{
    rFrame=0;
    gFrame=0;
    bFrame=255;
}
