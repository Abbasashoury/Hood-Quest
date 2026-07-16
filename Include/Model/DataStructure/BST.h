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
    BSTNode *root;

    BSTNode *insertHelper(BSTNode *, const string &, long int);
    BSTNode *searchHelper(BSTNode *, const string &) const;
    void destroyHelper(BSTNode *);

public:
    BST();
    ~BST();

    void insert(const string &, long int);
    BSTNode *search(const string &) const;
    bool updateScore(const string &, long int);
    void clear();
};

#endif