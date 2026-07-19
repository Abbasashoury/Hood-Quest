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
    // user constructor
    User(string, size_t);
    // user destructor
    ~User();

    void SetScore(long int score) { Score = score; } // score setter method
    string getUsername() const { return Username; }  // user name getter method
    size_t getPassword() const { return Password; }  // password getter method
    long int getCurrentScore() const { return Score; } // score getter method
};
#endif