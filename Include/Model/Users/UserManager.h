#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Hash.h"
#include "BST.h"
#include "Maxheap.h"

using namespace std;

class Usermanager
{
private:
    vector<User> Users;
    BST bstuser;
    MaxHeap maxheapuser;
    int Numofuser = 0;

    friend void save(const Usermanager &, const string &);
    friend void load(Usermanager &, const string &);

public:
    void CreateUser(const string &, const string &); // craete user method to create new users
    bool LoginUser(const string &, const string &);  // login method
    int SearchUser(const string &);                  // a method to search between the users
    void SetUserScore(const string &, long int);

    long int GetUserScore(int idx) { Users[idx].getCurrentScore(); }
    void increaseNumofUser() { Numofuser++; } // increase the number of users

    BST &GetBST() { return bstuser; }
    MaxHeap &GetMaxHeap() { return maxheapuser; }
};
#endif USERMANAGER_H