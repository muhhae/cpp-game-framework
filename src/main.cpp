#include <graphics.h>
#include <random>
#include <time.h>
#include <iostream>
#include <chrono>
#include <unistd.h>

#include "lib/image.hpp"

int main()
{

    int page = 0;

    srand(time(NULL));
    initwindow(1024, 720, "My Window", 0, 0, true, true);

    setactivepage(0);
    setvisualpage(1);

    float x = rand() % 1024;
    float y = rand() % 720;

    int frameCount = 0;
    float time = 0;
    int fps = 0;

    while(1)
    {
        auto timeStart = std::chrono::steady_clock::now();

        setactivepage(page);
        setvisualpage(1 - page);
        page = 1 - page;
        
        cleardevice();

        if (GetAsyncKeyState(VK_UP)) y--;
        if (GetAsyncKeyState(VK_DOWN)) y++;
        if (GetAsyncKeyState(VK_LEFT)) x--;
        if (GetAsyncKeyState(VK_RIGHT)) x++;

        circle(x, y, 20);

        auto timeEnd = std::chrono::steady_clock::now();

        float deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();

        frameCount++;
        time += deltaTime / 1000000000;

        if (time >= 1) 
        {
            fps = frameCount;

            time = 0;
            frameCount = 0;

        }

        std::string fps_str = std::to_string(fps);
        char * fps_show = new char[fps_str.length() + 1];
        strcpy(fps_show, fps_str.c_str());

        outtextxy(10, 10, "FPS : ");
        outtextxy(50, 10, fps_show);

        delete fps_show;
    }   

}

