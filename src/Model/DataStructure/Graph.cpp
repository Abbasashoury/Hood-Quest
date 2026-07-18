#include "Graph.h"

// addNode method implementation
void Graph::addNode(char node)
{
    if (adjList.find(node) == adjList.end()) // check if the node is not already in the graph
    {
        adjList[node] = {};
        return;
    }
}

// addEdge method implementation
void Graph::addEdge(char from, char to, int weight)
{
    adjList[from].push_back({to, weight}); // add an edge for the first node
    adjList[to].push_back({from, weight}); // add an edge for the second node
}

// adhacency list getter method implementation
const map<char, vector<pair<char, int>>> &Graph::getAdjList() const
{
    return adjList;
}

// constructor implementation
Graph::Graph()
{
    // an array that store the name of the nodes
    char nodeNames[19]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'J', 'K', 'W', 'M', 'O', 'P', 'R', 'S', 'Q', 'T', 'U', 'V'};

    // for loop to create the nodes
    for (char i : nodeNames)
    {
        addNode(i);
    }

    // create the edges between the nodes
    addEdge('A', 'B', 3);
    addEdge('A', 'F', 6);
    addEdge('B', 'C', 2);
    addEdge('C', 'D', 5);
    addEdge('D', 'E', 1);
    addEdge('E', 'G', 3);
    addEdge('G', 'F', 4);
    addEdge('F', 'J', 6);
    addEdge('J', 'K', 3);
    addEdge('K', 'W', 2);
    addEdge('W', 'M', 3);
    addEdge('W', 'G', 5);
    addEdge('M', 'G', 4);
    addEdge('M', 'S', 1);
    addEdge('S', 'R', 2);
    addEdge('R', 'P', 1);
    addEdge('P', 'O', 3);
    addEdge('O', 'Q', 2);
    addEdge('Q', 'T', 5);
    addEdge('T', 'R', 4);
    addEdge('T', 'U', 2);
    addEdge('U', 'V', 3);
    addEdge('Q', 'V', 5);
    addEdge('U', 'S', 6);
    addEdge('R', 'K', 3);
    addEdge('P', 'J', 5);
}