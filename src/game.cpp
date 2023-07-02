#include "lib/game.hpp"

namespace gp 
{
    Game::Game() 
    {
        
    }
    
    void Game::init()
    {
        initwindow(1024, 720, "My Window", 0, 0, true, true);

        setactivepage(0);
        setvisualpage(1);

        start();

        while(1)
        {
            Time.start();

            setactivepage(page + 1);
            setvisualpage(1 - page + 1);
            page = 1 - page;
            cleardevice();

            //main game loop    
            update();

            // fps counter
            if (m_showFPS)
            {
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
            }

            Time.end();
            std::cout<<"delta : "<<Time.deltaTime()<<std::endl;
        }   
    }

    void Game::start()
    {
        
    }

    void Game::update() 
    {
        
    }
}