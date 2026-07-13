#include "UserManager.h"

// create user method implementation
void Usermanager::CreateUser(const string &username, const string &pass)
{
    // search the system to find out the user already exist or no
    int flag = -1;
    flag = Usermanager::SearchUser(username);

    // use the flag to see if it should create a new user or no
    if (flag = -1)
    {
        // create an object to hash the password
        Hash hasher;
        size_t HPass = hasher.ConvertToHash(pass);

        // create a new user with the username and hashed password
        User TempUser(username, HPass);
        Users.push_back(TempUser);

        // increase the number of users
        Usermanager::increaseNumofUser();
        cout << "User Created Successfully!" << endl;
    }
    cout << "User Already Exists!" << endl;
}

// login user method implementation
bool Usermanager::LoginUser(const string &username, const string &pass)
{
    // create an object to hash the password
    Hash hasher;
    size_t HPass = hasher.ConvertToHash(pass);

    // search the user in system
    int index = Usermanager::SearchUser(username);

    // check if the password is right
    if (Users[index].getPassword() == HPass)
    {
        cout << "Login Successful!" << endl;
        return true;
    }

    // if the password is wrong
    cout << "Login Failed!" << endl;
    return false;
}

// search user method implementation
int Usermanager::SearchUser(const string &username)
{
    // a for loop to navigate every user
    for (int i = 0; i < Users.size(); i++)
    {
        // check every user
        if (Users[i].getUsername() == username)
        {
            return i;
        }
    }
}

void Usermanager::ShowLeaderBoard()
{
    // print the leaderboard
    // to display all users by rating. Not just the top player.
    cout << "================== Leaderboard ==================\n";
    cout << "Rank\t\tUsername\t\tScore\n";
    for (int i = 0; i < Users.size(); i++)
    {
        cout << (i + 1) << "\t" << Users[i].getUsername() << "\t\t" << Users[i].getUserScore() << "\n";
    }
    cout << "=================================================\n";
}
// print score function implementation
void Usermanager::PrintScore(const string &username)
{
    // a for loop to navigate the users
    for (int i = 0; i < Users.size(); i++)
    {
        // check if the user has been found or no
        if (Users[i].getUsername() == username)
        {
            cout << "Score: " << Users[i].getUserScore() << endl;
            return;
        }
    }
}