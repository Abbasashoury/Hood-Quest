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

    void SetScore(long int score) { Score = score; }
    string getUsername() const { return Username; }
    size_t getPassword() const { return Password; }
    long int getCurrentScore() const { return Score; }
};
#endif USER_H