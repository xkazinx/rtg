#include "unit.h"

Unit::Unit(TilePos pos) : _destination(pos), _shape(10.f) {
        _shape.setPosition(pos);
        _shape.setFillColor(sf::Color::Red);
    }

Unit::~Unit() {}

void Unit::Tick() 
{
    auto & pos = GetPos();
    if(_destination.x != pos.x) 
    {
        float x = _destination.x - pos.x;
        _shape.move((x/abs(x)), 0);
    }

    if(_destination.y != pos.y) 
    {
        float y = _destination.y - pos.y;
        _shape.move(0, (y/abs(y)));
    }
}