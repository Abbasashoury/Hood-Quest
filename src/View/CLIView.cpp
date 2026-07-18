#include "CLIView.h"
#include "InputHandler.h"

CliView::CliView(Usermanager &usermanager, MaxHeap &maxheap)
    : usermanager(usermanager), maxheapview(maxheap) {}

void CliView::PrintMainMenu()
{
    std::cout << " ========== welcome to this game ==========\n";
    std::cout << " please select an option:\n";
    std::cout << " crate a new user: 1\n";
    std::cout << " login: 2\n";
    std::cout << " Show leaderboard: 3\n"; // to display all users by rating. Not just the top player.
    std::cout << " Print score of desired user: 4\n";
    std::cout << " exit: 5\n";
}

void CliView::PrintScore() // display the score of a desired player with linear search or BST DataType
{
    int searchmode;
    std::cout << "please select an mode: Linear Search (1) or BST Search (2)\n";
    cin >> searchmode;

    if (inputhandler != nullptr)
    {
        inputhandler->ScoreUser(searchmode);
    }
    else
    {
        std::cout << "InputHandler is not connected to this view yet.\n";
    }
}

void CliView::PrintLeaderboard()
{
    pair<string, long int> maxuser;
    maxuser = maxheapview.getTop();
    std::cout << " Top Player: " << maxuser.first << "\n Score = " << maxuser.second << endl;
}

string CliView::GetColorNode(char currentNode, char playerpos, char wolfpos)
{
    if (currentNode == playerpos && currentNode == wolfpos)
    {
        return YELLOW + "(" + currentNode + ")" + RESET;
    }
    else if (currentNode == playerpos)
    {
        return RED + "(" + currentNode + ")" + RESET;
    }
    else if (currentNode == wolfpos)
    {
        return BLUE + "(" + currentNode + ")" + RESET;
    }
    return WHITE + "(" + currentNode + ")" + RESET;
}

void CliView::displayGraph(char playerpos, char wolfpos)
{
    std::cout << "\033[2J\033[H";

    std::cout << "====================== HOODQUEST MAP ======================\n";
    std::cout << "  " << RED << "[Red Riding Hood: " << playerpos << "]" << RESET
              << "   " << BLUE << "[Wolf: " << wolfpos << "]" << RESET << "\n";
    std::cout << "===========================================================\n\n";

    std::cout << "     " << GetColorNode('B', playerpos, wolfpos) << "----------2----------" << GetColorNode('C', playerpos, wolfpos) << "----------5----------" << GetColorNode('D', playerpos, wolfpos) << "\n";
    std::cout << "      /                                                \\\n";
    std::cout << "     3                                                  1\n";
    std::cout << "    /                                                    \\\n";
    std::cout << " " << GetColorNode('A', playerpos, wolfpos) << "-------6------" << GetColorNode('F', playerpos, wolfpos) << "---------4----------" << GetColorNode('G', playerpos, wolfpos) << "-------3------" << GetColorNode('E', playerpos, wolfpos) << "\n";
    std::cout << "                  /                      |  \\\n";
    std::cout << "                 6                       5   4\n";
    std::cout << "                /                        |    \\\n";
    std::cout << "              " << GetColorNode('J', playerpos, wolfpos) << "-----3-----" << GetColorNode('K', playerpos, wolfpos) << "----2----" << GetColorNode('W', playerpos, wolfpos) << "-3-" << GetColorNode('M', playerpos, wolfpos) << "\n";
    std::cout << "               \\              \\               /\n";
    std::cout << "                5              3             1\n";
    std::cout << "                 \\              \\           /\n";
    std::cout << "   " << GetColorNode('O', playerpos, wolfpos) << "-----3-----" << GetColorNode('P', playerpos, wolfpos) << "-----1-----" << GetColorNode('R', playerpos, wolfpos) << "---2---" << GetColorNode('S', playerpos, wolfpos) << "\n";
    std::cout << "     \\                          |          \\\n";
    std::cout << "      2                         4           6\n";
    std::cout << "       \\                        |            \\\n";
    std::cout << "       " << GetColorNode('Q', playerpos, wolfpos) << "-----------5---------" << GetColorNode('T', playerpos, wolfpos) << "-----2-----" << GetColorNode('U', playerpos, wolfpos) << "\n";
    std::cout << "         \\                                    /\n";
    std::cout << "          5                                  3\n";
    std::cout << "           \\                                /\n";
    std::cout << "            \\--------------" << GetColorNode('V', playerpos, wolfpos) << "-------------/\n\n";
    std::cout << "===========================================================\n";
}