#include "GameEngine.h"

void Gameengine::GameLoop()
{
    Cliview cli;
    InputHandler input;
    Move move;

    Graph graph;
    Stack stack;
    Usermanager usermanager;
    BST bst;
    MaxHeap maxheap;

    cli.PrintMainMenu();
    string CurrentUser = input.MainHandler();

    Player player(CurrentUser, 'a', 0);
    Wolf wolf('d');
    GameState gamestate(player, wolf);

    if (CurrentUser != "Exit")
    {
        bool mode;
        while (true)
        {
            cli.displayGraph(player.getPosition(), wolf.getPosition());
            mode = input.SelectModeofAlghorithms();
            switch (mode)
            {
            case true:
                cout << "Dijkstra selected\n";
                dijkstraPrintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                break;
            case false:
                cout << "A* selected\n";
                AStarprintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                break;
            }
            char CurrentOrder = input.CurrentHandler();
            switch (CurrentOrder)
            {
            case '0':
                cout << "Undo selected\n";
                gamestate.undo(player, wolf, stack);
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
                // if (move.movePlayer(graph, player, CurrentOrder)) // This section is not ready yet.
                {
                    cout << "game is finish.";
                    int idx = usermanager.SearchUser(CurrentUser);
                    long int newscore = player.getScore() + usermanager.GetUserScore(idx);
                    usermanager.SetUserScore(CurrentUser, newscore);
                    bst.updateScore(CurrentUser, newscore);
                    maxheap.updateScore(CurrentUser, newscore);
                    cli.PrintLeaderboard();
                }
            default:
                cout
                    << "Invalid order selected\n";
            }
        }
    }
}