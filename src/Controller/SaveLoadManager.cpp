#include "SaveLoadManager.h"

void save(const Usermanager &usermanager, const string &file)
{
    ofstream ofs(file);
    if (!ofs)
    {
        cerr << "Could not open file for save: " << file << endl;
        return;
    }

    for (int i = 0; i < usermanager.Users.size(); i++)
    {
        ofs << usermanager.Users[i].getUsername() << "\n";
        ofs << usermanager.Users[i].getPassword() << "\n";
        ofs << usermanager.Users[i].getCurrentScore() << "\n";
    }

    cout << "Data Saved Successfully!" << endl;
}

void load(Usermanager &usermanager, const string &file)
{
    ifstream ifs(file);
    if (!ifs)
    {
        cerr << "Could not open file for load: " << file << endl;
        return;
    }

    usermanager.Users.clear();
    usermanager.Numofuser = 0;

    string username;
    size_t password;
    long int score;

    while (ifs >> username >> password >> score)
    {
        User user(username, password);
        user.SetScore(score);
        usermanager.Users.push_back(user);
        usermanager.increaseNumofUser();
    }

    usermanager.bstuser.clear();
    usermanager.maxheapuser.clear();

    for (int i = 0; i < usermanager.Users.size(); i++)
    {
        const string &uname = usermanager.Users[i].getUsername();
        long int uscore = usermanager.Users[i].getCurrentScore();

        usermanager.bstuser.insert(uname, uscore);
        usermanager.maxheapuser.insert(uname, uscore);
    }

    cout << "Data Loaded Successfully!" << endl;
}