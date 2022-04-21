#ifndef SZAMBEALLIT_HPP
#define SZAMBEALLIT_HPP

#include "graphics.hpp"
#include "widget.hpp"

class Szambeallit : public Widget
{
    int _value;
    int red=255;
    int blue=0;
public:
    Szambeallit(Application* parent, int x, int y, int sx, int sy);
    int getValue();
    int gombFolott(int, int);
    virtual void draw();
    virtual void handle(genv::event ev);

};

#endif // SZAMBEALLIT_HPP
