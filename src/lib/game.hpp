#pragma once

#include <graphics.h>
#include <random>
#include <time.h>
#include <iostream>
// #include <unistd.h>

#include "image.hpp"
#include "gameTime.hpp"
#include "animation.hpp"

namespace gp
{
    class Game
    {
        protected :
            Timer Time;
            bool quit = false;
        private :
            int page = 0;
            int frameCount = 0;
            int fps = 0;
            double time = 0;

            bool m_showFPS = 1;

        public :
            Game();
            virtual void init(bool fullScreen = 1, vector2 screenSize = vector2(1920, 1080), std::string title = "My Game");
            virtual void start();
            virtual void update();

            void showFPS(bool showFPS = true) { m_showFPS = showFPS; }
    };
} 
