#include "unit.h"

Unit::Unit(TilePos pos) : _shape(10.f), _destination(pos)
{
	_shape.setPosition(pos);
	_shape.setFillColor(sf::Color::Red);
}

void Unit::SetSelected(const bool value)
{
	_selected = value;
	_shape.setFillColor(_selected ? sf::Color::Blue : sf::Color::Red);
}

bool Unit::Tick()
{
	// A pixel per axis per tick, the last step only what's left: a whole step past a
	// destination between pixels would shake around it for ever
	const Vector2f left = _destination - _shape.getPosition();
	_shape.move({ std::clamp(left.x, -1.f, 1.f), std::clamp(left.y, -1.f, 1.f) });
	return _shape.getPosition() == _destination;
}
