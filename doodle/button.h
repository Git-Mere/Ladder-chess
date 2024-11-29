// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#pragma once
#include <string>

using namespace std;

class MadeButton
{
private:
    bool   onMouse   = false;
    bool   onPressed = false;
    bool   onClicked = false;
    string Btext;

public:
    double x{0.0}, y{0.0}, Width{0.0}, Height{0.0}, WidthDiv{0.0};
    int    r{0}, g{0}, b{0}, a{0}, scene{0};

    MadeButton(double x2, double y2, double Width2, double TextSize, int r2, int g2, int b2, int a2, string text,
               int scene2);

    void MadeColorButton();

    void MadeText();

    void SetRangeButton();


    void IMadeButton()
    {
        SetRangeButton();

        MadeColorButton();

        MadeText();
    };
};
