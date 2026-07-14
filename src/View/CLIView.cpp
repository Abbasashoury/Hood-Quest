#include "Cliview.h"

void Cliview::PrintMainMenu()
{
    cout << " ========== welcome to this game ==========\n";
    cout << " please select an option:\n";
    cout << " crate a new user: 1\n";
    cout << " login: 2\n";
    cout << " Show leaderboard: 3\n"; // to display all users by rating. Not just the top player.
    cout << " Print score of desired user: 4\n";
    cout << " exit: 5\n";
}

void Cliview::PrintScore(string username) // display the score of a desired player with linear search or BST DataType
{
    int searchmode;
    cout << "please select an mode: Linear Search (1) or BST Search (2)\n";
    cin >> searchmode;
    switch (searchmode)
    {
    case 1:
    {
        int idx, finalscore;
        idx = usermanager.SearchUser(username);
        finalscore = usermanager.GetUserScore(idx);
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

void Cliview::PrintLeaderboard()
{
    pair<string, long int> maxuser;
    maxuser = maxheapview.getTop();
    cout << " The name of top user is " << maxuser.first << "and its score: " << maxuser.second << endl;
}

void Cliview::GetColorNude(char currentNude, char playerpos, char wolfpos)
{
}

void Cliview::displayGraph(char playerpos, char wolfpos)
{
}