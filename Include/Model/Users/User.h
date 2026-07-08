#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string Username;
    string Password;
    long int Score;

public:
    User();
    ~User();
};
#endif USER_H