#include "unit.h"

Unit::Unit(TilePos pos) : _destination(pos), _shape(10.f) {
        _shape.setPosition(pos);
        _shape.setFillColor(sf::Color::Red);
    }

Unit::~Unit() {}

void Unit::SetDestination(const Vector2f & pos)
{
    cout << "Set dest" << endl;
    _destination = pos;
}

void Unit::Tick() 
{
    auto & pos = GetPos();
    if(_destination.x != pos.x) 
    {
        float x = _destination.x - pos.x;
        _shape.move(((x/abs(x))) * 1, 0);
    }

    if(_destination.y != pos.y) 
    {
        float y = _destination.y - pos.y;
        _shape.move(0, ((y/abs(y))) * 1);
    }
}