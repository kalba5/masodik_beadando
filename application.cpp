#include "application.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include "iostream"

using namespace genv;
Application::Application(int width, int height)
{
    gout.open(width, height);
}
void Application::register_widget(Widget* widget)
{
    widgets.push_back(widget);
    std::cout << "itt pusholodik bele" << std::endl;        ///majd torolni kell
}
void Application::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i=0; i < widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                        focus = i;
                        widgets[i]->setColorSelected();
                }
            }
        }
        else if (ev.type == ev_key && ev.keycode == key_enter)
        {
            action("mentes");
            focus = -1;
        }


        if (focus != -1)
        {
            widgets[focus]->handle(ev);
        }


        for (size_t i=0; i<widgets.size(); i++)             //a nem kijelolt widgetek keretenek a szinet visszarakja basicre
        {
            if (i != focus)
            {
                widgets[i]->setColorBasic();
            }
        }

        for (Widget* w : widgets)                           //kirajzolja a widgeteket
        {
            w->draw();
        }

        gout << refresh;
    }
}
