#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include "legordulolista.hpp"
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
    //Szambeallit* sz3;
    LegorduloLista* ll1;
    vector<string> vll1 = {"Ford mustang (1967)", "Audi rs7", "Pagani Zonda", "Tesla model x", "Porsche 911", "Bugatti Chiron", "LaFerrari"};
    LegorduloLista* ll2;
    vector<string> vll2 = {"Almos", "Elod", "Ond"};
public:
    App(int width, int height): Application(width, height)
    {
        sz1 = new Szambeallit(this, 40, 40, 200, 30, -10, 10);
        sz2 = new Szambeallit(this, 40, 100, 100, 20, -100, 100);   //minimum 36-nak kell lennie a size_x -nek, hogy legalabb 1 karakter kiferjen
        //sz3 = new Szambeallit(this, 40, 250, 200, 200, -100, 100);   //es minimum 20-nak kell lennie a size_y -nak
        ll1 = new LegorduloLista(this, 40, 470, 250, 60, vll1);
        ll2 = new LegorduloLista(this, 310, 250, 200,25, vll2);
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
