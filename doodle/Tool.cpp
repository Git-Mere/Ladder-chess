// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#include "variable.h"
#include "Tool.h"
#include "doodle/doodle.hpp"
#include "Position.h"

using namespace doodle;

void Tool::deter_mode()
{
    if (std::all_of(Tiles.begin(), Tiles.end(), [](Tile t) { return t.onoff == false; }))
    {
        mod = 2;
    }
}

void Tool::connect()
{
    for (int i = 0; i < spaces.size(); i++)
    {
        int y = 2 + ((i / 5) * 4); 
        int x = i % 5;
   
        if (spaces[i].point_l == true && spaces[i].point_r == true)
        {
            map1[y][x + 1] = 4;
            map2[y][x + 1] = 4;
            map1[y][x]     = 4;
            map2[y][x]     = 4;
        }
    }

    for (int i = 5; i < spaces.size(); i++)
    {
        int y = 2 + ((i / 5) * 4);
        int x = i % 5;
        int im = i - 5;
        if (spaces[i].point_r == true && spaces[im].point_l == true && spaces[i].point_l == false &&
            spaces[im].point_r == false && map1[y - 4][x] != 9 && map1[y - 4][x] != 10 && map2[y - 4][x] != 9 &&
            map2[y - 4][x] != 10 && map1[y][x + 1] != 9 && map1[y][x + 1] != 10 && map2[y][x + 1] != 9 &&
            map2[y][x + 1] != 10)
        {
            map1[y - 4][x] = 6;
            map2[y - 4][x] = 6;
            map1[y][x + 1] = 5;
            map2[y][x + 1] = 5;
        }
        
    }

    for (int i = 5; i < spaces.size(); i++)
    {
        int y = 2 + ((i / 5) * 4);
        int x = i % 5;
        int im = i - 5;
        if (spaces[i].point_l == true && spaces[im].point_r == true && spaces[i].point_r == false &&
            spaces[im].point_l == false && map1[y - 4][x + 1] != 6 && map1[y - 4][x + 1] != 5 &&
            map2[y - 4][x + 1] != 6 && map2[y - 4][x + 1] != 5 && map1[y][x] != 6 && map1[y][x] != 5 &&
            map2[y][x] != 6 && map2[y][x] != 5)
        {
            map1[y][x]         = 10;
            map2[y][x]         = 10;
            map1[y - 4][x + 1] = 9;
            map2[y - 4][x + 1] = 9;
        }
        
    }

    for (int i = 0; i < spaces.size(); i++)
    {
        int y = 1 + ((i / 5) * 4);
        int x = i % 5;
        if (spaces[i].u_point_l == true && spaces[i].u_point_r == true)
        {
            map1[y][x]         = 4;
            map2[y][x]         = 4;
            map1[y][x + 1] = 4;
            map2[y][x + 1] = 4;
        }
        
    }

    for (int i = 0; i < spaces.size(); i++)
    {
        int y = 3 + ((i / 5) * 4);
        int x = i % 5;
        if (spaces[i].d_point_l == true && spaces[i].d_point_r == true)
        {
            map1[y][x]     = 4;
            map2[y][x]     = 4;
            map1[y][x + 1] = 4;
            map2[y][x + 1] = 4;
        }
        
    }
}
void Tool::reset()
{
    for (int i = 0; i < Tiles.size(); i++)
    {
        if (Tiles[i].player == 1)
        {
            switch (Tiles[i].type)
            {
                case TileType::one_block:
                    Tiles[i].position.x = -550;
                    Tiles[i].position.y = 100;
                    break;
                case TileType::one_block2:
                    Tiles[i].position.x = -400;
                    Tiles[i].position.y = 100;
                    break;
                case TileType::diagonal_l:
                    Tiles[i].position.x = -550;
                    Tiles[i].position.y = -100;
                    break;
                case TileType::diagonal_r:
                    Tiles[i].position.x = -400;
                    Tiles[i].position.y = -100;
                    break;
                case TileType::double_l:
                    Tiles[i].position.x = -520;
                    Tiles[i].position.y = -200;
                    break;
                case TileType::double_r:
                    Tiles[i].position.x = -520;
                    Tiles[i].position.y = -300;
                    break;
            }
        }
        if (Tiles[i].player == 2)
        {
            switch (Tiles[i].type)
            {
                case TileType::one_block:
                    Tiles[i].position.x = 300;
                    Tiles[i].position.y = 100;
                    break;
                case TileType::one_block2:
                    Tiles[i].position.x = 450;
                    Tiles[i].position.y = 100;
                    break;
                case TileType::diagonal_l:
                    Tiles[i].position.x = 300;
                    Tiles[i].position.y = -100;
                    break;
                case TileType::diagonal_r:
                    Tiles[i].position.x = 450;
                    Tiles[i].position.y = -100;
                    break;
                case TileType::double_l:
                    Tiles[i].position.x = 330;
                    Tiles[i].position.y = -200;
                    break;
                case TileType::double_r:
                    Tiles[i].position.x = 330;
                    Tiles[i].position.y = -300;
                    break;
            }
        }
    }
    spaces.clear();
    make_space();

    for (int i = 0; i < 33; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            map1[i][j] = 0;
            map2[i][j] = 0;
        }
    }
    map1[0][1] = 1;
    map2[0][4] = 1;

    turn = 1;
    only_one_tile = false;
    choice        = 0;
    mod           = 1;

    WINNER = 0;
    Win    = 0;
    for (int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].onoff = true;
        Tiles[i].now_click = false;
    }
}   

void Tool::Cho()
{
    int mouseX = get_mouse_x();
    int mouseY = get_mouse_y();
    auto [p11, p12, p13, p14, p15, p16, p21, p22, p23, p24, p25, p26] = Tiles;

    for (int i = 0; i < Tiles.size(); i++)
    {
        if (mouseX >= Tiles[i].position.x && mouseX <= Tiles[i].position.x + Tiles[i].position.width &&
            mouseY >= Tiles[i].position.y && mouseY <= Tiles[i].position.y + Tiles[i].position.height)
        {
            if (Tiles[i].type == p11.type || Tiles[i].type == p12.type)
            {
                choice = 1;
            }
            else if (Tiles[i].type == p13.type)
            {
                choice = 2;
            }
            else if (Tiles[i].type == p14.type)
            {
                choice = 3;
            }
            else if (Tiles[i].type == p15.type)
            {
                choice = 4;
            }
            else if (Tiles[i].type == p16.type)
            {
                choice = 5;
            }
        }
    }
}

void Tool::make_space()
{
    for (int j = 240; j > -321; j -= 80)
    {
        for (int i = -225; i < 136; i += 90)
        {
            pos space;
            space.x      = i;
            space.y      = j;
            space.width  = 90;
            space.height = 80;
            spaces.push_back(space);
        }
    }
}

void Tool::ButtonRange(int first, int second, int Cscene)
{
    double MX = get_mouse_x();
    double MY = get_mouse_y();

    for (int i = first; i <= second; i++)
    {
        if ((MX > Button[i].x && MX < Button[i].x + Button[i].Width) &&
            (MY > Button[i].y && MY < Button[i].y + Button[i].Height) && scene == Cscene)
        {
            scene = Button[i].scene;
        }
    }
}

void Tool::ButtonRange(int first, int Cscene)
{
    double MX = get_mouse_x();
    double MY = get_mouse_y();
    if ((MX > Button[first].x && MX < Button[first].x + Button[first].Width) &&
        (MY > Button[first].y && MY < Button[first].y + Button[first].Height) && scene == Cscene)
    {
        scene = Button[first].scene;
    }
}

void Tool::IntroL2(double& TimeElapsed, double& alp)
{
    push_settings();
    (TimeElapsed < 2) ? alp += 10 : alp -= 10;
    set_outline_color(0, alp);
    set_fill_color(255, alp);
    set_font_size(60);

    draw_text("Team Protosstype", -325, 0);
    pop_settings();
    if (TimeElapsed > 4)
    {
        TimeElapsed = 0;
        alp         = 0;
        scene       = MAIN;
    }
}
void Tool::Credits()
{
    push_settings();
    set_outline_color(0);
    set_fill_color(255);
    set_font_size(40);

    draw_text("Seungheon Jeon",-600, 150);
    draw_text("Sangbeom Kim", -600, 0);
    draw_text("Sehun Kim", -600, -150);
    pop_settings();
}

void Tool::WhoIsWinner()
{
    push_settings();
    if (WINNER == 0)
    {
        set_fill_color(255, 50, 50);
        if (turn == 1)
            draw_rectangle(-485, 195, 110, 110);
        else if (turn == 2)
            draw_rectangle(365, 195, 110, 110);
    }
    else if (WINNER == 1)
    {
        set_fill_color(251, 242, 54);
        draw_rectangle(-485, 195, 110, 110);
    }
    else if (WINNER == 2)
    {
        set_fill_color(251, 242, 54);
        draw_rectangle(365, 195, 110, 110);
    }

    if (map1[32][4] ^ map2[32][1])
    {
        if (map1[32][4])
        {
            Win++;
            if (Win > 2) WINNER = 1;
        }
        if (map2[32][1])
        {
            Win++;
            if (Win > 2) WINNER = 2;
        }
    }
    else if (map1[32][4] && map2[32][1])
    {
        if (turn == 1)
            WINNER = 2;
        else if (turn == 2)
            WINNER = 1;
    }

    set_outline_color(0);
    set_fill_color(255);
    set_font_size(60);

    if (WINNER == 1)
    {
        draw_text("1P WIN", -130, 200);
        Button[5].IMadeButton();
    }
    if (WINNER == 2)
    {
        draw_text("2P WIN", -130, 200);
        Button[5].IMadeButton();
    }

    pop_settings();
}

void Tool::rule()
{
    for (int i = 0; i < spaces.size(); i++)
    {
        int ip1 = i + 1;
        int im1 = i - 1;
        int im4 = i - 4;
        int im5 = i - 5;
        int im6 = i - 6;
        if (i == 5 || i == 10 || i == 15 || i == 20 || i == 25 || i == 30 || i == 35)
        {
            if (choice == 1 || choice == 2)
            {
                if (spaces[ip1].point_l == false && spaces[i].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
            else if (choice == 3)
            {
                if (spaces[im4].point_l == false && spaces[im5].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
        }
        else if (i == 0)
        {
            if (choice == 1)
            {
                if (spaces[ip1].point_l == false && spaces[i].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
        }
        else if (i == 1 || i == 2 || i == 3)
        {
            if (choice == 1)
            {
                if (spaces[ip1].point_l == false && spaces[i].point_r == false && spaces[i].point_l == false &&
                    spaces[im1].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
        }
        else if (i == 4)
        {
            if (choice == 1)
            {
                if (spaces[im1].point_r == false && spaces[i].point_l == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
        }
        else if (i == 9 || i == 14 || i == 19 || i == 24 || i == 29 || i == 34 || i == 39)
        {
            if (choice == 1 || choice == 3)
            {
                if (spaces[i].point_l == false && spaces[im1].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
            else if (choice == 2)
            {
                if (spaces[im5].point_l == false && spaces[im6].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
        }
        else
        {
            if (choice == 1)
            {
                if (spaces[ip1].point_l == false && spaces[i].point_r == false && spaces[i].point_l == false &&
                    spaces[im1].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
            else if (choice == 2)
            {
                if (spaces[i].point_r == false && spaces[ip1].point_l == false && spaces[im5].point_l == false &&
                    spaces[im6].point_r == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
            else if (choice == 3)
            {
                if (spaces[i].point_l == false && spaces[im1].point_r == false && spaces[im5].point_r == false &&
                    spaces[im4].point_l == false)
                {
                    spaces[i].check = true;
                }
                else
                {
                    spaces[i].check = false;
                }
            }
        }
    }

    for (int i = 0; i < spaces.size(); i++)
    {
        int ip1 = i + 1;
        int ip2 = i + 2;
        int im1 = i - 1;
        if (i == 0 || i == 5 || i == 10 || i == 15 || i == 20 || i == 25 || i == 30 || i == 35)
        {
            if (choice == 4)
            {
                if (spaces[ip1].d_point_r == false && spaces[ip2].d_point_l == false)
                {
                    spaces[i].d_check = true;
                }
                else
                {
                    spaces[i].d_check = false;
                }
            }
            else if (choice == 5)
            {
                if (spaces[ip1].u_point_r == false && spaces[ip2].u_point_l == false)
                {
                    spaces[i].d_check = true;
                }
                else
                {
                    spaces[i].d_check = false;
                }
            }
        }
        else if (i == 3 || i == 8 || i == 13 || i == 18 || i == 23 || i == 28 || i == 33 || i == 38)
        {
            if (choice == 4)
            {
                if (spaces[i].u_point_l == false && spaces[im1].u_point_r == false)
                {
                    spaces[i].d_check = true;
                }
                else
                {
                    spaces[i].d_check = false;
                }
            }
            else if (choice == 5)
            {
                if (spaces[i].d_point_l == false && spaces[im1].d_point_r == false)
                {
                    spaces[i].d_check = true;
                }
                else
                {
                    spaces[i].d_check = false;
                }
            }
        }
        else if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24 || i == 29 || i == 34 || i == 39)
        {
            spaces[i].d_check = false;
        }
        else
        {
            if (choice == 4)
            {
                if (spaces[ip1].d_point_r == false && spaces[ip2].d_point_l == false && spaces[i].u_point_r == false &&
                    spaces[im1].u_point_l == false)
                {
                    spaces[i].d_check = true;
                }
                else
                {
                    spaces[i].d_check = false;
                }
            }
            else if (choice == 5)
            {
                if (spaces[ip1].u_point_r == false && spaces[ip2].u_point_l == false && spaces[i].d_point_r == false &&
                    spaces[im1].d_point_l == false)
                {
                    spaces[i].d_check = true;
                }
                else
                {
                    spaces[i].d_check = false;
                }
            }
        }
    }
}