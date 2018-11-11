#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
#include <string>
//string
#include <memory>
//unique_ptr, shared_ptr, weak_ptr
#include <algorithm>
//find_if

#include <SFML/Graphics.hpp>
#include <cstdint>

using sf::RenderTarget;
using sf::ContextSettings;
using sf::RenderStates;
using sf::Vector2f;
using sf::FloatRect;
using sf::Event;
using sf::VideoMode;
using sf::Mouse;
using sf::Drawable;
using sf::CircleShape;
using sf::RectangleShape;
using sf::RenderWindow;

using namespace std;

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using szt = std::size_t;

using TilePos = Vector2f;
using UnitId = u16;

// g++ -std=c++1z src/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -enetlib.a && ./sfml-app

constexpr auto kResX = 800, kResY = 600;

class Unit;
class UnitMgr;
class Scene;
class SceneMgr;

namespace g
{
    extern unique_ptr<UnitMgr> unit_mgr;
    extern unique_ptr<SceneMgr> scene_mgr;

    extern void Initialize();
    extern void Deinitialize();
};

enum class SceneID : u8
{
    Main,
    Game,
    Max,
};

#include <functional>
/*
class Guard 
{
    template<typename Fnc>
    Guard(Fnc constuct, Fnc destruct) 
        : _destruct(destruct)
    {
        construct();
    }

    ~Guard()
    {
        _destruct();
    }

    function<(void)> _destruct;
}
*/
#endif