#pragma once
#include "globals.h"

struct UnitMgr
{
	using Id = UnitId;

	~UnitMgr();

	void Add(unique_ptr<Unit> && unit);
	Unit * FindById(const Id id);

	// The units touching `area` become the selection
	void Select(const FloatRect & area);
	// Moves selected units to point, the group keeping its shape
	void Move(const Vector2f & pos);

	Id _create_id = 0;
	vector<unique_ptr<Unit>> _list;
	vector<Unit *> _selected_list;
	// Where the last group is going: the yellow box under the units
	RectangleShape _target_area;
};
