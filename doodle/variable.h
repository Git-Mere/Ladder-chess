// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#pragma once
#include "Tile.h"
#include "button.h"
#include "doodle/doodle.hpp"
#include <vector>
#include <array>

using namespace doodle;

//Seungheon variables
inline int choice = 0;

inline bool only_one_tile = false;

inline int turn = 1;

inline int mod = 1;

inline std::vector<pos> spaces{};
inline std::array<Tile, 12> Tiles{ {
    Tile(TileType::one_block, 1), Tile(TileType::one_block2, 1), Tile(TileType::diagonal_l, 1),
    Tile(TileType::diagonal_r, 1), Tile(TileType::double_l, 1),   Tile(TileType::double_r, 1),
    Tile(TileType::one_block, 2), Tile(TileType::one_block2, 2), Tile(TileType::diagonal_l, 2),
    Tile(TileType::diagonal_r, 2), Tile(TileType::double_l, 2),   Tile(TileType::double_r, 2),
} };

//Sehun variables
constexpr int windowWidth{1300};
constexpr int windowHeight{700};
inline int    WINNER{0};
inline int    Win{0};
enum scenes
{
    INTRO,
    INTRO2,
    MAIN,
    HOWTOPLAY,
    CREDITS,
    INGAME,
    QUIT
};

inline int scene{INTRO};

inline std::vector<MadeButton> Button{MadeButton(-120, -60, 240, 60, 250, 180, 75, 255, "     START", INGAME),
                                      MadeButton(-120, -140, 240, 60, 250, 75, 180, 255, " How to Play", HOWTOPLAY),
                                      MadeButton(-120, -220, 240, 60, 75, 180, 250, 255, "    CREDIT", CREDITS),
                                      MadeButton(-120, -300, 240, 60, 75, 100, 100, 100, "      QUIT", QUIT),
                                      MadeButton(-600, -300, 120, 45, 75, 100, 100, 100, " BACK", MAIN),
                                      MadeButton(-75, -150, 150, 60, 75, 180, 250, 255, "  MAIN", MAIN)};


//Sangbeom variables
// map for player 1
// map1[i][j] : point(j, i)
inline int map1[33][6] = {
    {0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
};


// map for player 2
// map2[i][j] : point(j, i)
inline int map2[33][6] = {
    {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
};

//sound variables
inline int turnchange = 0;
inline int intro1 = 0;
inline int intro2 = 0;
inline int mainmenu = 0;
inline int ingame = 0;
inline int button1 = 1;
inline int button2 = 0;
inline int button3 = 0;
inline int win = 0;