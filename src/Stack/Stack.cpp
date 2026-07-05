#include <Stack.h>

// isEmpty method implementation
bool Stack:: isEmpty() const
{
    return (mystack.size() == 0);
}

// push method implementation
void Stack:: push(int x)
{
    mystack.push_back(x);
}

// pop method implementation
int Stack:: pop()
{
    int temp;
    temp = mystack.back();
    mystack.pop_back();
    return (temp);
}