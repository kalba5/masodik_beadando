#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;

class App: public Application
{
private:
    Szambeallit* sz1;
    Szambeallit* sz2;
    Szambeallit* sz3;
public:
    App(int width, int height): Application(width, height)
    {
        sz1 = new Szambeallit(this, 40, 40, 200, 30, 5, 10);
        sz2 = new Szambeallit(this, 40, 100, 100, 20, -1000, 20);   //minimum 36-nak kell lennie a size_x -nek, hogy legalabb 1 karakter kiferjen
        sz3 = new Szambeallit(this, 40, 250, 200, 200, -5, 1111);   //es minimum 20-nak kell lennie a size_y -nak
    }

    void action(string id)
    {
        if (id == "mentes")
            std::cout << "enter" << std::endl;
    }
};


int main()
{
    App app(600,600);
    gout << refresh;
    app.event_loop();
    return 0;
}
