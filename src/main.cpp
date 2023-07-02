#include "lib/game.hpp"

class myGame : public gp::Game
{
    private:
        //game Variables
        gp::image viking;
        gp::vector2 position = gp::vector2(300 ,300);
        gp::vector2 moveVector;
        gp::vector2 scale = gp::vector2(4, 4);
        double speed = 300;
        
    public:
        void start()
        {
            viking.load("Image/attack1_1.gif", 100, 65);
            viking.setScale(4, 4);
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
            
            viking.setScale(scale);

            position += moveVector * speed * Time.deltaTime();
            viking.setPosition(position);
            viking.draw();

            circle(viking.getPosition().getX(), viking.getPosition().getY(), 20);
        }
};

int main()
{
    myGame game;
    game.showFPS();
    game.init();
    return 0;
}
