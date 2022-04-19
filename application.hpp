#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <string>
#include <vector>

class Widget;
class Application
{
protected:
    std::vector<Widget*> widgets;
public:
    Application(int, int);
    void register_widget(Widget*);
    void event_loop();
    virtual void action(std::string) = 0;
};

#endif // APPLICATION_HPP
