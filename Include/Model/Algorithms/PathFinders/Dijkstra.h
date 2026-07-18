#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <queue>
#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>
#include <map>
#include <vector>
#include <functional>

class Dijkstra
{
private:
    vector<char> dijkstraPath;
    
    const string RESET = "\033[0m";
    const string GREEN = "\033[1;32m";

public:
    struct dijkstraResult; // a struct to store the dijkstra result
    struct pathFinderResult; // a struct to store the path finder result
    dijkstraResult dijkstraAlgorithm(const Graph &, char, char); // dijkstra function to make the distances table
    pathFinderResult pathFinder(const Graph &, char, char, char); // path finder function to find the shortest path
    void dijkstraPrintPath(const Graph &, char, char, char); // a function to print the path in terminal
    vector<char> getPath() const; // a getter method to return the suggested path
};

#endif