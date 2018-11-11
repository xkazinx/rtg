#include "gamescene.h"
#include "unitmgr.h"
#include "unit.h"

void GameScene::Initialize() 
{
    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 10.f, 10.f }));
    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 20.f, 30.f }));

    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 60.f, 70.f }));
    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 30.f, 40.f }));

    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 50.f, 80.f }));
    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 100.f, 90.f }));

    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 120.f, 440.f }));
    g::unit_mgr->Add(make_unique<Unit>(TilePos{ 450.f, 230.f }));
}

void GameScene::HandleEvents(Event & event)
{
    switch(event.type) {
        case Event::MouseButtonReleased:
        case Event::MouseButtonPressed:
        {
            auto up = event.type == Event::MouseButtonReleased;

            auto & ev = event.mouseButton;
            if (ev.button == Mouse::Button::Left) {
                if(!up) {
                    _selector.Start(ev.x, ev.y);
                }
                else {
                    g::unit_mgr->Select(_selector.Release());
                }
            }
            else if (ev.button == Mouse::Button::Right) {
                if(!up) {
                    g::unit_mgr->Move(Vector2f(ev.x, ev.y));               
                }
            }

            break;
        }

    case Event::MouseMoved:
        _selector.Tick(event.mouseMove.x, event.mouseMove.y);
        break;
    }    
}

void GameScene::Render(RenderTarget & target, RenderStates & states) const
{
    for(const auto & unit : g::unit_mgr->GetList()) {
        target.draw(*unit.get());
    }

    target.draw(_selector);
}

void GameScene::Tick()
{
    for(auto & unit : g::unit_mgr->GetList()) {
        unit->Tick();
    }
}