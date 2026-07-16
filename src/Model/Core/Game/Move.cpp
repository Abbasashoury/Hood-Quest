#include "Move.h"

// valid move method imlementation
bool Move::validMove(const Graph &graph, Player &player, Wolf &wolf, char nextPosition)
{
    const auto &adjList = graph.getAdjList();    // create the adjacency list
    char currentPosition = player.getPosition(); // get the player position

    // check if the player and wolf are not in the same Block
    if (nextPosition == wolf.getPosition())
    {
        try
        {
            throw invalid_argument("the wolf and the player can not be in the same Block!");
        }
        catch (const invalid_argument &x)
        {
            std::cerr << x.what() << endl;
        }
        return false;
    }

    // check if the node is in the graph or no
    auto it = adjList.find(currentPosition);
    if (it == adjList.end())
    {
        // exception handling to check the node
        try
        {
            throw invalid_argument("wrong node! please try again!");
        }
        catch (const invalid_argument &x)
        {
            std::cerr << x.what() << endl;
        }

        return false;
    }

    // search the neighbors list to find the next position
    const auto &neighbors = it->second;
    // a for loop to navigate the neighbors list
    for (const auto &neighbor : neighbors)
    {
        // if condition to compare the position and edge
        if (neighbor.first == nextPosition)
        {
            return true;
        }
    }

    // execption handling for the edges
    try
    {
        throw invalid_argument("there is not any edge between this nodes! please try again!");
    }
    catch (const invalid_argument &x)
    {
        std::cerr << x.what() << endl;
    }

    return false;
}

// dice move method implementation
bool Move::diceMove()
{
    // create a random number for the dice
    srand(time(0));
    int number = rand() % 6;

    if (number == 0 || number == 2 || number == 4)
    {
        return true;
    }

    cout << "dice number is odd! wolf can not move" << endl;
    return false;
}

// move player method implementation
bool Move::movePlayer(const Graph &graph, Player &player, Wolf &wolf, char nextPosition, const vector<char> path)
{
    // an if condition to check that the player can move or no
    if (validMove(graph, player, wolf, nextPosition))
    {
        player.setPosition(nextPosition);

        // get player and wolf position
        char playerPosition = player.getPosition();
        char wolfPosition = wolf.getPosition();

        // createpath algorithm variable
        char pathAlgorithm = ' ';

        // if condition to check the path is empty or no
        if (path.empty())
        {
            pathAlgorithm = path.front();
        }

        // if consition to campare the Blocks
        if (playerPosition == pathAlgorithm)
        {
            player.addScore(3);
            return true;
        }

        // when the player does not use the suggested path
        player.addScore(1);
        return true;
    }
    return false;
}

// move wolf mathod implemenation
void Move::moveWolf(const Graph &graph, Wolf &wolf, Player &player)
{
    // if condition to check for the wolf move validation
    if (diceMove())
    {
        char nextMove = wolfNextPosition(graph, player.getPosition(), wolf.getPosition());
        wolf.setPosition(nextMove);
        cout << "wolf moved to " << nextMove << " Block" << endl;
        return;
    }
}