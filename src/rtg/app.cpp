#include "app.h"
#include "unit.h"
#include "unitmgr.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

App::App()
{
	InitializeWindow();
	InitGlobals();
}

App::~App()
{
	FreeGlobals();
}

void App::Run()
{
	_clock.restart();

	while (_window->isOpen())
	{
		HandleEvents();
		Ticks();
		Render();
	}
}

void App::InitializeWindow()
{
	sf::ContextSettings settings;

#ifdef __EMSCRIPTEN__
	// The page sizes the canvas (kazilib web/shell.html), not the window's resize frame;
	// display() waits for the browser's next frame. The game has no text of its own: the
	// controls go under it, on the page.
	const auto style = sf::Style::Titlebar | sf::Style::Close;
	emscripten_run_script("document.getElementById('bar').insertAdjacentHTML('beforeend', '<span id=\"hint\">Left drag: select units. Right click: move them.</span>')");
#else
	const auto style = sf::Style::Default;
	settings.antiAliasingLevel = 8; // (a browser's one context is made before this window)
#endif

	_window = make_unique<RenderWindow>(sf::VideoMode({ kResX, kResY }), "rtg", style, sf::State::Windowed, settings);
	g_window = _window.get();

#ifndef __EMSCRIPTEN__
	_window->setFramerateLimit(60);
#endif
}

void App::HandleEvents()
{
	while (const optional<sf::Event> event = _window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			_window->close();
		else
			g_scenes.HandleEvent(&*event);
	}
}

void App::Ticks()
{
	_debt += _clock.restart().asSeconds();

	for (int i = 0; _debt >= kTickSeconds && i < kMaxTicksPerFrame; i++)
	{
		_debt -= kTickSeconds;
		g_scenes.Tick();
	}

	if (_debt >= kTickSeconds)
		_debt = 0.f;
}

void App::Render()
{
	_window->clear(sf::Color::Black);
	g_scenes.Render();
	_window->display();
}
