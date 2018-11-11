#include "app.h"
#include "unitmgr.h"
#include "unit.h"
#include "scenemgr.h"
#include "gamescene.h"

App::App() {
    g::Initialize();
    InitializeWindow();
}

App::~App() {
    g::Deinitialize();
}

void App::Run()
{
    Tick();
}

void App::InitializeWindow()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    _window = make_unique<RenderWindow>(VideoMode(kResX, kResY), "rtg", sf::Style::Default, settings);
    _window->setFramerateLimit(60);
}

void App::HandleEvents()
{
    Event event;
    while (_window->pollEvent(event))
    {
        if(event.type == Event::Closed) {
            _window->close();
        }
        else {
            g::scene_mgr->HandleEvents(event);
        }
    }
}

void App::Render()
{
    _window->clear(sf::Color::Black);
    _window->draw(*g::scene_mgr.get());
    _window->display();
}

void App::Tick()
{
    while (_window->isOpen())
    {
        HandleEvents();
        g::scene_mgr->Tick();
        Render();
    }
}