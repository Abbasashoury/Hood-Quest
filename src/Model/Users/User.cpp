#include "User.h"

// user constructor implementation
User::User(string username, size_t password)
{
    Username = username;
    Password = password;
    Score = 0;
}

// user destructor implementation
User::~User() {}