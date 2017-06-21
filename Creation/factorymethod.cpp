#include "factorymethod.h"

Cup* Cup::getCup(std::string color)
{
    if (color == "red")
        return new RedCup();
    else if (color == "blue")
        return new BlueCup();
    else
        return 0;
}
