#include "Player.h"

// player constructor implementation
player::player(std::string playerName, char playerPosition , int score)
{
    setPlayer(playerName , playerPosition , score);
}

// set player method implementation
void player::setPlayer(std::string name, char position, int score)
{
    setName(name);
    setPosition(position);
    setScore(score);
}

// name setter method implementation
void player::setName(std::string name)
{
    playerName = name;
}

// position setter implememntation
void player::setPosition(char Position)
{
    playerPosition = Position;
}

// score setter implementation
void player::setScore(int score)
{
    playerScore = score;
}

// player name getter impleementation
std::string player::getName() const
{
    return playerName;   
}

// player position getter implementation
char player::getPosition() const
{
    return playerPosition;
}

// player score getter implementation
int player::getScore() const
{
    return playerScore;
}