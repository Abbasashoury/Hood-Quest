#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player
{
private:
    std::string playerName;
    char playerPosition;

public:
    player(std::string , char); // player class constructor
    void playerSetter(std::string , char); // setter method to initialize the variables
    void playerSetter(char); // overloaded seeter method
    std::string getName() const; // getter method for name variable
    char getPlayerPosition() const; // getter method for player position variable
};

#endif