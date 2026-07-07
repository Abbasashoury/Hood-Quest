#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <queue>
#include <algorithm>
#include <iostream>

struct dijkstraResult; // a struct to store the dijkstra result
struct pathFinderResult; // a struct to store the path finder result
dijkstraResult dijkstra(const Graph &, char , bool); // dijkstra function to make the distances table
pathFinderResult pathFinder(const Graph & , char , char , bool); // path finder function to find the shortest path
void printPath(const Graph &, char, char , bool); // a function to print the path in terminal

#endif DIJKSTRA_H