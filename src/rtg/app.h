#pragma once
#include "globals.h"

struct App
{
	// The game runs at this rate whatever the display does: a browser's frame is the
	// display's refresh (60, 120, 144 Hz), and units move a pixel per tick
	static constexpr float kTickSeconds = 1.f / 60.f;
	// The most ticks a frame catches up (a hidden tab, a long stall: the rest dropped)
	static constexpr int kMaxTicksPerFrame = 5;

	App();
	~App();

	void Run();
	void InitializeWindow();
	void HandleEvents();
	void Ticks();
	void Render();

	unique_ptr<RenderWindow> _window;
	sf::Clock _clock;
	float _debt = 0.f;
};
