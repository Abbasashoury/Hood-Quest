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

public:
    void CreateUser(const string &, const string &);
    void LoginUser(const string &, const string &);
    int SearchUser(const string &);
    int SearchUserBST();
    void PrintScore();
};
#endif USERMANAGER_H