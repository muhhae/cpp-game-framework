# cpp-game-framework
C++ 2D Game Framework build upon graphics.h library. 
- Image handler

# Prerequisities
- 32 bit compiler, graphics.h doesn't support 64 bit.
- graphics.h library

# Manual
1. Create class myGame that derived from gp::Game
2. Add void update() and void start()
3. Call init from myGame

### Example :
```
class myGame : gp::Game {
    private :
        
    public : 
        void update() {

        }

        void start() {

        }
}

int main() {
    myGame game;
    game.init();
    return 0;
}
```

```
void start() --> called the first time game started
void update() --> called every frame
```
