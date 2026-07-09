#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Hash.h"

using namespace std;

class Usermanager
{
private:
    vector<User> Users;
    int Numofuser = 0;

public:
    void CreateUser(const string &, const string &); // craete user method to create new users
    bool LoginUser(const string &, const string &); // login method
    int SearchUser(const string &); // a method to search between the users
    void increaseNumofUser(){ Numofuser++; } // increase the number of users 
    void ShowLeaderBoard(); // show leaderboard method to display the users and their scores
    void PrintScore(const string &); // print score function
};
#endif USERMANAGER_H