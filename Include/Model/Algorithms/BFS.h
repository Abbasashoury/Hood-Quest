#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <queue>
#include <algorithm>

// bfs function to find the best path for the wolf
vector<char> BFS(const Graph &, char, char);
// return the next postion that the wolf should go
char wolfNextPosition(char , char);

#endif BFS_H