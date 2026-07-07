#include "AStar.h"

// A* result struct implementation
struct AstarResult
{
    vector<char> path;
    int totalWeight;
};

// heuristic function to estimate the distance
int heuristic(char from, char to)
{
    // a map to store the cordinations
    // this cordinates are not accurate
    static const map<char, pair<int, int>> nodeCordinates =
        {
            {'V', {0, 0}},
            {'U', {0, 1}},
            {'T', {-1, 1}},
            {'Q', {-2, 1}},
            {'O', {-2, 2}},
            {'P', {-1, 2}},
            {'R', {0, 2}},
            {'S', {1, 2}},
            {'M', {1, 3}},
            {'W', {0, 3}},
            {'K', {-1, 3}},
            {'J', {-2, 3}},
            {'F', {-1, 3}},
            {'A', {-3, 4}},
            {'B', {-2, 4}},
            {'C', {-2, 5}},
            {'D', {-1, 5}},
            {'E', {-2, 5}},
            {'G', {-3, 3}}
        };

    // get the nodes from the map
    auto itA = nodeCordinates.find(from);
    auto itB = nodeCordinates.find(to);

    // check if the nodes are not in the map
    if (itA == nodeCordinates.end() || itB == nodeCordinates.end())
    {
        return 0;
    }

    // extract first and second node cordination
    int x1 = itA->second.first;
    int y1 = itA->second.second;
    int x2 = itB->second.first;
    int y2 = itB->second.second;

    // calculate the euclidean distance
    int dx = x1 - x2;
    int dy = y1 - y2;

    return static_cast<int>(sqrt(dx * dx + dy * dy));
}

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
            if (toNode != wolfPosition)
            {
                newgraph.addEdge(fromNode, toNode, weight);
            }
        }
    }

    // assign the adjacency list
    const auto &adjList = newgraph.getAdjList();

    // check for the from and to nodes validation
    if (adjList.find(from) == adjList.end() || adjList.find(to) == adjList.end())
    {
        return {{}, -1};
    }

    map<char, int> gScore;    // real destination from the origin
    map<char, int> fScore;    // gScore + heuristic
    map<char, char> previous; // store the prevoius node

    // innitialize every variable to maximum number they can store
    for (const auto &node : adjList)
    {
        gScore[node.first] = INT_MAX;
        fScore[node.first] = INT_MAX;
        previous[node.first] = '\0';
    }

    // initializing the origin node
    gScore[from] = 0;
    fScore[from] = heuristic(from, to);

    // create the priority queue to store the nodes with ascending sort
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({fScore[from], from}); // initialize the priority queue

    // A* algorithm main loop
    while (!pq.empty())
    {
        char currentNode = pq.top().second;
        int currentFScore = pq.top().first;
        pq.pop();

        // skip the repeated nodes
        if (currentFScore > fScore[currentNode])
        {
            continue;
        }

        // if the program reach the destination create the path
        if (currentNode == to)
        {
            vector<char> path;
            char current = to;

            // a while loop to store the path
            while (current != '\0')
            {
                path.push_back(current);
                // check for the last node
                if (current == from)
                {
                    break;
                }
                current = previous[current];
            }

            // revers the path to achive the right order
            reverse(path.begin(), path.end());
            return {path, gScore[to]};
        }

        // neighbor checking
        auto it = adjList.find(currentNode);
        // skip if current node is not in the adjacency list
        if (it == adjList.end())
        {
            continue;
        }

        // a for loop for finfing the current node neighbors
        for (const auto &neighbor : it->second)
        {
            char nextNode = neighbor.first;
            int weight = neighbor.second;

            // new distance from origin to neighbor
            int newDistance = gScore[currentNode] + weight;

            // check if the new way is shorter or no
            if (newDistance < gScore[nextNode])
            {
                // update the vatiables
                previous[nextNode] = currentNode;
                gScore[nextNode] = newDistance;
                fScore[nextNode] = newDistance + heuristic(nextNode, to);

                // add a node to the priority queue
                pq.push({fScore[nextNode], nextNode});
            }
        }
    }

    // if there is not any path
    return {{}, -1};
}