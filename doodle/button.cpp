// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#include "button.h"
#include <doodle/doodle.hpp>
#include <iostream>


using namespace doodle;

using namespace std;

constexpr int half{2};


MadeButton ::MadeButton(double x2, double y2, double Width2, double TextSize, int r2, int g2, int b2, int a2,
                        string text, int scene2)
{
    x      = x2;
    y      = y2;
    Width  = Width2;
    Height = TextSize;

    r = r2;
    g = g2;
    b = b2;
    a = a2;

    Btext = text;
    scene = scene2;
};

void MadeButton ::SetRangeButton()
{
    double MX = get_mouse_x();
    double MY = get_mouse_y();


    if ((MX > x && MX < x + Width) && (MY > y && MY < y + Height))
    {
        onMouse = true;

        if (MouseIsPressed)
        {
            onPressed = true;
        }
        else
            onPressed = false;
    }
    else
        onMouse = false;
};

void MadeButton ::MadeColorButton()
{
    if (onMouse)
    {
        if (onPressed)
        {
            set_fill_color(r, g / half, b / half, a);
        }
        else
            set_fill_color(r, g, b, a / half);
    }
    else
        set_fill_color(r, g, b, a);

    draw_rectangle(x, y, Width, Height);
};

void MadeButton ::MadeText()
{
    set_fill_color(255);
    set_font_size(Height / half);
    set_outline_color(0);
    draw_text(Btext, x, y);
}
