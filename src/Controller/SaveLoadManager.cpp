#include "SaveLoadManager.h"


// file checker function implementation
bool fileChecker()
{
    // check if the file is in the system or no
    ifstream file("..\\src\\Controller\\save.txt");

    // if the file is in the system
    if(file.good())
    {
        return true;
    }

    // if the file does not exist
    ofstream ofs("..\\src\\Controller\\save.txt");
    if (!ofs)
    {
        return false;
    }

    cout << "> Save file created successfully.\n";
    return true;
}

// save function implementation
void save(const Usermanager &usermanager, const string &file)
{
    // search for the save.txt file
    ofstream ofs(file);
    if (!ofs)
    {
        cerr << "<<<< Could not open file for save: " << file << endl;
        return;
    }

    // a for loop to save data from every user in save.txt file
    for (size_t i = 0; i < usermanager.Users.size(); i++)
    {
        ofs << usermanager.Users[i].getUsername() << "\n";
        ofs << usermanager.Users[i].getPassword() << "\n";
        ofs << usermanager.Users[i].getCurrentScore() << "\n";
    }

    cout << "> Data Saved Successfully!" << endl;
}

// load funtion implementation
void load(Usermanager &usermanager, const string &file)
{
    // check for the save.txt file
    ifstream ifs(file);
    if (!ifs)
    {
        cerr << "<<<< Could not open file for load: " << file << endl;
        return;
    }

    usermanager.Users.clear();
    usermanager.Numofuser = 0;

    string username;
    size_t password;
    long int score;

    // a while loop to get and initilize every user from the save.txt file
    while (ifs >> username >> password >> score)
    {
        User user(username, password);
        user.SetScore(score);
        usermanager.Users.push_back(user);
        usermanager.increaseNumofUser();
    }

    // clear the BST and Max Heap
    usermanager.bstuser.clear();
    usermanager.maxheapuser.clear();

    // a for loop to insert users in Max Heap and BST
    for (size_t i = 0; i < usermanager.Users.size(); i++)
    {
        const string &uname = usermanager.Users[i].getUsername();
        long int uscore = usermanager.Users[i].getCurrentScore();

        usermanager.bstuser.insert(uname, uscore);
        usermanager.maxheapuser.insert(uname, uscore);
    }

    cout << "> Data Loaded Successfully!" << endl;
}