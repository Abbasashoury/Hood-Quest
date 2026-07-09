#include "GameEngine.h"

void Gameengine::GameLoop()
{
    Cliview cli;
    InputHandler input;
    // Gamestate gamestate;
    // Move move;
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
            char CurrentOrder = input.CurrentHandler();
            switch (CurrentOrder)
            {
            case '0':
                cout << "Undo selected\n";
                // gamastate.undo();
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'J':
            case 'K':
            case 'M':
            case 'W':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
                // move.moveplayer(CurrentOrder , CurrentUser);
            }
        }
    }
}