#include "CLIView.h"
#include "InputHandler.h"

Cliview::Cliview(Usermanager &usermanager, MaxHeap &maxheap)
    : usermanager(usermanager), maxheapview(maxheap) {}

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

void Cliview::PrintScore() // display the score of a desired player with linear search or BST DataType
{
    int searchmode;
    cout << "please select an mode: Linear Search (1) or BST Search (2)\n";
    cin >> searchmode;

    if (inputhandler != nullptr)
    {
        inputhandler->ScoreUser(searchmode);
    }
    else
    {
        cout << "InputHandler is not connected to this view yet.\n";
    }
}

void Cliview::PrintLeaderboard()
{
    pair<string, long int> maxuser;
    maxuser = maxheapview.getTop();
    cout << " The name of top user is " << maxuser.first << "and its score: " << maxuser.second << endl;
}

string Cliview::GetColorNode(char currentNode, char playerpos, char wolfpos)
{
    if (currentNode == playerpos)
    {
        return RED + "(" + currentNode + ")" + RESET;
    }
    else if (currentNode == wolfpos)
    {
        return BLUE + "(" + currentNode + ")" + RESET;
    }
    return WHITE + "(" + currentNode + ")" + RESET;
}

void Cliview::displayGraph(char playerpos, char wolfpos)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "====================== HOODQUEST MAP ======================\n";
    cout << "  " << RED << "[Red Riding Hood: " << playerpos << "]" << RESET
         << "   " << BLUE << "[Wolf: " << wolfpos << "]" << RESET << "\n";
    cout << "===========================================================\n\n";

    cout << "     " << GetColorNode('B', playerpos, wolfpos) << "----------2----------" << GetColorNode('C', playerpos, wolfpos) << "----------5----------" << GetColorNode('D', playerpos, wolfpos) << "\n";
    cout << "      /                                                \\\n";
    cout << "     3                                                  1\n";
    cout << "    /                                                    \\\n";
    cout << " " << GetColorNode('A', playerpos, wolfpos) << "-------6------" << GetColorNode('F', playerpos, wolfpos) << "---------4----------" << GetColorNode('G', playerpos, wolfpos) << "-------3------" << GetColorNode('E', playerpos, wolfpos) << "\n";
    cout << "                  /                      |  \\\n";
    cout << "                 6                       5   4\n";
    cout << "                /                        |    \\\n";
    cout << "              " << GetColorNode('J', playerpos, wolfpos) << "-----3-----" << GetColorNode('K', playerpos, wolfpos) << "----2----" << GetColorNode('W', playerpos, wolfpos) << "-3-" << GetColorNode('M', playerpos, wolfpos) << "\n";
    cout << "               \\              \\               /\n";
    cout << "                5              3             1\n";
    cout << "                 \\              \\           /\n";
    cout << "   " << GetColorNode('O', playerpos, wolfpos) << "-----3-----" << GetColorNode('P', playerpos, wolfpos) << "-----1-----" << GetColorNode('R', playerpos, wolfpos) << "---2---" << GetColorNode('S', playerpos, wolfpos) << "\n";
    cout << "     \\                          |          \\\n";
    cout << "      2                         4           6\n";
    cout << "       \\                        |            \\\n";
    cout << "       " << GetColorNode('Q', playerpos, wolfpos) << "-----------5---------" << GetColorNode('T', playerpos, wolfpos) << "-----2-----" << GetColorNode('U', playerpos, wolfpos) << "\n";
    cout << "         \\                                    /\n";
    cout << "          5                                  3\n";
    cout << "           \\                                /\n";
    cout << "            \\--------------" << GetColorNode('V', playerpos, wolfpos) << "-------------/\n\n";
    cout << "===========================================================\n";
}