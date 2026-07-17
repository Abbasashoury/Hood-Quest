#include "GameEngine.h"
#include "SaveLoadManager.h"

void gameEngine::GameLoop()
{
    if (!fileChecker())
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

            string CurrentOrder = input.CurrentHandler();
            if (CurrentOrder == "Undo")
            {
                cout << "Undo selected\n";
                gamestate.undo(player, wolf, stack);
            }
            else if (CurrentOrder == "Dijk" || CurrentOrder == "Astar")
            {
                if (CurrentOrder == "Dijk")
                {
                    cout << "Dijkstra selected\n";
                    dijkstraa.dijkstraPrintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                    path = dijkstraa.getPath();
                }
                else if (CurrentOrder == "Astar")
                {
                    cout << "A* selected\n";
                    astar.AStarprintPath(graph, player.getPosition(), 'V', wolf.getPosition());
                    path = astar.getPath();
                    break;
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
                }
            }
            else if (CurrentOrder == "Exit")
            {
                cout << "Exiting the game\n";
                return;
            }
            else
            {
                cout << "Invalid order selected\n";
            }
        }
    }
}