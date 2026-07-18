#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <cctype>
#include "UserManager.h"
#include "BST.h"
using namespace std;

class Cliview;

class InputHandler
{
private:
    CliView &cliinput;
    Usermanager &userManager;
    BST &bstview;

public:
    InputHandler(Usermanager &userManager, BST &bst, CliView &cli);

    string MainHandler();
    string CurrentHandler();
    bool SelectModeofAlghorithms();
    void ScoreUser(int); // We get both the username and the search type
};
#endif