#include "selector.h"

Selector::Selector()
{
	_shape.setFillColor(sf::Color::Transparent);
	_shape.setOutlineThickness(1.f);
	_shape.setOutlineColor(sf::Color::White);
}

void Selector::Start(const Vector2f & pos)
{
	_active = true;
	_shape.setSize({ 0.f, 0.f });
	_shape.setPosition(pos);
}

void Selector::Tick(const Vector2f & pos)
{
	if (!_active)
		return;

	const Vector2f start = _shape.getPosition();
	_shape.setSize({ pos.x - start.x + 1.f, pos.y - start.y + 1.f });
}

FloatRect Selector::Release()
{
	_active = false;

	// Increase one to trigger collision
	FloatRect bounds = _shape.getGlobalBounds();
	bounds.size.x += 1.f;
	bounds.size.y += 1.f;

	return bounds;
}
