#include <graphics.h>
#include <random>
#include <time.h>
#include <iostream>
#include <chrono>
#include <unistd.h>

#include "lib/image.hpp"
#include "lib/gameTime.hpp"

int main()
{
    gp::Timer Time;

    int page = 0;

    srand(time(NULL));
    initwindow(1024, 720, "My Window", 0, 0, true, true);

    int frameCount = 0;
    double time = 0;
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
    gp::vector2 scale(4, 4);

    double speed = 1000;

    while(1)
    {
        Time.start();

        setactivepage(page + 1);
        setvisualpage(1 - page + 1);
        page = 1 - page;
        
        cleardevice();
        //main game loop    

        moveVector = gp::vector2(0, 0);

        if (GetAsyncKeyState(VK_UP)) moveVector += gp::vector2(0, -1);
        if (GetAsyncKeyState(VK_DOWN)) moveVector += gp::vector2(0, 1);
        if (GetAsyncKeyState(VK_LEFT)) moveVector += gp::vector2(-1, 0);
        if (GetAsyncKeyState(VK_RIGHT)) moveVector += gp::vector2(1, 0);

        if (GetAsyncKeyState(VK_SPACE)) scale += gp::vector2(0.1, 0.1);
        
        viking.setScale(scale);

        position += moveVector * speed * Time.deltaTime();
        viking.setPosition(position);
        viking.draw();

        circle(viking.getPosition().getX(), viking.getPosition().getY(), 20);

        // fps counter
        frameCount++;
        time += Time.deltaTime();

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

        Time.end();
        std::cout<<"delta : "<<Time.deltaTime()<<std::endl;
    }   

}
