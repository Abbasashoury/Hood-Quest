#ifndef SAVELOADMANAGER_H
#define SAVELOADMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "UserManager.h"
using namespace std;

void save(const Usermanager &, const string &);
void load(Usermanager &, const string &);

#endif SAVELOADMANAGER_H