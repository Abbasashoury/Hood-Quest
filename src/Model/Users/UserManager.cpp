#include "UserManager.h"

void Usermanager::CreateUser(const string &username, const string &pass)
{
    Hash hasher;
    size_t HPass = hasher.ConvertToHash(pass);
    User TempUser(username, HPass);
    Users.push_back(TempUser);
}
void Usermanager::LoginUser(const string &username, const string &pass)
{
    Hash hasher;
    size_t HPass = hasher.ConvertToHash(pass);
    int index = Usermanager::SearchUser(username);

}
int Usermanager::SearchUser(const string &username)
{
    for(int i=0; i < Users.size();i++)
    {
        if(Users[i].getUsername() == username)
        {
            return i;
        }
    }
}