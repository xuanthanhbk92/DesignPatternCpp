#ifndef ABTRACTFACTORY_H
#define ABTRACTFACTORY_H
#include <QDebug>
/*
 *   Nha may : Nha may 1 , nha may 2, nha may 3
 *   Nha may 1:  sanPham1 , sanPham2, sanPham3
 *  Nha may 2 : sanPham4 , san pham 5 , san pham6
 *   Khach hang muon van hanh nha may 1 se tao ra -> 1 2 3
 *   Khach hang muon van hanh nha may 2 se tao ra -> 4, 5, 6
 *
 *
 *
 *
 *
 */
class AbtractFactory
{
public:
    AbtractFactory();
};

// cac doi tuong vat lieu

// interface shape
class Shape {
public:
    Shape() {m_id= m_total ++ ;}
    virtual void draw() = 0 ;
protected:
    int m_id;
    static int m_total;
};

class Circle: public Shape
{
    // Shape interface
public:
    void draw(){
    qDebug() << m_id << "Circle";
    }
};

class Square: public Shape
{
    // Shape interface
public:
    void draw(){
        qDebug() << m_id <<"Square";
    }
};

class Ellipse :public Shape
{
    // Shape interface
public:
    void draw()
    {
        qDebug() << m_id << "Ellipse";
    }
};

class Rectangle : public Shape
{
    // Shape interface
public:
    void draw()
    {
        qDebug() << m_id << "Rectangle ";
    }
};

class Factory {
public:
    virtual Shape* createCurvedInstance() = 0 ;
    virtual Shape* createStraintInstance() =0;
};

class SimpleShapeFactory : public Factory
{
    // Factory interface
public:
    Shape *createCurvedInstance(){
        return new Circle;
    }

    Shape *createStraintInstance()
    {
        return new Square;
    }
};


class RobustShapeFactory : public Factory
{
    // Factory interface
public:
    Shape *createCurvedInstance()
    {
        return new Ellipse;
    }

    Shape *createStraintInstance()
    {
        return new Rectangle;
    }
};




#endif // ABTRACTFACTORY_H
