#include "GameState.h"

// set position method implementation
char GameState::setPosition()
{
    // create a random number
    srand(time(0));
    int number = rand() % 18;
    // return a node using the random number
    switch (number)
    {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'E';
    case 5:
        return 'F';
    case 6:
        return 'G';
    case 7:
        return 'J';
    case 8:
        return 'K';
    case 9:
        return 'W';
    case 10:
        return 'M';
    case 11:
        return 'O';
    case 12:
        return 'P';
    case 13:
        return 'R';
    case 14:
        return 'S';
    case 15:
        return 'Q';
    case 16:
        return 'T';
    case 17:
        return 'U';
    default:
        return '?';
    }
}

// game state constructor implementation
GameState::GameState(Player &player, Wolf &wolf)
{
    // create a variable for faster run time
    char playerPosition = setPosition();
    char wolfPosition = setPosition();

    // set wolf and player position
    player.setPosition(playerPosition);
    wolf.setPosition(wolfPosition);

    // while loop to compare player and wolf positions
    while(playerPosition == wolfPosition)
    {
        wolf.setPosition(setPosition());
    }
}