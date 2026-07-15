#include "GameState.h"

// set position method implementation
char GameState::getRandomNode()
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
    char playerPosition = getRandomNode();
    char wolfPosition = getRandomNode();

    // set wolf and player position
    player.setPosition(playerPosition);
    wolf.setPosition(wolfPosition);

    // while loop to compare player and wolf positions
    while (playerPosition == wolfPosition)
    {
        wolf.setPosition(getRandomNode());
    }
}

// wolf block method implementation
bool wolfBlock(Player &player, Wolf &wolf)
{
    if(player.getPosition() == wolf.getPosition())
    {
        std::cout << "The wolf caught you" << std::endl;
        return true;
    }
    return false;
}

// reached destination method implementation
bool reachedDestinatio(Player &player)
{
    if(player.getPosition() == 'V')
    {
        std::cout << "you reached the grandmother's house" << std::endl;
        player.addScore(5);
        return true;
    }
    return false;
}

// undo method implementation
void GameState::undo(Player &player, Wolf &wolf, Stack &stack)
{
    // get the previos positiob of player and wolf
    std::pair<char, char> previousPosition = stack.pop();

    // assign player and wolf position woth their prevoius positions
    player.setPosition(previousPosition.first);
    wolf.setPosition(previousPosition.second);

    // change the player score
    player.addScore(-2);
}