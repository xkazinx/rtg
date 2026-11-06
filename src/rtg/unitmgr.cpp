#include "unitmgr.h"
#include "unit.h"

UnitMgr::~UnitMgr() = default;

Unit * UnitMgr::FindById(const Id id)
{
	const auto it = std::find_if(_list.begin(), _list.end(), [&](const auto & unit) { return unit->_id == id; });
	return it != _list.end() ? it->get() : nullptr;
}

void UnitMgr::Add(unique_ptr<Unit> && unit)
{
	unit->_id = ++_create_id;
	_list.emplace_back(std::move(unit));
}

void UnitMgr::Select(const FloatRect & area)
{
	_selected_list.clear();

	for (auto & unit : _list)
	{
		unit->SetSelected(area.findIntersection(unit->_shape.getGlobalBounds()).has_value());
		if (unit->_selected)
			_selected_list.push_back(unit.get());
	}

	Out("Selected {} units", _selected_list.size());
}

void UnitMgr::Move(const Vector2f & pos)
{
	// A right click with nothing selected
	if (_selected_list.empty())
		return;

	const FloatRect first = _selected_list.front()->_shape.getGlobalBounds();
	float left = first.position.x;
	float top = first.position.y;
	float right = left + first.size.x;
	float bottom = top + first.size.y;

	for (const Unit * const unit : _selected_list)
	{
		const FloatRect shape = unit->_shape.getGlobalBounds();
		left = std::min(left, shape.position.x);
		top = std::min(top, shape.position.y);
		right = std::max(right, shape.position.x + shape.size.x);
		bottom = std::max(bottom, shape.position.y + shape.size.y);
	}

	const Vector2f center((right + left) / 2.f, (bottom + top) / 2.f);
	const Vector2f delta = pos - center;

	_target_area.setPosition({ left + delta.x, top + delta.y });
	_target_area.setSize({ right - left, bottom - top });
	_target_area.setFillColor(sf::Color::Yellow);

	for (Unit * const unit : _selected_list)
		unit->_destination = unit->_shape.getPosition() + delta;

	Out("Moving {} units to {} {}", _selected_list.size(), pos.x, pos.y);
}
