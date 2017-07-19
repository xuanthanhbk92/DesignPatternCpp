#ifndef PROTOTYPE_H
#define PROTOTYPE_H


/*
 * Example of `prototype' design pattern.
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>

/* Prototype base class. */
class Prototype
{
    protected:
        std::string type;
        int value;

    public:
        virtual Prototype* clone() = 0;

        std::string getType()
        {
            return type;
        }

        int getValue()
        {
            return value;
        }
};

class ConcretePrototype1 : public Prototype
{
    public:
        ConcretePrototype1(int number)
        {
            type  = "Type1";
            value = number;
        }

        Prototype* clone()
        {
            return new ConcretePrototype1(*this);
        }
};

class ConcretePrototype2 : public Prototype
{
    public:
        ConcretePrototype2(int number)
        {
            type  = "Type2";
            value = number;
        }

        Prototype* clone()
        {
            return new ConcretePrototype2(*this);
        }
};

/* Factory that manages prorotype instances and produces their clones. */
class ObjectFactory
{
    static Prototype* type1value1;
    static Prototype* type1value2;
    static Prototype* type2value1;
    static Prototype* type2value2;

    public:
        static void  initialize()
        {
            type1value1 = new ConcretePrototype1(1);
            type1value2 = new ConcretePrototype1(2);
            type2value1 = new ConcretePrototype2(1);
            type2value2 = new ConcretePrototype2(2);
        }

        static Prototype* getType1Value1()
        {
            return type1value1->clone();
        }

        static Prototype* getType1Value2()
        {
            return type1value2->clone();
        }

        static Prototype* getType2Value1()
        {
            return type2value1->clone();
        }

        static Prototype* getType2Value2()
        {
            return type2value2->clone();
        }
};


#endif // PROTOTYPE_H
