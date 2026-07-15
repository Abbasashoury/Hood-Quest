#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
    std::string playerName;
    char playerPosition;
    int playerScore;

    void setPlayer(std::string, char, int); // setter method to initialize the variables
    void setName(std::string);              // setter method for player name
    void setScore();                     // setter method for player score

public:
    Player(std::string, char, int); // player class constructor
    void setPosition(char);         // setter method for player position
    void addScore(int);             // adder method fo player score
    std::string getName() const;    // getter method for name variable
    char getPosition() const;       // getter method for player position variable
    int getScore() const;           // getter method for player score variable
};

#endif