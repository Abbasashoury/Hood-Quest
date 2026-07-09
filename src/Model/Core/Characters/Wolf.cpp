#include "Wolf.h"

// wolf calss constructor implementation
wolf::wolf(char position)
{
    setPosition(position);
}

// set positoin implementation
void wolf::setPosition(char position)
{
    wolfPosition = position;
}

// get position method implementation
char wolf::getPosition() const
{
    return wolfPosition;
}