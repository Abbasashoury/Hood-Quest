#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <queue>
#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>

class dijkstra
{
private:
    vector<char> path;
public:
    struct dijkstraResult; // a struct to store the dijkstra result
    struct pathFinderResult; // a struct to store the path finder result
    dijkstraResult dijkstraAlgorithm(const Graph &, char, char); // dijkstra function to make the distances table
    pathFinderResult pathFinder(const Graph &, char, char, char); // path finder function to find the shortest path
    void dijkstraPrintPath(const Graph &, char, char, char); // a function to print the path in terminal
};

#endif DIJKSTRA_H