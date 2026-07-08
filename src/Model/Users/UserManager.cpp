#include "UserManager.h"

void Usermanager::CreateUser(const string &username, const string &pass)
{
    int flag = -1;
    flag = Usermanager::SearchUser(username);
    if (flag = -1)
    {
        Hash hasher;
        size_t HPass = hasher.ConvertToHash(pass);
        User TempUser(username, HPass);
        Users.push_back(TempUser);
        cout << "User Created Successfully!" << endl;
    }
    cout << "User Already Exists!" << endl;
}

bool Usermanager::LoginUser(const string &username, const string &pass)
{
    Hash hasher;
    size_t HPass = hasher.ConvertToHash(pass);
    int index = Usermanager::SearchUser(username);
    if (Users[index].getPassword() == HPass)
    {
        return true;
        cout << "Login Successful!" << endl;
    }
    cout << "Login Failed!" << endl;
    return false;
}

int Usermanager::SearchUser(const string &username)
{
    for (int i = 0; i < Users.size(); i++)
    {
        if (Users[i].getUsername() == username)
        {
            return i;
        }
    }
}
void Usermanager::PrintScore(const string &username)
{
    for (int i = 0; i < Users.size(); i++)
    {
        if (Users[i].getUsername() == username)
        {
            cout << "Score: " << Users[i].getScore() << endl;
            return;
        }
    }
}