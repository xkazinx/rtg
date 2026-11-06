#include "globals.h"
#include "gamescene.h"
#include "unit.h"
#include "unitmgr.h"

unique_ptr<UnitMgr> g_units;
lib::scene::Manager g_scenes;
RenderWindow * g_window = nullptr;

static unique_ptr<GameScene> s_game;

/**
 * Reason to use methods is to specify the order
 * of construction and deconstruction of every instance
 */
void InitGlobals()
{
	g_units = make_unique<UnitMgr>();
	s_game = make_unique<GameScene>();
	g_scenes.Add(*s_game);
	g_scenes.Set(*s_game);
}

void FreeGlobals()
{
	g_scenes._current = nullptr;
	g_scenes._list.clear();
	s_game.reset();
	g_units.reset();
}
