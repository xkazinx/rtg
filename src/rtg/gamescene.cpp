#include "gamescene.h"
#include "unit.h"
#include "unitmgr.h"

void GameScene::Initialize()
{
	if (!InitOnce())
		return;

	g_units->Add(make_unique<Unit>(TilePos{ 10.f, 10.f }));
	g_units->Add(make_unique<Unit>(TilePos{ 20.f, 30.f }));

	g_units->Add(make_unique<Unit>(TilePos{ 60.f, 70.f }));
	g_units->Add(make_unique<Unit>(TilePos{ 30.f, 40.f }));

	g_units->Add(make_unique<Unit>(TilePos{ 50.f, 80.f }));
	g_units->Add(make_unique<Unit>(TilePos{ 100.f, 90.f }));

	g_units->Add(make_unique<Unit>(TilePos{ 120.f, 440.f }));
	g_units->Add(make_unique<Unit>(TilePos{ 450.f, 230.f }));

	Out("Game ready: {} units", g_units->_list.size());
}

void GameScene::HandleEvent(const void * event)
{
	if (!event)
		return;

	const auto & ev = *static_cast<const sf::Event *>(event);

	if (const auto * press = ev.getIf<sf::Event::MouseButtonPressed>())
	{
		if (press->button == sf::Mouse::Button::Left)
			_selector.Start(Vector2f(press->position));
		else if (press->button == sf::Mouse::Button::Right)
		{
			g_units->Move(Vector2f(press->position));
			_moving = !g_units->_selected_list.empty();
		}
	}
	else if (const auto * release = ev.getIf<sf::Event::MouseButtonReleased>())
	{
		if (release->button == sf::Mouse::Button::Left)
			g_units->Select(_selector.Release());
	}
	else if (const auto * moved = ev.getIf<sf::Event::MouseMoved>())
		_selector.Tick(Vector2f(moved->position));
}

void GameScene::Render()
{
	g_window->draw(g_units->_target_area);

	for (const auto & unit : g_units->_list)
		g_window->draw(*unit);

	g_window->draw(_selector);
}

void GameScene::Tick()
{
	bool arrived = true;

	for (auto & unit : g_units->_list)
		arrived = unit->Tick() && arrived;

	if (_moving && arrived)
	{
		_moving = false;
		Out("Units arrived");
	}
}
