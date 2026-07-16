#ifndef MOVE_H
#define MOVE_H

#include "Graph.h"
#include "BFS.h"
#include "Player.h"
#include "Wolf.h"
#include "Dijkstra.h"
#include "AStar.h"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>

class Move
{
private:
    bool validMove(const Graph &, Player &, Wolf &, char); // check the validation of every move
    bool diceMove(); // dice simulator method for wolf move

public:
    bool movePlayer(const Graph &, Player &, Wolf &, char, const vector<char>); // move player method
    void moveWolf(const Graph &, Wolf & , Player &); // move wolf method
};

#endif