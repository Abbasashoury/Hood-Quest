#include "Dijkstra.h"

// dijkstra result struct implementation
struct dijkstra::dijkstraResult
{
    map<char, int> distance;
    map<char, char> previous;
};

// path finder result struct implementation
struct dijkstra::pathFinderResult
{
    vector<char> path;
    int totalweight;
};

// dijkstra algorithm function implementation
dijkstra::dijkstraResult dijkstra::dijkstraAlgorithm(const Graph &graph, char from, char wolfPosition)
{
    // create a new graph to remove the wolf position
    Graph newgraph;

    // a for loop to copy every node in the new graph except the wolf position
    for (const auto &node : graph.getAdjList())
    {
        if (node.first != wolfPosition)
        {
            newgraph.addNode(node.first);
        }
    }

    // a for loop to copy every edge that is not connected to the wolf position
    for (const auto &node : graph.getAdjList())
    {
        char from = node.first;

        // skip the wolf position node
        if (from == wolfPosition)
        {
            continue;
        }

        // a second for loop to navigate the vector that contain the edges
        for (const auto &edge : node.second)
        {
            char to = edge.first;
            int weight = edge.second;

            // skip the nodes that connect to the wolf position
            if (to != wolfPosition)
            {
                newgraph.addEdge(from, to, weight);
            }
        }
    }

    // assign an adjacecy list
    const auto &adjList = newgraph.getAdjList();

    // create two maps to store the distance and the previous node
    map<char, int> distance;  // map for distance
    map<char, char> previous; // map for prevoius node

    // a for loop to initialize the maps
    for (const auto &i : adjList)
    {
        // the new members will be add to the maps and initialize at the same time
        distance[i.first] = INT_MAX; // initialize the intiger to it's maximum number
        previous[i.first] = '\0'; // initialize every character to \0 or nothing
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

    // if there is not any path
    if (distance['V'] == INT_MAX)
    {
        try
        {
            throw runtime_error("could not find any path to grand mother's house");
        }

        catch (runtime_error &x)
        {
            cerr << "Error: " << x.what() << endl;
        }
    }

    return {distance, previous};
}

// path finder function implementation
dijkstra::pathFinderResult dijkstra::pathFinder(const Graph &graph, char from, char destinationNode, char wolfPosition)
{
    // result variable to store and use the dijkstra data
    dijkstraResult result = dijkstraAlgorithm(graph, from, wolfPosition);

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
        if (current == from) // check if the destination node and the starting node are the same
        {
            break;
        }
        current = result.previous[current]; // current change to the previous node
    }

    reverse(path.begin(), path.end()); // reverse the path to make prioritization
    return {path, result.distance[destinationNode]};
}

// print path function implementation
void dijkstra::dijkstraPrintPath(const Graph &graph, char from, char destinationNode, char wolfPosition)
{
    // initialize the needed variables
    pathFinderResult result = pathFinder(graph, from, destinationNode, wolfPosition); // get the pathfinder output
    const vector<char> &path = result.path; // get the path
    int totalDistance = result.totalweight; // get the total distance

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
    cout << endl << "total distance with the recommended path is :" << totalDistance << endl;
}