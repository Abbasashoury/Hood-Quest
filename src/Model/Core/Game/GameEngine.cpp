#include "GameEngine.h"

void Gameengine::GameLoop()
{
    Cliview cli;
    InputHandler input;
    cli.PrintMainMenu();
    string CurrentUser = input.MainHandler();
    player player1(CurrentUser,0,0);
    if (CurrentUser != "Exit")
    {
        cli.displayGraph(player1.getPosition(),'C');// موقت
        input.CurrentHandler();

    }
}