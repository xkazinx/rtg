#include "unitmgr.h"
#include "unit.h"

UnitMgr::~UnitMgr() {}

Unit * UnitMgr::FindById(const UnitId & id) {
    return FindIf([&](auto & unit) { return unit->Is(id); });
}

void UnitMgr::Add(unique_ptr<Unit> && unit) {
    unit->GetId() = ++_create_id;
    _list.emplace_back(std::move(unit));
}

void UnitMgr::Select(const FloatRect & area) {

    cout << "Selecting units" << endl;

    _selected_list.clear();

    for(auto & unit : GetList()) 
    {
        auto & shape = unit->GetShape();
        if (area.intersects(shape.getGlobalBounds()))
        {
            _selected_list.push_back(unit.get());
            shape.setFillColor(sf::Color::Blue);
        }
        else {
            shape.setFillColor(sf::Color::Red);
        }
    }
}

void UnitMgr::Move(const Vector2f & pos)
{
    for(auto unit : GetSelectedList()) 
    {
        unit->SetDestination(pos);
    }
}