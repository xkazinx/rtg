#include "scenemgr.h"
#include "scene.h"
#include "gamescene.h"

SceneMgr::SceneMgr() 
{
    //At(ID::Main) = make_unique<MainScene>();
    At(ID::Game) = make_unique<GameScene>();

    Set(kDefaultID);
}

SceneMgr::~SceneMgr() 
{

}

void SceneMgr::Set(ID id) 
{
    GetID() = id;

    Get()->Initialize();
}

void SceneMgr::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(*Get());
}

void SceneMgr::HandleEvents(Event & event) 
{
    Get()->HandleEvents(event);
}

void SceneMgr::Tick()
{
    Get()->Tick();
}