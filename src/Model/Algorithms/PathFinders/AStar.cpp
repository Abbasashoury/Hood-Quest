#include "AStar.h"

// A* result struct implementation
struct AStar::AstarResult
{
    vector<char> path;
    int totalWeight;
};

// heuristic function to estimate the distance
int AStar::heuristic(char from, char to)
{
    // a map to store the cordinations
    // this cordinates are not accurate
    static const map<char, pair<int, int>> nodeCordinates =
        {
            {'V', {0, 0}},
            {'U', {2, 1}},
            {'T', {0, 1}},
            {'Q', {-2, 1}},
            {'O', {-3, 2}},
            {'P', {-1, 2}},
            {'R', {0, 2}},
            {'S', {2, 2}},
            {'M', {3, 3}},
            {'W', {1, 3}},
            {'K', {-2, 3}},
            {'J', {-4, 3}},
            {'F', {-4, 4}},
            {'A', {-5, 5}},
            {'B', {-3, 6}},
            {'C', {0, 6}},
            {'D', {3, 6}},
            {'E', {5, 5}},
            {'G', {1, 4}}};

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

    // cast the sqrt in to a intiger
    return static_cast<int>(sqrt(dx * dx + dy * dy));
}

// A* algorithm function implementation
AStar::AstarResult AStar::AStarAlgorithm(const Graph &graph, char from, char to, char wolfPosition)
{
    // assign the adjacency list
    const auto &adjList = graph.getAdjList();

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

            // ignore the wolf position
            if (nextNode == wolfPosition)
            {
                continue;
            }

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
    try
    {
        throw runtime_error("could not find any path right now");
    }

    catch (runtime_error &x)
    {
        cerr << "<<<< Error: " << x.what() << endl;
    }

    return {{}, -1};
}

// get path method implementation
vector<char> AStar::getPath() const
{
    return AStarpath;
}

// print path function implementation
void AStar::AStarprintPath(const Graph &graph, char from, char to, char wolfPosition)
{
    AstarResult result = AStarAlgorithm(graph, from, to, wolfPosition); // get the result of the A* algorithm
    int totalDistance = result.totalWeight;                             // get the total weight
    AStarpath = result.path;                                            // store the algorithm path in a variable

    // check if there is a bath or no
    if (AStarpath.empty())
    {
        cout << "<<<< there is not ant path possible" << endl;
    }

    // print output
    cout << GREEN << "> A* recommended path: (total distance = " << totalDistance << ")\n";
    for (size_t i = 0; i < AStarpath.size(); i++)
    {
        cout << AStarpath[i];
        if (i < AStarpath.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << RESET << endl;
}