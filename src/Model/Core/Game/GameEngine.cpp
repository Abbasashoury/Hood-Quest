#include "GameEngine.h"

void Gameengine::GameLoop()
{
    Cliview cli;
    InputHandler input;

    cli.PrintMainMenu();
    string CurrentUser = input.MainHandler();
    player player1(CurrentUser, 0, 0);
    if (CurrentUser != "Exit")
    {
        bool mode;
        while (true)
        {
            cli.displayGraph(player1.getPosition(), 'C'); // موقت
            mode = input.SelectModeofAlghorithms();
            switch (mode)
            {
            case true:
                cout << "Dijkstra selected\n";
                // dijkstraPrintPath();
                break;
            case false:
                cout << "A* selected\n";
                // AStarprintPath();
                break;
            default:
                cout << "Invalid mode selected\n";
            }
            input.CurrentHandler();
        }
    }
}