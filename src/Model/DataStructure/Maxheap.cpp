#include "Maxheap.h"

void MaxHeap::heapifyUp(int i)
{
    while (i > 0 && heap[parent(i)].second < heap[i].second)
    {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void MaxHeap::heapifyDown(int i)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < (int)heap.size() && heap[left].second > heap[largest].second)
        largest = left;

    if (right < (int)heap.size() && heap[right].second > heap[largest].second)
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::insert(const string &username, long int score)
{
    heap.push_back({username, score});
    heapifyUp((int)heap.size() - 1);
}

int MaxHeap::search(const string &username) const
{
    for (int i = 0; i < (int)heap.size(); i++)
    {
        if (heap[i].first == username)
            return i;
    }
    return -1;
}

void MaxHeap::updateScore(const string &username, long int newScore)
{
    int index = search(username);

    if (index == -1)
    {
        insert(username, newScore);
        return;
    }

    long int oldScore = heap[index].second;
    heap[index].second = newScore;

    if (newScore > oldScore)
        heapifyUp(index);
    else if (newScore < oldScore)
        heapifyDown(index);
}

bool MaxHeap::MaxHeaIssEmpty() const
{
    return heap.empty();
}

pair<string, long int> MaxHeap::getTop() const
{
    return heap[0];
}