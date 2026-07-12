#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct BSTNode
{
    string username;
    long int score;
    BSTNode *left;
    BSTNode *right;

    BSTNode(const string &u, long int s) : username(u), score(s), left(nullptr), right(nullptr) {}
};

class BST
{
private:
public:
};

#endif