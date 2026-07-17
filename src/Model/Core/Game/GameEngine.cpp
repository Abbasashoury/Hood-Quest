#include "GameEngine.h"
#include "SaveLoadManager.h"

void gameEngine::GameLoop()
{
    if(!fileChecker())
    {
        cerr << "Save file could not be created.\n";
        return;
    }

    Usermanager usermanager;

    load(usermanager, "..\\src\\Controller\\save.txt");

    BST &bst = usermanager.GetBST();
    MaxHeap &maxheap = usermanager.GetMaxHeap();

    Cliview cli(usermanager, maxheap);
    InputHandler input(usermanager, bst, cli);
    cli.SetInputHandler(input);

    Move move;
    Graph graph;
    Stack stack;

    dijkstra dijkstraa;
    AStar astar;

    cli.PrintMainMenu();
    string CurrentUser = input.MainHandler();

    Player player(CurrentUser, 'a');
    Wolf wolf('d');
    GameState gamestate(player, wolf);

    if (CurrentUser != "Exit")
    {
        bool mode;
        vector<char> path;
        while (true)
        {
            cli.displayGraph(player.getPosition(), wolf.getPosition());
            mode = input.SelectModeofAlghorithms();
            switch (mode)
            {
            case true:
                cout << "Dijkstra selected\n";
                dijkstraa.dijkstraPrintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                path = dijkstraa.getPath();
                break;
            case false:
                cout << "A* selected\n";
                astar.AStarprintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                path = astar.getPath();
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
                stack.push(player.getPosition(), wolf.getPosition());
                if (move.movePlayer(graph, player, wolf, CurrentOrder, path))
                {
                    move.moveWolf(graph, wolf, player);

                    if (gamestate.reachedDestination(player) || gamestate.wolfBlock(player, wolf))
                    {
                        cout << "game is finish.";
                        int idx = usermanager.SearchUser(CurrentUser);
                        long int newscore = player.getScore() + usermanager.GetUserScore(idx);

                        usermanager.SetUserScore(CurrentUser, newscore);
                        bst.updateScore(CurrentUser, newscore);
                        maxheap.updateScore(CurrentUser, newscore);

                        save(usermanager, "..\\src\\Controller\\save.txt");

                        cli.PrintLeaderboard();
                        return;
                    }

                    cout << "The move was successful.\n";

                    break;
                }
                break;
            default:
                cout << "Invalid order selected\n";
            }
        }
    }
}