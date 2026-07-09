#include "InputHandler.h"

string InputHandler::MainHandler()
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
                cout << "Login Successful!\n";
                return username;
            }
            else
            {
                cout << "Login Failed!\n"
                     << endl;
                break;
            }
        case 3:
            userManager.ShowLeaderBoard();
            break;
        case 4:
            cout << "Exiting the program\n";
            return "Exit";
        default:
            cout << "Invalid choice. Please try again\n";
        }
    }
}
char InputHandler::CurrentHandler()
{
    char node;
    cin >> node; // take the input from the user
                 // but cliview only disply the graph and the selection of options
                 // name of nude (char) or undo (0)
    return node;
}

bool InputHandler::SelectModeofAlghorithms()
{
    char mode;
    cout << "Select the mode of algorithms: Dijkstra: D or A*: A\n";
    cin >> mode;
    switch (mode)
    {
    case 'D':
    case 'd':
        return true; // Dijkstra mode
    case 'A':
    case 'a':
        return false; // A* mode
    default:
        cout << "Invalid mode selected. Defaulting to Dijkstra.\n";
        return true; // Default to Dijkstra
    }
}