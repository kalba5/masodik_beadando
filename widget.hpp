#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "application.hpp"
#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    Application * _parent;
public:
    Widget(Application*, int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGET_HPP
