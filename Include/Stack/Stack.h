#include <vector>

class Stack
{
private:
    std:: vector <int> mystack; // create the vector

public:
    bool isEmpty() const; // a method to check if the stack is empty or no
    void push(int); // a method to add things to the stack
    int pop(); // a method to remove the last thing that has been add to the stack
};
