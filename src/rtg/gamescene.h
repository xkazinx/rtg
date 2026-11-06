#pragma once
#include "globals.h"
#include "selector.h"

struct GameScene : lib::scene::Base
{
	void Initialize() override;
	void Render() override;
	void HandleEvent(const void * event) override;
	void Tick() override;

	Selector _selector;
	// A move order is running (the console line when it ends)
	bool _moving = false;
};
