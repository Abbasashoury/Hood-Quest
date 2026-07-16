#include "InputHandler.h"
#include "CLIView.h"

InputHandler::InputHandler(Usermanager &userManager, BST &bst, Cliview &cli)
    : cliinput(cli), userManager(userManager), bstview(bst) {}

string InputHandler::MainHandler()
{
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
            cliinput.PrintLeaderboard();
            break;
        case 4:
            cliinput.PrintScore();
            break;
        case 5:
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
    cout << "Which nude do you want to go to (nude name = char) or do you want to return (Undo = 0):\n";
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

void InputHandler::ScoreUser(int searchmode)
{
    string username;
    cout << "Enter the Username:\n";
    cin >> username;

    switch (searchmode)
    {
    case 1:
    {
        int idx, finalscore;
        idx = userManager.SearchUser(username);
        finalscore = userManager.GetUserScore(idx);
        cout << "Score of " << username << ": " << finalscore << endl;
        break;
    }
    case 2:
    {
        BSTNode *foundNode = bstview.search(username);
        if (foundNode != nullptr)
        {
            cout << "Score of " << username << ": " << foundNode->score << endl;
        }
        else
        {
            cout << username << " was not found in BST.\n";
        }
        break;
    }
    default:
    {
        cout << "Invalid mode selected. Defaulting to Linear Search.\n";
        break;
    }
    }
}