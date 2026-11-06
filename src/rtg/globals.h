#pragma once
// rtg's common header: kazilib (std names, integer types, Out / Info / Warn / Err, the
// scene manager), SFML 3.1, the game's types and globals.
#include <stdnames.h>   // kazilib: the std names without std::
#include <stlxtypes.h>  // kazilib ml: u8 .. u64, szt
#ifdef _LIBCPP_VERSION
// (kazilib ml's stlx.h defines _NOEXCEPT empty; libc++ - the web build's - uses that
// name for `noexcept` in its own headers)
#undef _NOEXCEPT
#define _NOEXCEPT noexcept
#endif
#include <log.h>           // kazilib: Out / Info / Warn / Err
#include <scene/manager.h> // kazilib: lib::scene::Base / Manager

#include <algorithm>

#include <SFML/Graphics.hpp>

using sf::CircleShape;
using sf::Drawable;
using sf::FloatRect;
using sf::RectangleShape;
using sf::RenderStates;
using sf::RenderTarget;
using sf::RenderWindow;
using sf::Vector2f;

using TilePos = Vector2f;
using UnitId = u16;

constexpr unsigned kResX = 800, kResY = 600;

struct Unit;
struct UnitMgr;

// In construction order, destroyed the other way round (InitGlobals / FreeGlobals)
extern unique_ptr<UnitMgr> g_units;
extern lib::scene::Manager g_scenes;
extern RenderWindow * g_window;

void InitGlobals();
void FreeGlobals();
