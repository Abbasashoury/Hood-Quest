#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class Graph
{
private:
    map<char, vector<pair<char, int>>> adjList; // create the adjacency list

public:
    Graph(); // constructor
    void addNode(char); // a method to add new node
    void addEdge(char , char , int); // a method tp connect two edges
};