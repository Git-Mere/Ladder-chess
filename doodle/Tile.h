//Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
//Assignment Name   : Game Prototype 1
//Course            : CS120
//Term & Year       : fall/2020

#pragma once
#include "Position.h"
#include "doodle/doodle.hpp"

enum class TileType
{
    one_block,
    one_block2,
    diagonal_l,
    diagonal_r,
    double_l,
    double_r
};

class Tile
{
public:

    Tile(TileType type, int p);

    TileType type{TileType::one_block};
    pos      position{0};
    bool     now_click = false;
    int      player = 0;
    bool     onoff = true;

    

    void update();
    void draw();
    void tilemove();
    void tilemove2();

    void tilemove_helper1(int &mouseX, int &mouseY);
    void tilemove_helper2(int &mouseX, int &mouseY);
    void tilemove_helper3(int &mouseX, int &mouseY);
    void tilemove_helper4(int &mouseX, int &mouseY);
    void tilemove_helper5(int &mouseX, int &mouseY);

    void tilemove2_helper1(int& mouseX, int& mouseY);
    void tilemove2_helper2(int& mouseX, int& mouseY);
    void tilemove2_helper3(int& mouseX, int& mouseY);
    void tilemove2_helper4(int& mouseX, int& mouseY);
    void tilemove2_helper5(int& mouseX, int& mouseY);
    

};
