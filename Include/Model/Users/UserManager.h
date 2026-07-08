#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

class Usermanager
{
private:
    vector<User> Users;

public:
    void AddUser();
    void DelUser();
    int SearchUser();
    void PrintScore();
};
#endif USERMANAGER_H