#pragma once
#include "globals.h"

struct Selector : Drawable
{
	Selector();

	void Start(const Vector2f & pos);
	void Tick(const Vector2f & pos);
	FloatRect Release();

	void draw(RenderTarget & target, RenderStates states) const override
	{
		if (_active)
			target.draw(_shape, states);
	}

	bool _active = false;
	RectangleShape _shape;
};
