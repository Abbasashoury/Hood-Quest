#include "InputHandler.h"
#include "CLIView.h"

InputHandler::InputHandler(Usermanager &userManager, BST &bst, CliView &cli)
    : cliinput(cli), userManager(userManager), bstview(bst) {}

string InputHandler::MainHandler()
{
    int choice;
    while (true)
    {
        string username, password;
        cliinput.PrintMainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            userManager.CreateUser(username, password);

            // auto automaticlly login thse user after creating account
            if (userManager.LoginUser(username, password))
            {
                cout << "Login Successful!\n";
                return username;
            }

            cerr << "<<<< Auto login failed please login manually!\n";
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
                cout << "<<<< Login Failed!\n"
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
            cout << "<<<< Invalid choice. Please try again\n";
        }
    }
}
string InputHandler::CurrentHandler()
{
    string order;
    cout << ">> Please enter your next move:\n"
         << ">>> Move (Type node name).\n"
         << ">>> Undo (Type Undo).\n"
         << ">>> Exit (Type Exit).\n";

    cin >> order;

    // if the input was not valid
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "<<<< Invalid input! Please enter a character.\n";
        return ""; // invalid value
    }

    for (char &c : order)
    {
        c = toupper(c); // Convert to uppercase
    }

    return order;
}

bool InputHandler::SelectModeofAlghorithms()
{
    char mode;
    cout << ">> Select the mode of algorithms:\n"
         << ">>> Dijkstra: (D)\n"
         << ">>> A*: (A)\n";
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
        cout << "<<<< Invalid mode selected. Defaulting to Dijkstra.\n";
        return true; // Default to Dijkstra
    }
}

void InputHandler::ScoreUser(int searchmode)
{
    string username;
    cout << ">> Enter the Username:\n";
    cin >> username;

    switch (searchmode)
    {
    case 1:
    {
        int idx, finalscore;
        idx = userManager.SearchUser(username);
        finalscore = userManager.GetUserScore(idx);
        cout << "User: " << username << "\n Score: " << finalscore << endl;
        break;
    }
    case 2:
    {
        BSTNode *foundNode = bstview.search(username);
        if (foundNode != nullptr)
        {
            cout << "User: " << username << "\n Score: " << foundNode->score << endl;
        }
        else
        {
            cout << username << " was not found in BST.\n";
        }
        break;
    }
    default:
    {
        cout << "<<<< Invalid mode selected. Defaulting to Linear Search.\n";
        break;
    }
    }
}