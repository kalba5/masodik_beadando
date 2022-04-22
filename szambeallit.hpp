#ifndef SZAMBEALLIT_HPP
#define SZAMBEALLIT_HPP

#include "graphics.hpp"
#include "widget.hpp"

class Szambeallit : public Widget
{
    int _value;
    int upperLimit, lowerLimit;
public:
    Szambeallit(Application* parent, int x, int y, int sx, int sy, int lL, int uL);
    int getValue();
    int gombFolott(int, int);
    virtual void draw();
    virtual void handle(genv::event ev);

};

#endif // SZAMBEALLIT_HPP
