#include "BFS.h"

// BFS algorithm implementation
vector<char> BFS(const Graph &graph, char playerPosition, char wolfPosition)
{
    // get the adjacency list from the graph
    const map<char, vector<pair<char, int>>> &adjList = graph.getAdjList();

    // create a queue for breadth search
    queue<char> pq;
    // a vector to stop search the repeated nodes
    map<char, bool> visitedNodes;
    // a vector to store the parents nodes
    map<char, char> parentNodes;

    // a for loop to inizialize every node
    for (const auto &pair : adjList)
    {
        visitedNodes[pair.first] = false;
        parentNodes[pair.first] = '\0';
    }

    // add the wolf postion to the queue
    pq.push(wolfPosition);
    visitedNodes[wolfPosition] = true;

    // the main loop of the BFS algorithm
    while (!pq.empty())
    {
        // store the first node
        char current = pq.front();
        pq.pop(); // remove the first node from queue

        // if the current had reach the player position
        if (current == playerPosition)
        {
            // create a vector to store the path
            vector<char> path;
            char node = current;

            // a while loop to add the right nodes to the path
            while (node != '\0')
            {
                path.push_back(node);     // add the node to the path
                node = parentNodes[node]; // change the value of node to it's parent
            }

            // reverse the path to get the right order
            reverse(path.begin(), path.end());
            return path;
        }

        // find current in adjacency list map
        auto it = adjList.find(current);

        // check if the current node is in the map
        if (it != adjList.end())
        {
            // a for loop to find the neighbors
            for (const auto &neighbor : it->second)
            {
                char neighborNode = neighbor.first;

                // prevent the system to check already visited nodes
                if (!visitedNodes[neighborNode])
                {
                    visitedNodes[neighborNode] = true;
                    parentNodes[neighborNode] = current;
                    pq.push(neighborNode);
                }
            }
        }
    }

    // if there is not any possible path
    try
    {
        throw runtime_error("could not find any path for wolf movement");
    }

    catch (runtime_error &x)
    {
        cout << "<<<< Error: " << x.what() << endl;
    }

    return {};
}

// wolf next postion function implementation
char wolfNextPosition(const Graph &graph, char playerPosition, char wolfPosition)
{
    // store the BFS result
    vector<char> path = BFS(graph, playerPosition, wolfPosition);

    // if there is not any way
    if (path.empty() || path.size() == 1)
    {
        return wolfPosition;
    }

    // return the next node in the shortest way
    return path[1];
}