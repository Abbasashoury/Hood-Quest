#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include "UserManager.h"
#include "CLIView.h"
using namespace std;
class InputHandler
{
private:
    Cliview cliinput;
    Usermanager userManager;
    BST bstview;

public:
    string MainHandler();
    char CurrentHandler();
    bool SelectModeofAlghorithms();
    void ScoreUser(int); // We get both the username and the search type
};
#endif INPUTHANDLER_H