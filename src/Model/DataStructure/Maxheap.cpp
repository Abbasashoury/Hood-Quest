#include "Maxheap.h"

// heapify up method implementation
void MaxHeap::heapifyUp(int i)
{
    while (i > 0 && heap[parent(i)].second < heap[i].second)
    {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

// heapify down method implementation
void MaxHeap::heapifyDown(int i)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    // conditions to swap place in the heap
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

// insert method implementation
void MaxHeap::insert(const string &username, long int score)
{
    // add a member to the heap
    heap.push_back({username, score});
    heapifyUp((int)heap.size() - 1);
}

// search method implementation
int MaxHeap::search(const string &username) const
{
    // a for loop to search in the heap
    for (int i = 0; i < (int)heap.size(); i++)
    {
        if (heap[i].first == username)
            return i;
    }
    return -1;
}

// update score method implementation
void MaxHeap::updateScore(const string &username, long int newScore)
{
    int index = search(username);

    // if the username is not in the heap
    if (index == -1)
    {
        insert(username, newScore);
        return;
    }

    // update the user score in the heap
    long int oldScore = heap[index].second;
    heap[index].second = newScore;

    if (newScore > oldScore)
        heapifyUp(index);
    else if (newScore < oldScore)
        heapifyDown(index);
}

// max heap is empty method implementation
bool MaxHeap::MaxHeapIsEmpty() const
{
    return heap.empty();
}

// get top method implementation
pair<string, long int> MaxHeap::getTop() const
{
    return heap[0];
}

// max heap clear method implementation
void MaxHeap::clear()
{
    heap.clear();
}