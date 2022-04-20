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
    Szambeallit* sz;
public:
    MyApp(int width, int height): Application(width, height)
    {
        sz = new Szambeallit(this, 40, 40, 200, 30);
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
