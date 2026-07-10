#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <string>
#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<pair<string, long int>> heap;

    int parent(int i) const { return (i - 1) / 2; }
    int leftChild(int i) const { return 2 * i + 1; }
    int rightChild(int i) const { return 2 * i + 2; }

    void heapifyUp(int);
    void heapifyDown(int);

public:
    void insert(const string &, long int);
    int search(const string &) const;
    void updateScore(const string &, long int);

    bool isEmpty() const;
    pair<string, long int> getTop() const;
};

#endif