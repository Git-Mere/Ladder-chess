// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#include "Tile.h"
#include "variable.h"
#include "doodle/doodle.hpp"
#include <iostream>

Tile::Tile(TileType tp, int p) { 
	type = tp;
    player = p;
    if (p == 1)
    {
        switch (type)
        {
            case TileType::one_block:
                position.x      = -550;
                position.y      = 100;
                position.width  = 90;
                position.height = 80;
                break;
            case TileType::one_block2:
                position.x      = -400;
                position.y      = 100;
                position.width  = 90;
                position.height = 80;
                break;
            case TileType::diagonal_l:
                position.x      = -550;
                position.y      = -100;
                position.width  = 90;
                position.height = 160;
                break;
            case TileType::diagonal_r:
                position.x      = -400;
                position.y      = -100;
                position.width  = 90;
                position.height = 160;
                break;
            case TileType::double_l:
                position.x      = -520;
                position.y      = -200;
                position.width  = 180;
                position.height = 80;
                break;
            case TileType::double_r:
                position.x      = -520;
                position.y      = -300;
                position.width  = 180;
                position.height = 80;
                break;
        }
    }
    if (p == 2)
    {
        switch (type)
        {
            case TileType::one_block:
                position.x      = 300;
                position.y      = 100;
                position.width  = 90;
                position.height = 80;
                break;
            case TileType::one_block2:
                position.x      = 450;
                position.y      = 100;
                position.width  = 90;
                position.height = 80;
                break;
            case TileType::diagonal_l:
                position.x      = 300;
                position.y      = -100;
                position.width  = 90;
                position.height = 160;
                break;
            case TileType::diagonal_r:
                position.x      = 450;
                position.y      = -100;
                position.width  = 90;
                position.height = 160;
                break;
            case TileType::double_l:
                position.x      = 330;
                position.y      = -200;
                position.width  = 180;
                position.height = 80;
                break;
            case TileType::double_r:
                position.x      = 330;
                position.y      = -300;
                position.width  = 180;
                position.height = 80;
                break;
        }
    }
}

void Tile::draw() { 
    using namespace doodle;
    push_settings();
    set_outline_width(2);
    set_outline_color(120);
    draw_rectangle(position.x, position.y, position.width, position.height);
    pop_settings();
    push_settings();
    set_font_size(30);
    draw_text("P1", -450, 295);
    draw_text("P2", 400, 295);

    if (mod == 2)
    {
        set_font_size(25);
        draw_text("You used all the blocks.", -620, 100);
        draw_text("You used all the blocks.", 260, 100);
        draw_text("You can now move", -600, 0);
        draw_text("the blocks one by one", -600, -50);
        draw_text("You can now move", 280, 0);
        draw_text("the blocks one by one", 280, -50);
    }
    set_outline_width(2);
    set_fill_color(255);
    draw_ellipse(-135, 335, 24);
    draw_triangle(123, 324, 135, 348, 147, 324);
    draw_ellipse(135, -335, 24);
    draw_triangle(-123, -348, -135, -324, -147, -348);
    
    pop_settings();
    double x = position.x;
    double y = position.y;
    double w = position.width;
    double h = position.height;

        if (now_click == true)
        {
            push_settings();
            set_outline_width(2);
            draw_ellipse(x + 45, y + 40, 20);
            pop_settings();
        }
        if (onoff == true)
        {
            switch (type)
            {
                case TileType::one_block:
                    push_settings();
                    set_outline_width(2);
                    set_outline_color(255, 0, 0);
                    draw_line(x, (y + y + h) / 2, x + w, (y + y + h) / 2);
                    pop_settings();
                    break;

                case TileType::one_block2:
                    push_settings();
                    set_outline_width(2);
                    set_outline_color(255, 0, 0);
                    draw_line(x, (y + y + h) / 2, x + w, (y + y + h) / 2);
                    pop_settings();
                    break;

                case TileType::diagonal_l:

                    draw_line(x, (y + (y + h)) / 2, x + w, (y + (y + h)) / 2);
                    push_settings();
                    set_outline_width(2);
                    set_outline_color(255, 0, 0);
                    draw_line(x, (h / 4 * 3) + y, x + w, (h / 4) + y);
                    pop_settings();
                    break;
                case TileType::diagonal_r:

                    draw_line(x, (y + (y + h)) / 2, x + w, (y + (y + h)) / 2);
                    push_settings();
                    set_outline_width(2);
                    set_outline_color(255, 0, 0);
                    draw_line(x, (h / 4) + y, x + w, (h / 4 * 3) + y);
                    pop_settings();
                    break;
                case TileType::double_l:

                    draw_line((x + (x + w)) / 2, y, (x + (x + w)) / 2, y + h);
                    push_settings();
                    set_outline_width(2);
                    set_outline_color(255, 0, 0);
                    draw_line(x, (h / 4 * 3) + y, x + w / 2, (h / 4 * 3) + y);
                    draw_line(x + w / 2, (h / 4) + y, x + w, (h / 4) + y);
                    pop_settings();
                    break;
                case TileType::double_r:

                    draw_line((x + (x + w)) / 2, y, (x + (x + w)) / 2, y + h);
                    push_settings();
                    set_outline_width(2);
                    set_outline_color(255, 0, 0);
                    draw_line(x, (h / 4) + y, x + w / 2, (h / 4) + y);
                    draw_line(x + w / 2, (h / 4 * 3) + y, x + w, (h / 4 * 3) + y);
                    pop_settings();
                    break;
            }
        }
    
}

void Tile::update()
{
    if (mod == 1)
    {
        if (player == turn)
        {
            if (onoff == true)
            {
                tilemove();
            }
        }
    }
    if (mod == 2)
    { 
       tilemove2();   
    }
}

void Tile::tilemove(){
    int mouseX = get_mouse_x();
    int mouseY = get_mouse_y();
        if (now_click == false && only_one_tile == false && mouseX >= position.x &&
            mouseX <= position.x + position.width && mouseY >= position.y && mouseY <= position.y + position.height)
        {
            now_click     = true;
            only_one_tile = true;
        }
        else if (now_click == true && only_one_tile == true && mouseX >= position.x &&
                 mouseX <= position.x + position.width && mouseY >= position.y &&
                 mouseY <= position.y + position.height)
        {
            now_click     = false;
            only_one_tile = false;
            choice        = 0;
        };
        switch (choice)
        {
            case 1: tilemove_helper1(mouseX, mouseY); break;
            case 2: tilemove_helper2(mouseX, mouseY); break;
            case 3: tilemove_helper3(mouseX, mouseY); break;
            case 4: tilemove_helper4(mouseX, mouseY); break;
            case 5: tilemove_helper5(mouseX, mouseY); break;
        }
};

void Tile::tilemove_helper1(int& mouseX, int& mouseY)
{
    for (int i = 0; i < spaces.size(); i++)
    {
        if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
            mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].check == true &&
            spaces[i].occupy == false)
        {
            now_click         = false;
            only_one_tile     = false;
            choice            = 0;
            onoff             = false;
            position.x        = spaces[i].x;
            position.y        = spaces[i].y;
            position.num      = i;
            spaces[i].occupy  = true;
            spaces[i].point_l = true;
            spaces[i].point_r = true;
            spaces[i].check   = false;
            if (turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
    }
}

void Tile::tilemove_helper2(int& mouseX, int& mouseY)
{
    for (int i = 5; i < spaces.size(); i++)
    {
        int im = i - 5;
        if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
            mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].check == true &&
            spaces[i].occupy == false && spaces[im].occupy == false)
        {
            now_click             = false;
            only_one_tile         = false;
            choice                = 0;
            onoff                 = false;
            position.x            = spaces[i].x;
            position.y            = spaces[i].y;
            position.num          = i;
            spaces[i].occupy      = true;
            spaces[im].occupy  = true;
            spaces[i].point_r     = true;
            spaces[im].point_l = true;

            spaces[i].check = false;
            if (turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
    }
}

void Tile::tilemove_helper3(int& mouseX, int& mouseY)
{
    for (int i = 5; i < spaces.size(); i++)
    {
        int im = i - 5;
        if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
            mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].check == true &&
            spaces[i].occupy == false && spaces[im].occupy == false)
        {
            now_click             = false;
            only_one_tile         = false;
            choice                = 0;
            onoff                 = false;
            position.x            = spaces[i].x;
            position.y            = spaces[i].y;
            position.num          = i;
            spaces[i].occupy      = true;
            spaces[im].occupy  = true;
            spaces[i].point_l     = true;
            spaces[im].point_r = true;
            if (turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
    }
}

void Tile::tilemove_helper4(int& mouseX, int& mouseY)
{
    for (int i = 0; i < spaces.size()-1; i++)
    {
        int ip = i + 1;
        if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
            mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].occupy == false &&
            spaces[ip].occupy == false && spaces[i].d_check == true)
        {
            now_click               = false;
            only_one_tile           = false;
            choice                  = 0;
            onoff                   = false;
            position.x              = spaces[i].x;
            position.y              = spaces[i].y;
            position.num            = i;
            spaces[i].occupy        = true;
            spaces[ip].occupy    = true;
            spaces[i].u_point_r     = true;
            spaces[i].u_point_l     = true;
            spaces[ip].d_point_r = true;
            spaces[ip].d_point_l = true;
            if (turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
    }
}

void Tile::tilemove_helper5(int& mouseX, int& mouseY)
{
    for (int i = 0; i < spaces.size()-1; i++)
    {
        int ip = i + 1;
        if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
            mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].occupy == false &&
            spaces[ip].occupy == false && spaces[i].d_check == true)
        {
            now_click               = false;
            only_one_tile           = false;
            choice                  = 0;
            onoff                   = false;
            position.x              = spaces[i].x;
            position.y              = spaces[i].y;
            position.num            = i;
            spaces[i].occupy        = true;
            spaces[ip].occupy    = true;
            spaces[i].d_point_r     = true;
            spaces[i].d_point_l     = true;
            spaces[ip].u_point_r = true;
            spaces[ip].u_point_l = true;
            if (turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
    }
}
    


void Tile::tilemove2()
{
    int mouseX = get_mouse_x();
    int mouseY = get_mouse_y();
    if (choice == 1)
    {
        for (int i = 0; i < spaces.size(); i++)
        {
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height)
            {
                if (now_click == false && only_one_tile == false && mouseX >= position.x &&
                    mouseX <= position.x + position.width && mouseY >= position.y &&
                    mouseY <= position.y + position.height)
                {
                    now_click         = true;
                    only_one_tile     = true;
                    spaces[i].occupy  = false;
                    spaces[i].point_l = false;
                    spaces[i].point_r = false;
                }
                else if (now_click == true && only_one_tile == true && mouseX >= position.x &&
                         mouseX <= position.x + position.width && mouseY >= position.y &&
                         mouseY <= position.y + position.height)
                {
                    now_click         = false;
                    only_one_tile     = false;
                    choice            = 0;
                    spaces[i].occupy  = true;
                    spaces[i].point_l = true;
                    spaces[i].point_r = true;
                };
            }
        }
    }
    else if(choice == 2)
    {
        for (int i = 5; i < spaces.size(); i++)
        {
            int im = i - 5;
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height)
            {
                
                    if (now_click == false && only_one_tile == false && mouseX >= position.x &&
                    mouseX <= position.x + position.width && mouseY >= position.y &&
                    mouseY <= position.y + (position.height/2))
                {
                    now_click             = true;
                    only_one_tile         = true;
                    spaces[i].occupy      = false;
                    spaces[im].occupy  = false;
                    spaces[i].point_r     = false;
                    spaces[im].point_l = false;
                }
                else if (now_click == true && only_one_tile == true && mouseX >= position.x &&
                         mouseX <= position.x + position.width && mouseY >= position.y &&
                         mouseY <= position.y + (position.height / 2))
                {
                    now_click             = false;
                    only_one_tile         = false;
                    choice                = 0;
                    spaces[i].occupy      = true;
                    spaces[im].occupy  = true;
                    spaces[i].point_r     = true;
                    spaces[im].point_l = true;
                }
                
            }
        }
    }
    else if(choice == 3)
    {
        for (int i = 5; i < spaces.size(); i++)
        {
            int im = i - 5;
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height)
            {
                if (now_click == false && only_one_tile == false && mouseX >= position.x &&
                    mouseX <= position.x + position.width && mouseY >= position.y &&
                    mouseY <= position.y + (position.height / 2))
                {
                    now_click             = true;
                    only_one_tile         = true;
                    spaces[i].occupy      = false;
                    spaces[im].occupy  = false;
                    spaces[i].point_l     = false;
                    spaces[im].point_r = false;
                }
                else if (now_click == true && only_one_tile == true && mouseX >= position.x &&
                         mouseX <= position.x + position.width && mouseY >= position.y &&
                         mouseY <= position.y + (position.height / 2))
                {
                    now_click             = false;
                    only_one_tile         = false;
                    choice                = 0;
                    spaces[i].occupy      = true;
                    spaces[im].occupy  = true;
                    spaces[i].point_l     = true;
                    spaces[im].point_r = true;
                };
            }
        }
    }
    else if(choice == 4)
    {
        for (int i = 0; i < spaces.size(); i++)
        {
            int ip1 = i + 1;
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height)
            {
                
                    if (now_click == false && only_one_tile == false && mouseX >= position.x &&
                        mouseX <= position.x + (position.width/2) && mouseY >= position.y &&
                        mouseY <= position.y + position.height)
                    {
                        now_click               = true;
                        only_one_tile           = true;
                        spaces[i].occupy        = false;
                        spaces[ip1].occupy    = false;
                        spaces[i].u_point_l     = false;
                        spaces[i].u_point_r     = false;
                        spaces[ip1].d_point_r = false;
                        spaces[ip1].d_point_l = false;
                    }
                    else if (now_click == true && only_one_tile == true && mouseX >= position.x &&
                             mouseX <= position.x + (position.width / 2) && mouseY >= position.y &&
                             mouseY <= position.y + position.height)
                    {
                        now_click               = false;
                        only_one_tile           = false;
                        choice                  = 0;
                        spaces[i].occupy        = true;
                        spaces[ip1].occupy    = true;
                        spaces[i].u_point_l     = true;
                        spaces[i].u_point_r     = true;
                        spaces[ip1].d_point_r = true;
                        spaces[ip1].d_point_l = true;
                    };
                
            }
        }
    }
    else if (choice == 5)
    {
        for (int i = 0; i < spaces.size(); i++)
        {
            int ip1 = i + 1;
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height)
            {
                if (now_click == false && only_one_tile == false && mouseX >= position.x &&
                    mouseX <= position.x + (position.width / 2) && mouseY >= position.y &&
                    mouseY <= position.y + position.height)
                {
                    now_click               = true;
                    only_one_tile           = true;
                    spaces[i].occupy        = false;
                    spaces[ip1].occupy    = false;
                    spaces[i].d_point_l     = false;
                    spaces[i].d_point_r     = false;
                    spaces[ip1].u_point_r = false;
                    spaces[ip1].u_point_l = false;
                }
                else if (now_click == true && only_one_tile == true && mouseX >= position.x &&
                         mouseX <= position.x + (position.width / 2) && mouseY >= position.y &&
                         mouseY <= position.y + position.height)
                {
                    now_click               = false;
                    only_one_tile           = false;
                    choice                  = 0;
                    spaces[i].occupy        = true;
                    spaces[ip1].occupy    = true;
                    spaces[i].d_point_l     = true;
                    spaces[i].d_point_r     = true;
                    spaces[ip1].u_point_r = true;
                    spaces[ip1].u_point_l = true;
                };
            }
        }
    }
    switch (choice)
    {
        case 1: tilemove2_helper1(mouseX, mouseY); break;
        case 2: tilemove2_helper2(mouseX, mouseY); break;
        case 3: tilemove2_helper3(mouseX, mouseY); break;
        case 4: tilemove2_helper4(mouseX, mouseY); break;
        case 5: tilemove2_helper5(mouseX, mouseY); break;
    }
}

void Tile::tilemove2_helper1(int& mouseX, int& mouseY)
{
    for (int i = 0; i < spaces.size(); i++)
    {
        int i1 = 2 + ((position.num / 5) * 4);
        int i2 = (position.num % 5) + 1;
        int i3 = (position.num % 5);
        if (position.num == i + 1 || position.num == i - 1 || position.num == i + 5 || position.num == i - 5)
        {
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].check == true &&
                spaces[i].occupy == false)
            {
                spaces[position.num].occupy  = false;
                spaces[position.num].point_l = false;
                spaces[position.num].point_r = false;

                map1[i1][i2] = 0;
                map2[i1][i2] = 0;
                map1[i1][i3] = 0;
                map2[i1][i3] = 0;

                now_click         = false;
                only_one_tile     = false;
                choice            = 0;
                onoff             = false;
                position.x        = spaces[i].x;
                position.y        = spaces[i].y;
                position.num      = i;
                spaces[i].occupy  = true;
                spaces[i].point_l = true;
                spaces[i].point_r = true;

                if (turn == 1)
                {
                    turn = 2;
                }
                else
                {
                    turn = 1;
                }
            }
        }
    }
}

void Tile::tilemove2_helper2(int& mouseX, int& mouseY) {
    for (int i = 5; i < spaces.size(); i++)
    {
        int im = i - 5;
        int pm = position.num - 5;
        int i1 = 2 + ((position.num / 5) * 4) - 4;
        int i2 = (position.num % 5);
        int i3 = 2 + ((position.num / 5) * 4);
        int i4 = (position.num % 5) + 1;
        if (position.num == i + 1 || position.num == i - 1 || position.num == i + 5 || position.num == i - 5)
        {
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].check == true &&
                spaces[i].occupy == false && spaces[im].occupy == false)
            {
                spaces[position.num].occupy      = false;
                spaces[pm].occupy  = false;
                spaces[pm].point_l = false;
                spaces[position.num].point_r     = false;

                map1[i1][i2] = 0;
                map2[i1][i2] = 0;
                map1[i3][i4] = 0;
                map2[i3][i4] = 0;

                now_click             = false;
                only_one_tile         = false;
                choice                = 0;
                onoff                 = false;
                position.x            = spaces[i].x;
                position.y            = spaces[i].y;
                position.num          = i;
                spaces[i].occupy      = true;
                spaces[im].occupy  = true;
                spaces[im].point_l = true;
                spaces[i].point_r     = true;

                if (turn == 1)
                {
                    turn = 2;
                }
                else
                {
                    turn = 1;
                }
            }
        }
    }
}
void Tile::tilemove2_helper3(int& mouseX, int& mouseY)
{
    for (int i = 5; i < spaces.size(); i++)
    {
        int im = i - 5;
        int pm = position.num - 5;
        int i1 = 2 + ((position.num / 5) * 4);
        int i2 = (position.num % 5);
        int i3 = 2 + ((position.num / 5) * 4) - 4;
        int i4 = (position.num % 5) + 1;
        if (position.num == i + 1 || position.num == i - 1 || position.num == i + 5 || position.num == i - 5)
        {
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].check == true &&
                spaces[i].occupy == false && spaces[im].occupy == false)
            {
                spaces[position.num].occupy      = false;
                spaces[pm].occupy  = false;
                spaces[pm].point_r = false;
                spaces[position.num].point_l     = false;

                map1[i1][i2] = 0;
                map2[i1][i2] = 0;
                map1[i3][i4] = 0;
                map2[i3][i4] = 0;

                now_click             = false;
                only_one_tile         = false;
                choice                = 0;
                onoff                 = false;
                position.x            = spaces[i].x;
                position.y            = spaces[i].y;
                position.num          = i;
                spaces[i].occupy      = true;
                spaces[im].occupy  = true;
                spaces[im].point_r = true;
                spaces[i].point_l     = true;


                if (turn == 1)
                {
                    turn = 2;
                }
                else
                {
                    turn = 1;
                }
            }
        }
    }
}
void Tile::tilemove2_helper4(int& mouseX, int& mouseY)
{
    for (int i = 0; i < spaces.size() - 1; i++)
    {
        int ip = i + 1;
        int pp = position.num + 1;
        int i1 = 1 + ((position.num / 5) * 4);
        int i2 = (position.num % 5);
        int i3 = (position.num % 5) + 1;
        int i4 = 3 + ((position.num / 5) * 4);
        int i5 = (position.num % 5) + 1;
         int i6 = (position.num % 5) + 2;
        if (position.num == i + 1 || position.num == i - 1 || position.num == i + 5 || position.num == i - 5)
        {
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].occupy == false &&
                spaces[ip].occupy == false && spaces[i].d_check == true)
            {
                spaces[position.num].occupy        = false;
                spaces[pp].occupy    = false;
                spaces[position.num].u_point_r     = false;
                spaces[position.num].u_point_l     = false;
                spaces[pp].d_point_r = false;
                spaces[pp].d_point_l = false;

                map1[i1][i2] = 0;
                map2[i1][i2] = 0;
                map1[i1][i3] = 0;
                map2[i1][i3] = 0;
                map1[i4][i5] = 0;
                map2[i4][i5] = 0;
                map1[i4][i6] = 0;
                map2[i4][i6] = 0;

                now_click               = false;
                only_one_tile           = false;
                choice                  = 0;
                onoff                   = false;
                position.x              = spaces[i].x;
                position.y              = spaces[i].y;
                position.num            = i;
                spaces[i].occupy        = true;
                spaces[ip].occupy    = true;
                spaces[i].u_point_r     = true;
                spaces[i].u_point_l     = true;
                spaces[ip].d_point_r = true;
                spaces[ip].d_point_l = true;

                if (turn == 1)
                {
                    turn = 2;
                }
                else
                {
                    turn = 1;
                }
            }
        }
    }
}

void Tile::tilemove2_helper5(int& mouseX, int& mouseY)
{
    for (int i = 0; i < spaces.size() - 1; i++)
    {
        int ip = i + 1;
        int pp = position.num + 1;
        int i1 = 3 + ((position.num / 5) * 4);
        int i2 = (position.num % 5);
        int i3 = (position.num % 5) + 1;
        int i4 = 1 + ((position.num / 5) * 4);
        int i5 = (position.num % 5) + 1;
        int i6 = (position.num % 5) + 2;
        if (position.num == i + 1 || position.num == i - 1 || position.num == i + 5 || position.num == i - 5)
        {
            if (mouseX >= spaces[i].x && mouseX <= spaces[i].x + spaces[i].width && mouseY >= spaces[i].y &&
                mouseY <= spaces[i].y + spaces[i].height && now_click == true && spaces[i].occupy == false &&
                spaces[ip].occupy == false && spaces[i].d_check == true)
            {
                spaces[position.num].occupy        = false;
                spaces[pp].occupy    = false;
                spaces[position.num].d_point_r     = false;
                spaces[position.num].d_point_l     = false;
                spaces[pp].u_point_r = false;
                spaces[pp].u_point_l = false;

                map1[i1][i2] = 0;
                map2[i1][i2] = 0;
                map1[i1][i3] = 0;
                map2[i1][i3] = 0;
                map1[i4][i5] = 0;
                map2[i4][i5] = 0;
                map1[i4][i6] = 0;
                map2[i4][i6] = 0;

                now_click               = false;
                only_one_tile           = false;
                choice                  = 0;
                onoff                   = false;
                position.x              = spaces[i].x;
                position.y              = spaces[i].y;
                position.num            = i;
                spaces[i].occupy        = true;
                spaces[ip].occupy    = true;
                spaces[i].d_point_r     = true;
                spaces[i].d_point_l     = true;
                spaces[ip].u_point_r = true;
                spaces[ip].u_point_l = true;

                if (turn == 1)
                {
                    turn = 2;
                }
                else
                {
                    turn = 1;
                }
            }
        }
    }
}
