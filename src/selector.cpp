#include "selector.h"

Selector::Selector() : _active(false)
{
    _shape.setFillColor(sf::Color::Transparent);
    _shape.setOutlineThickness(1.f);
    _shape.setOutlineColor(sf::Color::White);
}

Selector::~Selector() 
{

}

void Selector::Start(const float & x, const float & y)
{
    _active = true;
    _shape.setSize(Vector2f(0, 0));
    _shape.setPosition(x, y);
}

void Selector::Tick(const float & x, const float & y)
{
    if(!_active) {
        return;
    }
    
    auto b = _shape.getPosition();

    auto sz = Vector2f(x - b.x + 1, y - b.y + 1);

/*
    TODO: Limit to bounds
    cout << b.x << "/" << b.y << "//" << sz.x << "/" << sz.y << endl;

    if (sz.x > kResX) sz.x = kResX;
    if (sz.y > kResY) sz.y = kResY;

    if (b.x - sz.x <= 0) sz.x = 0;
    if (b.y - sz.y <= 0) sz.y = 0;
*/
    _shape.setSize(sz);
}

FloatRect Selector::Release()
{
    _active = false;

    // Increase one to trigger collision
    auto bounds = _shape.getGlobalBounds();
    bounds.width++;
    bounds.height++;
    
    return bounds;;
}