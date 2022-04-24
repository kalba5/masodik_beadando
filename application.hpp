#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Widget;                                   //jelezzuk, hogy majd kesobb lesz egy class Widget
class Application
{
protected:
    std::vector<Widget*> widgets;               //egy Widget* tipusu vector amiben eltaroljuk a hasznalt widgeteket
    std::ofstream kifajl;
public:
    Application(int, int);                      //konstruktor a hatter mereteinek
    void register_widget(Widget*);              //bele pusholja a widgeteket a widget vektorba
    void event_loop();
    virtual void action(std::string) = 0;
};

#endif // APPLICATION_HPP
