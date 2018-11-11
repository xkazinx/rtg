#ifndef SCENE_H
#define SCENE_H

#include "globals.h"

class Scene : public Drawable {
public:
    Scene();
    ~Scene();

    virtual void Initialize() = 0;
    virtual void Render(RenderTarget & target, RenderStates & states) const = 0;
    virtual void HandleEvents(Event & event) = 0;
    virtual void Tick() = 0;
    
    void draw(RenderTarget& target, RenderStates states) const override
    {
        Render(target, states);
    }
};

#endif