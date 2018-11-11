#include "globals.h"
#include "scene.h"
#include "selector.h"

class GameScene : public Scene
{
private:
    Selector _selector;
    
public:
    GameScene() : Scene() {}
    ~GameScene() {}

    void Initialize() override;
    void Render(RenderTarget & target, RenderStates & states) const override;
    void HandleEvents(Event & event) override;
    void Tick() override;
};