#include "AStar.h"

// A* result struct implementation
struct AstarResult
{
    vector<char> path;
    int totalWeight;
};

// A* algorithm function implementation
AstarResult AStar(const Graph &graph, char from, char to, char wolfPosition, heuristicFunction heuristic)
{
    // create a new graph to remove the wolf position
    Graph newgraph;

    // a for loop to create the nodes in filtered graph
    for (const auto &node : graph.getAdjList())
    {
        if (node.first != wolfPosition)
        {
            newgraph.addNode(node.first);
        }
    }

    // a for loop to copy the valid edges
    for (const auto &node : graph.getAdjList())
    {
        char fromNode = node.first;
        // skip the wolf position node
        if (fromNode == wolfPosition)
        {
            continue;
        }

        // a for loop to navigate the edges of every node
        for (const auto &edge : node.second)
        {
            char toNode = edge.first;
            int weight = edge.second;

            // skip the edges that connect to wolf position
            if (to != wolfPosition)
            {
                newgraph.addEdge(fromNode, toNode, weight);
            }
        }
    }
}