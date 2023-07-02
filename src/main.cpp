#include "lib/game.hpp"

class myGame : public gp::Game
{
    private:
        //game Variables
        gp::vector2 position = gp::vector2(300 ,300);
        gp::vector2 moveVector;
        gp::vector2 scale = gp::vector2(4, 4);
        double speed = 300;

        gp::animation viking; 
        
    public:
        void start()
        {
            viking.setScale(4, 4);
            viking.load("Image/viking/animation/idle", 100, 65);
            viking.setFrameRate(6);
            viking.setOrigin(40, 42.5);
            viking.setPosition(300, 300);
        }
        void update()
        {
            moveVector = gp::vector2(0, 0);

            if (GetAsyncKeyState(VK_UP)) moveVector += gp::vector2(0, -1);
            if (GetAsyncKeyState(VK_DOWN)) moveVector += gp::vector2(0, 1);
            if (GetAsyncKeyState(VK_LEFT)) moveVector += gp::vector2(-1, 0);
            if (GetAsyncKeyState(VK_RIGHT)) moveVector += gp::vector2(1, 0);

            if (GetAsyncKeyState(VK_SPACE)) scale += gp::vector2(0.1, 0.1);

            // viking.setScale(scale);

            position += moveVector * speed * Time.deltaTime();

            viking.setPosition(position);
            viking.draw(Time.deltaTime());

            if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
        }
};

int main()
{
    myGame game;
    game.showFPS();
    game.init();
    return 0;
}
