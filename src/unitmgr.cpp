#include "unitmgr.h"
#include "unit.h"

UnitMgr::~UnitMgr() {}

Unit * UnitMgr::FindById(const UnitId & id)
{
    return FindIf([&](auto & unit) { return unit->Is(id); });
}

void UnitMgr::Add(unique_ptr<Unit> && unit)
{
    unit->GetId() = ++_create_id;
    _list.emplace_back(std::move(unit));
}

void UnitMgr::Select(const FloatRect & area)
{
    _selected_list.clear();

    for(auto & unit : GetList()) 
    {
        auto & shape = unit->GetShape();
        unit->SetSelected(area.intersects(shape.getGlobalBounds()));
        if(unit->GetSelected()) {
            _selected_list.push_back(unit.get());
        }
    }
}

void UnitMgr::Move(const Vector2f & pos)
{
    auto rect = GetSelectedList().front()->GetShape().getGlobalBounds();

    float   left    = rect.left,
            top     = rect.top,
            right   = rect.left + rect.width,
            bottom  = rect.top + rect.height;

    for(auto unit : GetSelectedList())
    {
        auto shape = unit->GetShape().getGlobalBounds();

        if(shape.top < top) {
            top = shape.top;
        }

        if(shape.left < left) {
            left = shape.left;
        }

        if(shape.left + shape.width > right) {
            right = shape.left + shape.width;
        }

        if(shape.top + shape.height > bottom) {
            bottom = shape.top + shape.height;
        }
    }

    Vector2f center = Vector2f(
        (right + left) / 2,
        (bottom + top) / 2
    );

    Vector2f delta = Vector2f(
        pos.x - center.x,
        pos.y - center.y
    );

    test.setPosition(Vector2f(left + delta.x, top + delta.y));
    test.setSize(Vector2f(right - left, bottom - top));
    test.setFillColor(sf::Color::Yellow);    

    for(auto unit : GetSelectedList()) 
    {
        unit->SetDestination(unit->GetPos() + delta);
    }
}