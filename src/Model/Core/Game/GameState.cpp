#include "GameState.h"

// set position method implementation
char GameState::getRandomNode()
{
    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'J', 'K', 'W', 'M', 'O', 'P', 'R', 'S', 'Q', 'T', 'U'};
    int randomNumber = rand() % 18;
    return nodes[randomNumber];
}

// game state constructor implementation
GameState::GameState(Player &player, Wolf &wolf)
{
    // set wolf and player position
    player.setPosition(getRandomNode());
    wolf.setPosition(getRandomNode());

    // while loop to compare player and wolf positions
    while (player.getPosition() == wolf.getPosition())
    {
        wolf.setPosition(getRandomNode());
    }
}

// wolf block method implementation
bool GameState::wolfBlock(Player &player, Wolf &wolf)
{
    if (player.getPosition() == wolf.getPosition())
    {
        std::cout << "============= GAME OVER =============" << std::endl;
        std::cout << "The wolf caught You!" << std::endl;
        return true;
    }
    return false;
}

// reached destination method implementation
bool GameState::reachedDestination(Player &player)
{
    if (player.getPosition() == 'V')
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