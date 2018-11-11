#include "globals.h"

class App
{
public:
    App();
    ~App();

    void Run();
    void InitializeWindow();

    void Tick();

    void HandleEvents();
    void Render();

    unique_ptr<RenderWindow> _window;
};