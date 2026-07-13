#include <Stack.h>

// isEmpty method implementation
bool Stack::isEmpty() const
{
    return (mystack.size() == 0);
}

// push method implementation
void Stack::push(char playerPosition, char wolfPosition)
{
    mystack.push_back({playerPosition, wolfPosition});
}

// pop method implementation
std::pair<char, char> Stack::pop()
{
    std::pair<char, char> temp;
    temp = mystack.back();
    mystack.pop_back();
    return (temp);
}