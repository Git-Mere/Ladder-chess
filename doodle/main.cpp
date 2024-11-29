// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#include "Tile.h"
#include "Tool.h"
#include "button.h"
#include "doodle/doodle.hpp"
#include "map.h"
#include "variable.h"
#include "sound.h"
#include <iostream>
#include <vector>
#include <string>

using namespace doodle;
using namespace std;
using namespace Tool;

constexpr void make_board();

int main()
{
    create_window("Team Protosstype", windowWidth, windowHeight);
    make_space();

    const Image DigiPen{"Image/DigiPen.png"};
    const Image kiyeong1{"Image/kiyeong1.png"};
    const Image kiyeong2{"Image/kiyeong2.png"};
    const Image kiyeong3{"Image/kiyeong3.png"};
    const Image davi1{"Image/davi1.png"};
    const Image davi2{"Image/davi2.png"};
    const Image davi3{"Image/davi3.png"};
    const Image LadderChess{"Image/Ladder Chess.png"};
    const Image main_k{"Image/main_k.png"};
    const Image main_d{"Image/main_d.png"};
    const Image How{"Image/How to Play.png"};

    double time{0};
    double alp{10};
    double TimeElapsed{0};
    set_image_mode(RectMode::Center);
    Sound sound;
    sound.Setup();

    while (!is_window_closed())
    {
        TimeElapsed += (ElapsedTime - time);
        time = ElapsedTime;
        update_window();
        clear_background(220);
        switch (scene)
        {
            case INTRO:
                if (intro1 == 0) {
                    sound.PlaySound(1);
                    intro1 = 1;
                }
                if (TimeElapsed < 3 && alp > 1)
                    alp -= 1;
                clear_background(255);
                draw_image(DigiPen, 0, 50, 482.5 * alp, 250 * alp);

                if (TimeElapsed > 3)
                {
                    TimeElapsed = 0;
                    alp         = 0;
                    scene       = INTRO2;
                }
                break;

            case INTRO2:
                if (intro2 == 0) {
                    sound.PlaySound(2);
                    intro2 = 1;
                }
                IntroL2(TimeElapsed, alp);
                break;

            case MAIN:
                reset();
                if (mainmenu == 0) {
                    sound.PlaySound(3);
                    mainmenu = 1;
                    ingame = 0;
                }
                if (button1 == 0) {
                    sound.PlaySound(5);
                    button1 = 1;
                    button2 = 0;
                    button3 = 0;
                }
                win = 0;
                push_settings();
                for (int i = 0; i <= 3; i++)
                    Button[i].IMadeButton();

                draw_image(LadderChess, 0, 150);
                draw_image(main_k, -360, -150);
                draw_image(main_d, 460, -150);

                set_font_size(15);
                draw_text("All content C 2020 DigiPen (USA) Corporation, all rights reserved.", -630, -350);
                pop_settings();

                break;

            case HOWTOPLAY:
                if (button2 == 0) {
                    sound.PlaySound(5);
                    button2 = 1;
                    button1 = 0;
                }
                draw_image(How, 0, 0);
                Button[4].IMadeButton();
                break;

            case CREDITS:
                if (button3 == 0) {
                    sound.PlaySound(5);
                    button3 = 1;
                    button1 = 0;
                }
                Credits();
                Button[4].IMadeButton(); 
                break;

            case INGAME:
                if (ingame == 0) {
                    sound.PlaySound(4);
                    ingame = 1;
                    mainmenu = 0;
                }
                if (TimeElapsed > 3)
                {
                    Win         = 0;
                    TimeElapsed = 0;
                }
                connect();

                for (Tile tile : Tiles)
                {
                    tile.draw();
                }
                make_board();

                modLine1();
                mapshow1();
                modLine2();
                mapshow2();

                rule();
                deter_mode();

                WhoIsWinner();
                if (WINNER == 0)
                {
                    draw_image(kiyeong1, -430, 250);
                    draw_image(davi1, 420, 250); 
                    if (turn == 2 && turnchange == 0) {
                        sound.PlaySound(0);
                        turnchange = 1;
                    }
                    if (turn == 1 && turnchange == 1) {
                        sound.PlaySound(0);
                        turnchange = 0;
                    }
                    win = 0;
                }
                else if (WINNER == 1)
                {
                    draw_image(kiyeong3, -430, 250);
                    draw_image(davi2, 420, 250);
                    if (win == 0) {
                        sound.PlaySound(6);
                        win = 1;
                    }
                }
                else if (WINNER == 2)
                {
                    draw_image(kiyeong2, -430, 250);
                    draw_image(davi3, 420, 250);
                    if (win == 0) {
                        sound.PlaySound(6);
                        win = 1;
                    }
                }

                push_settings();
                set_font_size(15);
                pop_settings();
                break;
                break;
            case QUIT: close_window(); break;

            default: break;
        }
    }
}

void on_key_released(KeyboardButtons button)
{
    if (button == KeyboardButtons::Escape)
        close_window();

    if (button == KeyboardButtons::R)
    {
        reset();
    }
}

void on_mouse_pressed(doodle::MouseButtons button)
{
    if (button == MouseButtons::Left)
    {
        Cho();
    }
}

void on_mouse_released(doodle::MouseButtons button)
{
    if (button == MouseButtons::Left && WINNER == 0)
    {
        for (int i = 0; i < Tiles.size(); i++)
        {
            Tiles[i].update();
        }
    }
    if (button == MouseButtons::Left)
    {
        ButtonRange(0, 3, MAIN);
        ButtonRange(4, HOWTOPLAY);
        ButtonRange(4, CREDITS);
        if (WINNER != 0)
            ButtonRange(5, INGAME);
    }
}

constexpr void make_board() {
    for (double i = 0; i < 6; i++)
    {
        draw_line(-225 + (i * 90), 320, -225 + (i * 90), -320);
    }
    for (double i = 0; i < 9; i++)
    {
        draw_line(-225, 320 - (i * 80), 225, 320 - (i * 80));
    };
}