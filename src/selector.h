#include "globals.h"

class Selector : public Drawable
{
private:
    bool _active;
    RectangleShape _shape;

public:
    Selector();
    ~Selector();

    void Start(const float & x, const float & y);
    void Tick(const float & x, const float & y);
    FloatRect Release();

    void draw(RenderTarget& target, RenderStates states) const override
    {
        if(_active) {
            target.draw(_shape);
        }
    }
};