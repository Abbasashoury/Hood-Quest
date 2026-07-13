#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "CLIView.h"
#include "InputHandler.h"
#include "GameState.h"
#include "Move.h"
#include "Player.h"
#include "WOlf.h"
#include "Graph.h"
#include "Stack.h"
#include "Dijkstra.h"
#include "AStar.h"

using namespace std;
class Gameengine
{
private:
public:
    void GameLoop();
};

#endif GAMEENGINE_H