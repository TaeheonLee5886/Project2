#pragma once
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include <vector>

using namespace std;

class Bullet{
    public:
        Bullet(int y_value, int x_value, int frame_value){y=y_value; x=x_value; create_frame_bullet=frame_value;};
        int damage=1;
        int y, x;
        int create_frame_bullet; //initialize when it creates
        int check_frame_bullet;
        int cell_speed_bullet=3;
        int level=1;
};

class My_plane{
    public:
        My_plane(int y_value, int x_value, int frame_value){y=y_value; x=x_value; create_frame_my_plane=frame_value;};
        int y, x;
        int shot_frame_my_plane=1;
        int create_frame_my_plane; //initialize when it creates
        int check_frame_my_plane=0;
        int cell_speed_my_plane=1;
        vector<Bullet> bullet;
};

//Screen manager.
class Screen_manager{
    public:
        int frame_length=100000; //each frame's length == 0.1sec(10,000 microseconds)
        int curr_frame=0; //1frame=0.1sec

        int y, x;
        int width=60;
        int height=30;
        int frame_event[300]={0,}, y_event[300]={0,}, x_event[300]={0,};
        char type_event[300] = {' ',};

        void print(int ascii);
        void print();
        void print_share();
        void render();
        char board[30][60]={'a'};
        My_plane my_plane = My_plane(height-2, 1, 0);
};