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
}
void Application::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button == btn_left) {
            for (size_t i=0; i < widgets.size(); i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        else if (ev.type == ev_key && ev.keycode == key_enter)
        {
            action("mentes");
        }
        if (focus != -1) {
            widgets[focus]->handle(ev);

            //ha a hatterre kattint a focus visszaall -1 -re
            for (size_t i=0;i<widgets.size();i++) {
                if (!(widgets[i]->is_selected(ev.pos_x, ev.pos_y)) && ev.button == btn_left) {
                        focus = -1;
                }
            }

        }
        for (Widget* w : widgets)                           //kirajzolja a widgeteket
        {
            w->draw();
        }

        std::cout << focus << std::endl;                    ///majd ki kell venni
        gout << refresh;
    }
}
