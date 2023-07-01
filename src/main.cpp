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

    int frameCount = 0;
    float time = 0;
    int fps = 0;

    setactivepage(0);
    setvisualpage(1);

    gp::image viking;
    viking.load("Image/attack1_1.gif", 100, 65);
    viking.setScale(4, 4);
    viking.setOrigin(40, 42.5);
    viking.setPosition(300, 300);

    gp::vector2 position(300 ,300);
    gp::vector2 moveVector;

    float speed = 0.3;

    while(1)
    {
        //time count start
        auto timeStart = std::chrono::steady_clock::now();

        //main game loop    
        setactivepage(page);
        setvisualpage(1 - page);
        page = 1 - page;
        
        cleardevice();

        moveVector = gp::vector2(0, 0);

        if (GetAsyncKeyState(VK_UP)) moveVector += gp::vector2(0, -1);
        if (GetAsyncKeyState(VK_DOWN)) moveVector += gp::vector2(0, 1);
        if (GetAsyncKeyState(VK_LEFT)) moveVector += gp::vector2(-1, 0);
        if (GetAsyncKeyState(VK_RIGHT)) moveVector += gp::vector2(1, 0);

        if (GetAsyncKeyState(VK_SPACE)) 
        {
            if (viking.getScale().getX() != 8) viking.setScale(8, 8);
        }

        
        position += moveVector * speed;
        viking.setPosition(position);
        viking.draw();

        // circle(x, y, 20);

        //fps counter
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

