#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include "UserManager.h"
#include "BST.h"
using namespace std;

class Cliview;

class InputHandler
{
private:
    Cliview &cliinput;
    Usermanager &userManager;
    BST &bstview;

public:
    InputHandler(Usermanager &userManager, BST &bst, Cliview &cli);

    string MainHandler();
    string CurrentHandler();
    void ScoreUser(int); // We get both the username and the search type
};
#endif