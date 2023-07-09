#include "lib/game.hpp"

namespace gp 
{
    Game::Game() 
    {
        
    }
    
    void Game::init(bool fullScreen, vector2 screenSize, std::string title)
    {
        std::string title_str;
        
        int left;
        int top;

        if (fullScreen) 
        {
            std::cout<<"Full Screen"<<std::endl;
            title_str = "";
            left = -11;
            top = -11;
        }
        else
        {
            std::cout<<"Not Full Screen"<<std::endl;
            std::cout<<"title : "<<title<<std::endl;
            title_str = title;
            std::cout<<"title_str : "<<title_str<<std::endl;
            left = 0;
            top = 0;
        }

        initwindow(screenSize.getX() , screenSize.getY(), title_str.c_str(), left, top);
        
        // initwindow(1920 , 1080, "", -11, -11);

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
            if (quit) 
            {
                std::cout<<"Quit"<<std::endl;
                quit = false;
                return;
            }
            // fps counter
            if (m_showFPS)
            {
                frameCount++;
                time += Time.deltaTime();

                if (fps == 0 && Time.deltaTime() > 0)
                {
                    fps = 1 / Time.deltaTime();
                }

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
        }   
    }

    void Game::start()
    {
        std::cout<<"Function Start not found"<<std::endl;
    }

    void Game::update() 
    {
        std::cout<<"Function Update not found"<<std::endl;
    }

}