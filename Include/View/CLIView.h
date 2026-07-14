#ifndef CLIVIEW_H
#define CLIVIEW_H

#include <iostream>
#include "UserManager.h"
#include "BST.h"
#include "Maxheap.h"
using namespace std;
class Cliview
{
private:
    Usermanager usermanager;
    BST bstview;
    MaxHeap maxheapview;

public:
    void GetColorNude(char, char, char);
    void displayGraph(char, char);
    void PrintMainMenu();
    void PrintLeaderboard();
    void PrintScore(string);
};

#endif CLIVIEW_H