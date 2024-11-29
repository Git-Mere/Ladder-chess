// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#pragma once
struct pos
{
    double x{0};
    double y{0};

    int num = 0;
    
    double width{0};
    double height{0};

    bool occupy   = false;

    bool point_l = false;
    bool point_r = false;
    
    bool u_point_l = false;
    bool u_point_r = false;
    bool d_point_l = false;
    bool d_point_r = false;

    bool check = false;
    bool d_check = false;
};