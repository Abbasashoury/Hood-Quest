#ifndef ASTAR_H
#define ASTAR_H

#include "Graph.h"
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
#include <exception>
#include <iostream>

class AStar
{
private:
    vector<char> AStarpath;
public:
struct AstarResult; // a struct to store the finall result of A* algorithm
AstarResult AStarAlgorithm(const Graph &, char, char, char); // A* algorithm function
int heuristic(char, char); // a function to calculate heauristic euclidean distance
void AStarprintPath(const Graph & , char , char , char);
};


#endif ASTAR_H