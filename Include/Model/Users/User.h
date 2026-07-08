#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string Username;
    long int Password;
    long int Score;

public:
    User();
    char *AddUser();
    char *DelUser();
};