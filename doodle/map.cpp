// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#include "map.h"
#include "variable.h"
#include <doodle/doodle.hpp>
#include <iostream>

using namespace doodle;

// line connect algorithm for player 1
void modLine1()
{
    for (int i = 1; i < 33; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (map1[i][j] == 4 && map1[i][j - 1] == 4)
            {
                if (map1[i - 1][j] == map1[i - 1][j - 1])
                {
                    map1[i][j]     = 4;
                    map1[i][j - 1] = 4;
                }
                if (map1[i - 1][j] != map1[i - 1][j - 1] && (map1[i][j - 2] + map1[i][j + 1] != 8))
                {
                    if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3 || map1[i - 1][j] == 8 || map1[i - 1][j] == 12)
                    {
                        map1[i][j - 1] = 3;
                        map1[i][j]     = 2;
                    }
                    if (map1[i - 1][j - 1] == 1 || map1[i - 1][j - 1] == 3 || map1[i - 1][j - 1] == 8 ||
                        map1[i - 1][j - 1] == 12)
                    {
                        map1[i][j - 1] = 2;
                        map1[i][j]     = 3;
                    }
                }
            }
            if (map1[i][j] == 2 && map1[i][j - 1] == 3)
            {
                if (map1[i - 1][j] == 0 && map1[i - 1][j - 1] == 0)
                {
                    map1[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map1[i - 1][j] == 4 && map1[i - 1][j - 1] == 4)
                {
                    map1[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map1[i - 1][j - 1] == 1 || map1[i - 1][j - 1] == 3 || map1[i - 1][j - 1] == 8 ||
                    map1[i - 1][j - 1] == 12)
                {
                    map1[i][j]     = 3;
                    map1[i][j - 1] = 2;
                }
                if (map1[i - 1][j] == 0 || (map1[i - 1][j] == 2 && map1[i - 1][j + 1] == 3) ||
                    (map1[i - 1][j] == 7 && map1[i + 3][j + 1] == 8) ||
                    (map1[i - 1][j] == 11 && map1[i + 3][j + 1] == 12))
                {
                    map1[i][j]     = 4;
                    map1[i][j - 1] = 4;
                }
            }
            if (map1[i][j] == 3 && map1[i][j - 1] == 2)
            {
                if (map1[i - 1][j] == 0 && map1[i - 1][j - 1] == 0)
                {
                    map1[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map1[i - 1][j] == 4 && map1[i - 1][j - 1] == 4)
                {
                    map1[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3 || map1[i - 1][j] == 8 || map1[i - 1][j] == 12)
                {
                    map1[i][j]     = 2;
                    map1[i][j - 1] = 3;
                }
                if (map1[i - 1][j - 1] == 0 || (map1[i - 1][j - 1] == 2 && map1[i - 1][j - 2] == 3) ||
                    (map1[i - 1][j - 1] == 7 && map1[i - 5][j - 2] == 8) ||
                    (map1[i - 1][j - 1] == 11 && map1[i - 5][j - 2] == 12))
                {
                    map1[i][j]     = 4;
                    map1[i][j - 1] = 4;
                }
            }
            // 5 6
            if (map1[i][j] == 5 && map1[i - 4][j - 1] == 6)
            {
                if (map1[i - 1][j] == map1[i - 5][j - 1])
                {
                    map1[i][j]         = 5;
                    map1[i - 4][j - 1] = 6;
                }
                if (map1[i - 1][j] != map1[i - 5][j - 1])
                {
                    if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3)
                    {
                        map1[i][j]         = 7;
                        map1[i - 4][j - 1] = 8;
                    }
                    if (map1[i - 5][j - 1] == 1 || map1[i - 5][j - 1] == 3)
                    {
                        map1[i][j]         = 8;
                        map1[i - 4][j - 1] = 7;
                    }
                    if (map1[i - 1][j] == 2 || map1[i - 1][j] == 4)
                    {
                        map1[i][j]         = 5;
                        map1[i - 4][j - 1] = 6;
                    }
                    if (map1[i - 5][j - 1] == 2 || map1[i - 5][j - 1] == 4)
                    {
                        map1[i][j]         = 5;
                        map1[i - 4][j - 1] = 6;
                    }
                }
            }
            if (map1[i][j] == 7 && map1[i - 4][j - 1] == 8)
            {
                if (map1[i - 1][j] == 2 || map1[i - 1][j] == 4)
                {
                    map1[i][j]         = 5;
                    map1[i - 4][j - 1] = 6;
                }
                if (map1[i - 5][j - 1] == 1 || map1[i - 5][j - 1] == 3)
                {
                    map1[i][j]         = 8;
                    map1[i - 4][j - 1] = 7;
                }
                if (map1[i - 1][j] == 0 && map1[i - 5][j - 1] == 0)
                {
                    map1[i][j]         = 5;
                    map1[i - 4][j - 1] = 6;
                }
            }
            if (map1[i][j] == 8 && map1[i - 4][j - 1] == 7)
            {
                if (map1[i - 5][j - 1] == 2 || map1[i - 5][j - 1] == 4)
                {
                    map1[i][j]         = 5;
                    map1[i - 4][j - 1] = 6;
                }
                if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3)
                {
                    map1[i][j]         = 7;
                    map1[i - 4][j - 1] = 8;
                }
                if (map1[i - 1][j] == 0 && map1[i - 5][j - 1] == 0)
                {
                    map1[i][j]         = 5;
                    map1[i - 4][j - 1] = 6;
                }
            }
            // 9 10
            if (map1[i][j] == 9 && map1[i + 4][j - 1] == 10)
            {
                if (map1[i - 1][j] == map1[i + 3][j - 1])
                {
                    map1[i][j]         = 9;
                    map1[i + 4][j - 1] = 10;
                }
                if (map1[i - 1][j] != map1[i + 3][j - 1])
                {
                    if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3)
                    {
                        map1[i][j]         = 11;
                        map1[i + 4][j - 1] = 12;
                    }
                    if (map1[i + 3][j - 1] == 1 || map1[i + 3][j - 1] == 3)
                    {
                        map1[i][j]         = 12;
                        map1[i + 4][j - 1] = 11;
                    }
                }
            }
            if (map1[i][j] == 11 && map1[i + 4][j - 1] == 12)
            {
                if (map1[i - 1][j] == 2 || map1[i - 1][j] == 4)
                {
                    map1[i][j]         = 9;
                    map1[i + 4][j - 1] = 10;
                }
                if (map1[i + 3][j - 1] == 1 || map1[i + 3][j - 1] == 3)
                {
                    map1[i][j]         = 12;
                    map1[i + 4][j - 1] = 11;
                }
                if (map1[i - 1][j] == 0 && map1[i + 3][j - 1] == 0)
                {
                    map1[i][j]         = 9;
                    map1[i + 4][j - 1] = 10;
                }
            }
            if (map1[i][j] == 12 && map1[i + 4][j - 1] == 11)
            {
                if (map1[i + 3][j - 1] == 2 || map1[i + 3][j - 1] == 4)
                {
                    map1[i][j]         = 9;
                    map1[i + 4][j - 1] = 10;
                }
                if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3)
                {
                    map1[i][j]         = 11;
                    map1[i + 4][j - 1] = 12;
                }
                if (map1[i - 1][j] == 0 && map1[i + 3][j - 1] == 0)
                {
                    map1[i][j]         = 9;
                    map1[i + 4][j - 1] = 10;
                }
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 2; j < 5; j++)
        {
            if (map1[i][j] == 3 && map1[i][j - 1] != 2 && map1[i][j + 1] == 4)
            {
                map1[i][j] = 4;
            }
            if (map1[i][j] == 3 && map1[i][j - 1] == 4 && map1[i][j + 1] != 2)
            {
                map1[i][j] = 4;
            }
            if (map1[i][j] == 2 && map1[i][j - 1] != 3 && map1[i][j + 1] == 4)
            {
                map1[i][j] = 4;
            }
            if (map1[i][j] == 2 && map1[i][j - 1] == 4 && map1[i][j + 1] != 3)
            {
                map1[i][j] = 4;
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (map1[i][j] == 0 || map1[i][j] == 1)
            {
                if (map1[i - 1][j] == 1 || map1[i - 1][j] == 3 || map1[i - 1][j] == 8 || map1[i - 1][j] == 12)
                {
                    map1[i][j] = 1;
                }
                if (map1[i - 1][j] == 0 || map1[i - 1][j] == 2 || map1[i - 1][j] == 7 || map1[i - 1][j] == 11)
                {
                    map1[i][j] = 0;
                }
                if (map1[i - 1][j] == 4 || map1[i - 1][j] == 5 || map1[i - 1][j] == 6 || map1[i - 1][j] == 9 ||
                    map1[i - 1][j] == 10)
                {
                    map1[i][j] = 0;
                }
            }
        }
    }
}

// line draw for player 1(red)
void mapshow1()
{
    push_settings();
    apply_translate(-225, 320);
    set_outline_width(3);
    set_outline_color(255, 0, 0);
    for (int i = 2; i < 32; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (map1[i][j] == 5 && map1[i - 4][j - 1] == 6)
            {
                push_settings();
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i - 4) * -20;
                int y2 = i * -20;
                set_outline_color(0);
                draw_line(x1, y1, x2, y2);
                pop_settings();
            }
            if (map1[i][j] == 9 && map1[i + 4][j - 1] == 10)
            {
                push_settings();
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i + 4) * -20;
                int y2 = i * -20;
                set_outline_color(0);
                draw_line(x1, y1, x2, y2);
                pop_settings();
            }
            if (map1[i][j] == 7 && map1[i - 4][j - 1] == 8)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i - 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = (i - 4) * -20;
                int y4 = (i - 3) * -20;
                int x  = (j - 1) * 90;
                draw_line(x, y3, x, y4);
            }
            if (map1[i][j] == 8 && map1[i - 4][j - 1] == 7)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i - 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = i * -20;
                int y4 = (i + 1) * -20;
                int x  = j * 90;
                draw_line(x, y3, x, y4);
            }
            if (map1[i][j] == 11 && map1[i + 4][j - 1] == 12)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i + 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = (i + 4) * -20;
                int y4 = (i + 5) * -20;
                int x  = (j - 1) * 90;
                draw_line(x, y3, x, y4);
            }
            if (map1[i][j] == 12 && map1[i + 4][j - 1] == 11)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i + 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = i * -20;
                int y4 = (i + 1) * -20;
                int x  = j * 90;
                draw_line(x, y3, x, y4);
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 2; j < 6; j++)
        {
            if (map1[i][j] == 4 && map1[i][j - 1] == 4 && map1[i][j - 2] == 4 && map1[i][j + 1] == 4)
            {
                push_settings();
                int x1 = (j - 2) * 90;
                int x2 = (j - 1) * 90;
                int x3 = j * 90;
                int x4 = (j + 1) * 90;
                int y  = i * -20;
                set_outline_color(0);
                draw_line(x1, y, x2, y);
                draw_line(x3, y, x4, y);
                pop_settings();
            }
            if (map1[i][j] == 4 && map1[i][j - 1] == 4 && map1[i][j - 2] != 4 && map1[i][j + 1] != 4)
            {
                push_settings();
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y  = i * -20;
                set_outline_color(0);
                draw_line(x1, y, x2, y);
                pop_settings();
            }
        }
        for (int j = 1; j < 6; j++)
        {
            if (j == 1 || j == 6)
            {
                if (map1[i][j] == 4 && map1[i][j - 1] == 4)
                {
                    push_settings();
                    int x1 = (j - 1) * 90;
                    int x2 = j * 90;
                    int y  = i * -20;
                    set_outline_color(0);
                    draw_line(x1, y, x2, y);
                    pop_settings();
                }
            }
            if (map1[i][j] == 2 && map1[i][j - 1] == 3)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y  = i * -20;
                draw_line(x1, y, x2, y);
                int y1 = i * -20;
                int y2 = (i + 1) * -20;
                int x  = (j - 1) * 90;
                draw_line(x, y1, x, y2);
            }
            if (map1[i][j] == 3 && map1[i][j - 1] == 2)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y  = i * -20;
                draw_line(x1, y, x2, y);
                int y1 = i * -20;
                int y2 = (i + 1) * -20;
                int x  = j * 90;
                draw_line(x, y1, x, y2);
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (map1[i - 1][j] == 1)
            {
                int y1 = (i - 1) * -20;
                int y2 = i * -20;
                int x  = j * 90;
                draw_line(x, y1, x, y2);
            }
        }
    }
    pop_settings();
}

void modLine2()
{
    for (int i = 1; i < 33; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (map2[i][j] == 4 && map2[i][j - 1] == 4)
            {
                if (map2[i - 1][j] == map2[i - 1][j - 1])
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map2[i - 1][j] != map2[i - 1][j - 1] && (map2[i][j - 2] + map2[i][j + 1] != 8))
                {
                    if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3 || map2[i - 1][j] == 8 || map2[i - 1][j] == 12)
                    {
                        map2[i][j - 1] = 3;
                        map2[i][j]     = 2;
                    }
                    if (map2[i - 1][j - 1] == 1 || map2[i - 1][j - 1] == 3 || map2[i - 1][j - 1] == 8 ||
                        map2[i - 1][j - 1] == 12)
                    {
                        map2[i][j - 1] = 2;
                        map2[i][j]     = 3;
                    }
                }
            }
            if (map2[i][j] == 2 && map2[i][j - 1] == 3)
            {
                if (map2[i - 1][j] == 0 && map2[i - 1][j - 1] == 0)
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map2[i - 1][j] == 4 && map2[i - 1][j - 1] == 4)
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map2[i - 1][j - 1] == 1 || map2[i - 1][j - 1] == 3 || map2[i - 1][j - 1] == 8 ||
                    map2[i - 1][j - 1] == 12)
                {
                    map2[i][j]     = 3;
                    map2[i][j - 1] = 2;
                }
                if (map2[i - 1][j] == 0 || (map2[i - 1][j] == 2 && map2[i - 1][j + 1] == 3) ||
                    (map2[i - 1][j] == 7 && map2[i + 3][j + 1] == 8) ||
                    (map2[i - 1][j] == 11 && map2[i + 3][j + 1] == 12))
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
            }
            if (map2[i][j] == 3 && map2[i][j - 1] == 2)
            {
                if (map2[i - 1][j] == 0 && map2[i - 1][j - 1] == 0)
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map2[i - 1][j] == 4 && map2[i - 1][j - 1] == 4)
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
                if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3 || map2[i - 1][j] == 8 || map2[i - 1][j] == 12)
                {
                    map2[i][j]     = 2;
                    map2[i][j - 1] = 3;
                }
                if (map2[i - 1][j - 1] == 0 || (map2[i - 1][j - 1] == 2 && map2[i - 1][j - 2] == 3) ||
                    (map2[i - 1][j - 1] == 7 && map2[i - 5][j - 2] == 8) ||
                    (map2[i - 1][j - 1] == 11 && map2[i - 5][j - 2] == 12))
                {
                    map2[i][j]     = 4;
                    map2[i][j - 1] = 4;
                }
            }
            // 5 6
            if (map2[i][j] == 5 && map2[i - 4][j - 1] == 6)
            {
                if (map2[i - 1][j] == map2[i - 5][j - 1])
                {
                    map2[i][j]         = 5;
                    map2[i - 4][j - 1] = 6;
                }
                if (map2[i - 1][j] != map2[i - 5][j - 1])
                {
                    if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3)
                    {
                        map2[i][j]         = 7;
                        map2[i - 4][j - 1] = 8;
                    }
                    if (map2[i - 5][j - 1] == 1 || map2[i - 5][j - 1] == 3)
                    {
                        map2[i][j]         = 8;
                        map2[i - 4][j - 1] = 7;
                    }
                    if (map2[i - 1][j] == 2 || map2[i - 1][j] == 4)
                    {
                        map2[i][j]         = 5;
                        map2[i - 4][j - 1] = 6;
                    }
                    if (map2[i - 5][j - 1] == 2 || map2[i - 5][j - 1] == 4)
                    {
                        map2[i][j]         = 5;
                        map2[i - 4][j - 1] = 6;
                    }
                }
            }
            if (map2[i][j] == 7 && map2[i - 4][j - 1] == 8)
            {
                if (map2[i - 1][j] == 2 || map2[i - 1][j] == 4)
                {
                    map2[i][j]         = 5;
                    map2[i - 4][j - 1] = 6;
                }
                if (map2[i - 5][j - 1] == 1 || map2[i - 5][j - 1] == 3)
                {
                    map2[i][j]         = 8;
                    map2[i - 4][j - 1] = 7;
                }
                if (map2[i - 1][j] == 0 && map2[i - 5][j - 1] == 0)
                {
                    map2[i][j]         = 5;
                    map2[i - 4][j - 1] = 6;
                }
            }
            if (map2[i][j] == 8 && map2[i - 4][j - 1] == 7)
            {
                if (map2[i - 5][j - 1] == 2 || map2[i - 5][j - 1] == 4)
                {
                    map2[i][j]         = 5;
                    map2[i - 4][j - 1] = 6;
                }
                if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3)
                {
                    map2[i][j]         = 7;
                    map2[i - 4][j - 1] = 8;
                }
                if (map2[i - 1][j] == 0 && map2[i - 5][j - 1] == 0)
                {
                    map2[i][j]         = 5;
                    map2[i - 4][j - 1] = 6;
                }
            }
            // 9 10
            if (map2[i][j] == 9 && map2[i + 4][j - 1] == 10)
            {
                if (map2[i - 1][j] == map2[i + 3][j - 1])
                {
                    map2[i][j]         = 9;
                    map2[i + 4][j - 1] = 10;
                }
                if (map2[i - 1][j] != map2[i + 3][j - 1])
                {
                    if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3)
                    {
                        map2[i][j]         = 11;
                        map2[i + 4][j - 1] = 12;
                    }
                    if (map2[i + 3][j - 1] == 1 || map2[i + 3][j - 1] == 3)
                    {
                        map2[i][j]         = 12;
                        map2[i + 4][j - 1] = 11;
                    }
                }
            }
            if (map2[i][j] == 11 && map2[i + 4][j - 1] == 12)
            {
                if (map2[i - 1][j] == 2 || map2[i - 1][j] == 4)
                {
                    map2[i][j]         = 9;
                    map2[i + 4][j - 1] = 10;
                }
                if (map2[i + 3][j - 1] == 1 || map2[i + 3][j - 1] == 3)
                {
                    map2[i][j]         = 12;
                    map2[i + 4][j - 1] = 11;
                }
                if (map2[i - 1][j] == 0 && map2[i + 3][j - 1] == 0)
                {
                    map2[i][j]         = 9;
                    map2[i + 4][j - 1] = 10;
                }
            }
            if (map2[i][j] == 12 && map2[i + 4][j - 1] == 11)
            {
                if (map2[i + 3][j - 1] == 2 || map2[i + 3][j - 1] == 4)
                {
                    map2[i][j]         = 9;
                    map2[i + 4][j - 1] = 10;
                }
                if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3)
                {
                    map2[i][j]         = 11;
                    map2[i + 4][j - 1] = 12;
                }
                if (map2[i - 1][j] == 0 && map2[i + 3][j - 1] == 0)
                {
                    map2[i][j]         = 9;
                    map2[i + 4][j - 1] = 10;
                }
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 2; j < 5; j++)
        {
            if (map2[i][j] == 3 && map2[i][j - 1] != 2 && map2[i][j + 1] == 4)
            {
                map2[i][j] = 4;
            }
            if (map2[i][j] == 3 && map2[i][j - 1] == 4 && map2[i][j + 1] != 2)
            {
                map2[i][j] = 4;
            }
            if (map2[i][j] == 2 && map2[i][j - 1] != 3 && map2[i][j + 1] == 4)
            {
                map2[i][j] = 4;
            }
            if (map2[i][j] == 2 && map2[i][j - 1] == 4 && map2[i][j + 1] != 3)
            {
                map2[i][j] = 4;
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (map2[i][j] == 0 || map2[i][j] == 1)
            {
                if (map2[i - 1][j] == 1 || map2[i - 1][j] == 3 || map2[i - 1][j] == 8 || map2[i - 1][j] == 12)
                {
                    map2[i][j] = 1;
                }
                if (map2[i - 1][j] == 0 || map2[i - 1][j] == 2 || map2[i - 1][j] == 7 || map2[i - 1][j] == 11)
                {
                    map2[i][j] = 0;
                }
                if (map2[i - 1][j] == 4 || map2[i - 1][j] == 5 || map2[i - 1][j] == 6 || map2[i - 1][j] == 9 ||
                    map2[i - 1][j] == 10)
                {
                    map2[i][j] = 0;
                }
            }
        }
    }
    
}

// line draw for player 2(blue)
void mapshow2()
{
    push_settings();
    apply_translate(-225, 320);
    set_outline_width(3);
    set_outline_color(0, 0, 255);
    for (int i = 2; i < 32; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (map2[i][j] == 7 && map2[i - 4][j - 1] == 8)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i - 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = (i - 4) * -20;
                int y4 = (i - 3) * -20;
                int x  = (j - 1) * 90;
                draw_line(x, y3, x, y4);
            }
            if (map2[i][j] == 8 && map2[i - 4][j - 1] == 7)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i - 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = i * -20;
                int y4 = (i + 1) * -20;
                int x  = j * 90;
                draw_line(x, y3, x, y4);
            }
            if (map2[i][j] == 11 && map2[i + 4][j - 1] == 12)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i + 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = (i + 4) * -20;
                int y4 = (i + 5) * -20;
                int x  = (j - 1) * 90;
                draw_line(x, y3, x, y4);
            }
            if (map2[i][j] == 12 && map2[i + 4][j - 1] == 11)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y1 = (i + 4) * -20;
                int y2 = i * -20;
                draw_line(x1, y1, x2, y2);
                int y3 = i * -20;
                int y4 = (i + 1) * -20;
                int x  = j * 90;
                draw_line(x, y3, x, y4);
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (map2[i][j] == 2 && map2[i][j - 1] == 3)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y  = i * -20;
                draw_line(x1, y, x2, y);
                int y1 = i * -20;
                int y2 = (i + 1) * -20;
                int x  = (j - 1) * 90;
                draw_line(x, y1, x, y2);
            }
            if (map2[i][j] == 3 && map2[i][j - 1] == 2)
            {
                int x1 = (j - 1) * 90;
                int x2 = j * 90;
                int y  = i * -20;
                draw_line(x1, y, x2, y);
                int y1 = i * -20;
                int y2 = (i + 1) * -20;
                int x  = j * 90;
                draw_line(x, y1, x, y2);
            }
        }
    }
    for (int i = 1; i < 33; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (map2[i - 1][j] == 1)
            {
                int y1 = (i - 1) * -20;
                int y2 = i * -20;
                int x  = j * 90;
                draw_line(x, y1, x, y2);
            }
        }
    }
    pop_settings();
}