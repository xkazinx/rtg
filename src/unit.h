#include "globals.h"

class Unit : public Drawable
{
private:
    CircleShape _shape;
    UnitId _id;
    Vector2f _destination;
    bool _selected;

public:
    using Id = UnitId;

    Unit(TilePos pos);
    ~Unit();

    auto & GetId() { return _id; }
    auto & GetId() const { return _id; }
    
    auto & GetShape() { return _shape; }
    auto & GetShape() const { return _shape; }

    auto & GetSelected() const { return _selected; }
    void SetSelected(const bool & value) {
        _selected = value;
        _shape.setFillColor(_selected ? sf::Color::Blue : sf::Color::Red);
    }


    void SetDestination(const Vector2f & pos)
    {
        _destination = pos;
    }


    auto & GetPos() { return GetShape().getPosition(); }
    auto & GetPos() const { return GetShape().getPosition(); }

    auto Is(const Id & id) const { return GetId() == id; }

    virtual void draw(RenderTarget& target, RenderStates states) const
    {
        target.draw(_shape);
    }

    void Tick();
};