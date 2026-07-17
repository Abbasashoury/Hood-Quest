#include "GameEngine.h"

int main()
{
    // srand for the randomizer function 
    srand(time(0));
    // create engine of the game
    gameEngine engine;
    // start the game loop
    engine.GameLoop();

    return 0;
}