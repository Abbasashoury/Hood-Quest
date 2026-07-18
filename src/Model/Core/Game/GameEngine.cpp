#include "GameEngine.h"
#include "SaveLoadManager.h"

void gameEngine::GameLoop()
{
    system("cls");

    if (!fileChecker())
    {
        cerr << "<<<< Save file could not be created.\n";
        return;
    }

    Usermanager usermanager;

    load(usermanager, "..\\src\\Controller\\save.txt");

    BST &bst = usermanager.GetBST();
    MaxHeap &maxheap = usermanager.GetMaxHeap();

    CliView cli(usermanager, maxheap);
    InputHandler input(usermanager, bst, cli);
    cli.SetInputHandler(input);

    Move move;
    Graph graph;
    Stack stack;

    Dijkstra dijkstra;
    AStar astar;

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
            cli.displayGraph(player.getPosition(), wolf.getPosition(), CurrentUser, player.getScore());
            mode = input.SelectModeofAlghorithms();
            switch (mode)
            {
            case true:
                cout << "> Dijkstra selected\n";
                dijkstra.dijkstraPrintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                path = dijkstra.getPath();
                break;
            case false:
                cout << "> A* selected\n";
                astar.AStarprintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                path = astar.getPath();
                break;
            }
            string CurrentOrder = input.CurrentHandler();
            if (CurrentOrder == "UNDO")
            {
                if (stack.isEmpty())
                {
                    cout << "<<<< You have not done any move in the game \n";
                }
                else
                {
                    cout << "> Undo selected\n";
                    gamestate.undo(player, wolf, stack);
                }
            }
            else if (CurrentOrder == "A" || CurrentOrder == "B" || CurrentOrder == "C" || CurrentOrder == "D" ||
                     CurrentOrder == "E" || CurrentOrder == "F" || CurrentOrder == "G" || CurrentOrder == "J" ||
                     CurrentOrder == "K" || CurrentOrder == "M" || CurrentOrder == "W" || CurrentOrder == "O" ||
                     CurrentOrder == "P" || CurrentOrder == "Q" || CurrentOrder == "R" || CurrentOrder == "S" ||
                     CurrentOrder == "T" || CurrentOrder == "U" || CurrentOrder == "V")
            {
                stack.push(player.getPosition(), wolf.getPosition());
                if (move.movePlayer(graph, player, wolf, CurrentOrder[0], path))
                {
                    move.moveWolf(graph, wolf, player);

                    if (gamestate.reachedDestination(player) || gamestate.wolfBlock(player, wolf))
                    {
                        cli.displayGraph(player.getPosition(), wolf.getPosition(), CurrentUser, player.getScore());

                        cout << "> game is finish.\n";
                        int idx = usermanager.SearchUser(CurrentUser);
                        long int newscore = player.getScore() + usermanager.GetUserScore(idx);

                        usermanager.SetUserScore(CurrentUser, newscore);
                        bst.updateScore(CurrentUser, newscore);
                        maxheap.updateScore(CurrentUser, newscore);

                        save(usermanager, "..\\src\\Controller\\save.txt");

                        cli.PrintLeaderboard();
                        return;
                    }

                    cout << "> The move was successful.\n";
                }
            }
            else if (CurrentOrder == "EXIT")
            {
                int idx = usermanager.SearchUser(CurrentUser);
                long int newscore = player.getScore() + usermanager.GetUserScore(idx);

                usermanager.SetUserScore(CurrentUser, newscore);
                bst.updateScore(CurrentUser, newscore);
                maxheap.updateScore(CurrentUser, newscore);

                save(usermanager, "..\\src\\Controller\\save.txt");

                cout << "===========Game state saved successfully===========\n";
                cout << "==================Exiting the game=================\n";
                return;
            }
            else
            {
                cout << "<<<< Invalid order selected\n";
            }
        }
    }
}