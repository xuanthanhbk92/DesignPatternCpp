#ifndef ADAPTER_H
#define ADAPTER_H
#include <iostream>

using namespace std;
// desire adapter
class ExpRectangle
{
public:
    virtual void draw() = 0 ;
};


class LegacyRectangle
{
public:
    LegacyRectangle(int x, int y, int h, int w)
    {
        this->x = x ;
        this->y = y ;
        this->h = h ;
        this->w = w ;
    }
    void oldDraw(){
        cout << "Old draw" << x << y << h <<w << endl;
    }

private:
    int x;
    int y;
    int h;
    int w;
};


class Adapter : public ExpRectangle, private LegacyRectangle
{
public:
    Adapter(int x, int y,int x1,int y1):LegacyRectangle(x,y,x1-x,y1-y){}


    // Rectangle interface
public:
    void draw(){
        cout << "Adapter draw" << endl;
        oldDraw();
    }
};

#endif // ADAPTER_H
