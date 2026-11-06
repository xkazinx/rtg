#pragma once
#include "globals.h"

struct Unit : Drawable
{
	using Id = UnitId;

	explicit Unit(TilePos pos);

	void SetSelected(const bool value);
	// A step towards the destination; true when it's there
	bool Tick();

	void draw(RenderTarget & target, RenderStates states) const override
	{
		target.draw(_shape, states);
	}

	CircleShape _shape;
	Id _id = 0;
	Vector2f _destination;
	bool _selected = false;
};
