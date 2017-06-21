#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H


#include <iostream>
#include <string>

class Cup
{
    public:
        Cup()
        {}

        std::string color;

        /* This is the factory method. */
        static Cup* getCup(std::string color);
};

class RedCup : public Cup
{
    public:
        RedCup()
        {
            color = "red";
        }
};

class BlueCup : public Cup
{
    public:
        BlueCup()
        {
            color = "blue";
        }
};




#endif // FACTORYMETHOD_H
