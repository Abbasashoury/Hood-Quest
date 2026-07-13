#include "GameEngine.h"

void Gameengine::GameLoop()
{
    Cliview cli;
    InputHandler input;
    Move move;

    Graph graph;
    Stack stack;

    cli.PrintMainMenu();
    string CurrentUser = input.MainHandler();

    Player player1(CurrentUser, 'a', 0);
    Wolf wolf('d');
    GameState gamestate(player1, wolf);

    if (CurrentUser != "Exit")
    {
        bool mode;
        while (true)
        {
            cli.displayGraph(player1.getPosition(), wolf.getPosition());
            mode = input.SelectModeofAlghorithms();
            switch (mode)
            {
            case true:
                cout << "Dijkstra selected\n";
                dijkstraPrintPath(graph, player1.getPosition(), 'V', wolf.getPosition());
                break;
            case false:
                cout << "A* selected\n";
                AStarprintPath(graph, player1.getPosition(), 'V', wolf.getPosition());
                break;
            default:
                cout << "Invalid mode selected\n";
            }
            char CurrentOrder = input.CurrentHandler();
            switch (CurrentOrder)
            {
            case '0':
                cout << "Undo selected\n";
                gamestate.undo(player1, wolf, stack);
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
                move.movePlayer(graph, player1, CurrentOrder);
            default:
                cout << "Invalid order selected\n";
            }
        }
    }
}