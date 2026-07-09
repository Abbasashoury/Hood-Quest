#ifndef STACK_H
#define STACK_H

#include <vector>
#include <utility>

class Stack
{
private:
    std::vector<std::pair<char, char>> mystack; // create the vector

public:
    bool isEmpty() const; // a method to check if the stack is empty or no
    void push(char, char); // a method to add things to the stack
    std::pair<char,char> pop(); // a method to remove the last thing that has been add to the stack
};

#endif STACK_H