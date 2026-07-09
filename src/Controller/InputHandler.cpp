#include "InputHandler.h"

bool InputHandler::MainHandler()
{
    Usermanager userManager;
    int choice;
    while (true)
    {
        string username, password;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            userManager.CreateUser(username, password);
            break;
        case 2:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (userManager.LoginUser(username, password))
            {
                cout << "Login Successful!" << endl;
                return true;
            }
            else
            {
                cout << "Login Failed!" << endl;
                break;
            }
        case 3:
            cout << "Exiting the program." << endl;
            return false;
        }
    }
}
char InputHandler::CurrentHandler()
{
    char node;
    cin >> node; // take the input from the user
                 // but cliview only disply the graph and the selection of options
    return node;
}