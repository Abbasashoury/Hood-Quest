#include "Dijkstra.h"

// dijkstra result struct implementation
struct dijkstraResult
{
    map<char, int> distance;
    map<char, char> previous;
};

// path finder result struct implementation
struct pathFinderResult
{
    vector<char> path;
    int totalweight;
};

// dijkstra function implementation
dijkstraResult dijkstra(const Graph &graph, char from, char wolfposition)
{
    // create a new graph to remove the wolf position
    Graph newgraph;

    // a for loop to copy every node in the new graph except the wolf position
    for (const auto &node : graph.getAdjList())
    {
        if (node.first != wolfposition)
        {
            newgraph.addNode(node.first);
        }
    }

    // get the graph from the getter method
    const auto &adjList = newgraph.getAdjList();

    // create two maps to store the distance and the previous node
    map<char, int> distance;  // map for distance
    map<char, char> previous; // map for prevoius node

    // a for loop to initialize the maps
    for (const auto &i : adjList)
    {
        // the new members will be add to the maps and initialize at the same time
        distance[i.first] = INT_MAX; // initialize the intiger to it's maximum number
        previous[i.first] = '\0';    // initialize every character to \0 or nothing
    }

    // the source node distance is equall to 0
    distance[from] = 0;

    // priority queue
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, from}); // push the from node and the distance to the priority queue

    // dijkstra algorithm loop
    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        char currentNode = pq.top().second;
        pq.pop();

        // ignore the old inputs
        if (currentDistance > distance[currentNode])
        {
            continue;
        }

        // check the neighbor nodes
        auto it = adjList.find(currentNode);
        if (it == adjList.end())
        {
            continue; // if the node does not exist
        }

        // a for loop to check if there is a better path or no
        for (const auto &neighbor : it->second)
        {
            char nextNode = neighbor.first;
            int weight = neighbor.second;

            // check if the new shortest path valid or no
            if (distance[currentNode] + weight < distance[nextNode])
            {
                // update the shortest path
                distance[nextNode] = distance[currentNode] + weight;
                previous[nextNode] = currentNode;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    return {distance, previous};
}

// path finder function implementation
pathFinderResult pathFinder(const Graph &graph, char from, char destinationNode)
{
    // result variable to store and use the dijkstra data
    dijkstraResult result = dijkstra(graph, from);

    // check if the result does not exist
    if (result.distance[destinationNode] == INT_MAX)
    {
        return {};
    }

    // create a path from the previous node
    vector<char> path;
    char current = destinationNode;

    // a while loop to create the path
    while (current != '\0')
    {
        path.push_back(current); // add the current node to the path
        if (current == from)     // check if the destination node and the starting node are the same
        {
            break;
        }
        current = result.previous[current]; // current change to the previous node
    }

    reverse(path.begin(), path.end()); // reverse the path to make prioritization
    return {path, result.distance[destinationNode]};
}

// print path function implementation
void printPath(const Graph &graph, char from, char destinationNode)
{
    // initialize the needed variables
    pathFinderResult result = pathFinder(graph, from, destinationNode); // get the pathfinder output
    const vector<char> &path = result.path;                             // get the path
    int totaldistance = result.totalweight;                             // get the total distance

    // check if there is a path or no
    if (path.empty())
    {
        cout << "there is not any possible path !!!!!!" << endl;
        return;
    }

    // dijkstra output
    cout << "dijkstra recomended path: " << endl;
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl
         << "total distance with the recommended path is :" << totaldistance << " meter" << endl;
}