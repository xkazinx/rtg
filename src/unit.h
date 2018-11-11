#include "globals.h"

class Unit : public Drawable
{
private:
    CircleShape _shape;
    UnitId _id;
    Vector2f _destination;

public:
    using Id = UnitId;

    Unit(TilePos pos);
    ~Unit();

    auto & GetId() { return _id; }
    auto & GetId() const { return _id; }
    
    auto & GetShape() { return _shape; }
    auto & GetShape() const { return _shape; }

    auto & GetPos() { return GetShape().getPosition(); }
    auto & GetPos() const { return GetShape().getPosition(); }

    auto Is(const Id & id) const { return GetId() == id; }

    virtual void draw(RenderTarget& target, RenderStates states) const
    {
        target.draw(_shape);
    }

    void SetDestination(const Vector2f & pos);

    void Tick();
};