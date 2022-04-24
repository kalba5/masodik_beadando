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
    //ofstream kifajl;
    Szambeallit* sz1;
    Szambeallit* sz2;
    //Szambeallit* sz3;
    LegorduloLista* ll1;
    vector<string> vll1 = {"Ford mustang (1967)", "Audi rs7", "Pagani Zonda", "Tesla model x", "Porsche 911", "Bugatti Chiron", "LaFerrari"};
    LegorduloLista* ll2;
    vector<string> vll2 = {"Almos", "Elod", "Ond", "Kond", "Tas", "Huba", "Tohotom"};
public:
    App(int width, int height): Application(width, height)
    {
        sz1 = new Szambeallit(this, 40, 40, 200, 35, -10, 10);    //minimum 36-nak kell lennie a size_x -nek, hogy legalabb 1 karakter kiferjen
        sz2 = new Szambeallit(this, 310, 40, 100, 30, -100, 100);   //es minimum 20-nak kell lennie a size_y -nak
        ll1 = new LegorduloLista(this, 40, 250, 250, 35, 5, vll1);
        ll2 = new LegorduloLista(this, 310, 250, 200,25, 9, vll2);

    }

    /*void fajlmegnyit()
    {
        kifajl.open("mentes.txt");
    }*/

    void action(string id)
    {
        if (id == "mentes")
        {
            /*if (!kifajl.is_open())
            {
                fajlmegnyit();
            }*/
            std::cout << "enter" << std::endl;
            kifajl << "sz1: " << sz1->getValue() << endl;
            kifajl << "sz2: " << sz2->getValue() << endl;
            kifajl << "ll1: " << ll1->getActualItem() << endl;
            kifajl << "ll2: " << ll2->getActualItem() << endl;
            kifajl << "Mentes vege!" << endl;
        }
    }
};


int main()
{
    App appl(600,600);
    ofstream kifajl("mentes.txt");
    gout << refresh;
    appl.event_loop();
    return 0;
}
