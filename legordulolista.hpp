#ifndef LEGORDULOLISTA_HPP
#define LEGORDULOLISTA_HPP

#include "widget.hpp"
#include <string>
#include <vector>

using namespace std;

class LegorduloLista : public Widget
{
    vector<string> _items;
    int maxItemPiece;      //ennyi darabot fog maximum megjelenite a legordult menuben egyszerre
    string actualItem;
    int rNegyzet, gNegyzet, bNegyzet;
    bool open;
public:
    LegorduloLista(Application* parent, int x, int y, int sx, int sy, vector<string> items);
    string getActualItem();
    bool gombFolott(int, int);
    //bool asd(int,int);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // LEGORDULOLISTA_HPP
