#include "Move.h"

// valid move method imlementation
bool Move::validMove(const Graph &graph, Player &player, char nextPosition)
{
    const auto &adjList = graph.getAdjList();    // create the adjacency list
    char currentPosition = player.getPosition(); // get the player position

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
    srand(time(0));
    int number = rand() % 6;
    if (number == 2 || number == 4 || number == 6)
    {
        return true;
    }

    cout << "dice number is odd! wolf can not move" << endl;
    return false;
}