#ifndef LEGORDULOLISTA_HPP
#define LEGORDULOLISTA_HPP

#include "widget.hpp"
#include <string>
#include <vector>

using namespace std;

class LegorduloLista : public Widget
{
    vector<string> _items;
    int maxItemPiece;       //ennyi darabot fog maximum megjelenite a legordult menuben egyszerre
    string actualItem;      //ez az item van felul kiirva
    int egerItem;           //azt tarolja el, hogy ha le van gordulve a menu akkor az eger hanyadik elem folott van
    bool open;              //ha igaz akkor le van gordulve a lista
    int alsoElem;
    int felsoElem;
    int eltolas;            //ennyivel van eltolva a gorgotol a lista
    bool le;
    bool fel;
public:
    LegorduloLista(Application* parent, int x, int y, int sx, int sy, int maxdb, vector<string> items);
    string getActualItem();
    bool gombFolott(int, int);
    int itemFelett(int, int);
    bool kifer_e();
    virtual void draw();
    virtual void handle(genv::event ev);

};

#endif // LEGORDULOLISTA_HPP
