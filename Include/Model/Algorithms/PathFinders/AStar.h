#ifndef ASTAR_H
#define ASTAR_H

#include "Graph.h"
#include <functional>
#include <queue>
#include <algorithm>
#include <cmath>

struct AstarResult; // a struct to store the finall result of A* algorithm
using heuristicFunction = std::function<int(char , char)>; // define a new function type
AstarResult AStar(const Graph& , char , char , char , heuristicFunction); // A* algorithm function
int manhatanHeuristic(char , char); // a function to turn the graph into a network
int euclideanHeuristic (char , char); // a function to calculate heauristic euclidean distance 

#endif ASTAR_H