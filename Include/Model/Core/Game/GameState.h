#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Player.h"
#include "Wolf.h"
#include "Stack.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>

class GameState
{
private:
    char setPosition(); // a method to set a position for player and wolf
public:
    GameState(Player &, Wolf &); // game state constructor
    void undo(Player &, Wolf & , Stack &); // undo method
};

#endif