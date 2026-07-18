#include "UserManager.h"
#include "SaveLoadManager.h"

// create user method implementation
void Usermanager::CreateUser(const string &username, const string &pass)
{
    // search the system to find out the user already exist or no
    int flag = -1;
    flag = Usermanager::SearchUser(username);

    // use the flag to see if it should create a new user or no
    if (flag == -1)
    {
        // create an object to hash the password
        Hash hasher;
        size_t HPass = hasher.ConvertToHash(pass);

        // create a new user with the username and hashed password
        User TempUser(username, HPass);
        Users.push_back(TempUser);
        bstuser.insert(username, 0);

        // increase the number of users
        Usermanager::increaseNumofUser();
        cout << "> User Created Successfully!" << endl;

        save(*this, "..\\src\\Controller\\save.txt");
    }
    else
    {
        cout << "<<<< User Already Exists!" << endl;
    }
}

// login user method implementation
bool Usermanager::LoginUser(const string &username, const string &pass)
{
    // create an object to hash the password
    Hash hasher;
    size_t HPass = hasher.ConvertToHash(pass);

    // search the user in system
    int index = Usermanager::SearchUser(username);

    // return false if the user does not exist
    if (index == -1)
    {
        cerr << "<<<< User not found\n";
        return false;
    }

    // check if the password is right
    if (Users[index].getPassword() == HPass)
    {
        return true;
    }

    // if the password is wrong
    cout << "<<<< Login Failed!" << endl;
    return false;
}

// search user method implementation
int Usermanager::SearchUser(const string &username)
{
    // a for loop to navigate every user
    for (size_t i = 0; i < Users.size(); i++)
    {
        // check every user
        if (Users[i].getUsername() == username)
        {
            return i;
        }
    }
    return -1;
}

void Usermanager::SetUserScore(const string &username, long int score)
{
    int idx;
    idx = Usermanager::SearchUser(username);
    Users[idx].SetScore(score);
    cout << "> Successfully updated the score of (" << username << ") to: " << score << endl;
}