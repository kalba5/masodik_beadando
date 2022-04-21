#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;

class MyApp: public Application
{
private:
    Szambeallit* sz1;
    Szambeallit* sz2;
    Szambeallit* sz3;
public:
    MyApp(int width, int height): Application(width, height)
    {
        sz1 = new Szambeallit(this, 40, 40, 200, 30);
        sz2 = new Szambeallit(this, 40, 100, 40, 80);
        sz3 = new Szambeallit(this, 40, 250, 200, 100);
    }
    void action(string id)
    {
    }
};


int main()
{
    MyApp app(600,600);
    gout << refresh;
    app.event_loop();
    return 0;
}
