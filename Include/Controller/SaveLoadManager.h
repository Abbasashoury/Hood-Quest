#ifndef SAVELOADMANAGER_H
#define SAVELOADMANAGER_H

#include <string>
#include "UserManager.h"
using namespace std;

class SaveLoadManager
{
private:
public:
    void save(const Usermanager &usermanager, const string &file);
    void load(const Usermanager &usermanager, const string &file);
    void Writh(const string &data, const string &file);
    string read(const string &data, const string &file);
};
#endif SAVELOADMANAGER_H