#include "AStar.h"

// A* result struct implementation
struct AstarResult
{
    vector<char> path;
    int totalWeight;
};

AstarResult AStar(const Graph& graph , char from , char to , char wolfPosition , heuristicFunction heuristic , )