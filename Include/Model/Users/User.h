#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string Username;
    size_t Password;
    long int Score;

public:
    User(string, size_t);
    ~User();

    string getUsername() { return Username; }
    size_t getPassword() { return Password; }
    long int getUserScore() { return Score; }
};
#endif USER_H