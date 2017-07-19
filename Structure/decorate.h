#ifndef DECORATE_H
#define DECORATE_H

// interface sung
#include <QDebug>

class Sung
{
public:
    virtual ~Sung(){}
    virtual void ban()=0;
};


class SungCoBan: public Sung
{
public:
    ~SungCoBan() {
        qDebug() << "Dtor sung co ban" ;
    }
    // Sung interface
    void ban(){
        qDebug() << "Ban";
    }
};


class PhuKienSwapper : public Sung
{
    public:
    PhuKienSwapper(Sung* phukien):m_coresung(phukien){}
    // Sung interface
    ~PhuKienSwapper() {
        delete m_coresung;
    }


    void ban(){
        m_coresung->ban();
    }
private:
    Sung *m_coresung;
};

class PhuKien1 : public PhuKienSwapper
{
public:
    PhuKien1(Sung* core ) :PhuKienSwapper(core){}
    ~PhuKien1(){
        qDebug() <<"Pk1 Dtor";
    }
    // Sung interface

    void ban(){
        PhuKienSwapper::ban();
        qDebug() << "PK1 Ban";
    }
};

class PhuKien2 : public PhuKienSwapper
{
public:
    PhuKien2(Sung* core ) :PhuKienSwapper(core){}
    ~PhuKien2(){
        qDebug() <<"Pk2 Dtor";
    }
    // Sung interface
public:
    void ban(){
        PhuKienSwapper::ban();
        qDebug() << "PK2 Ban";
    }
};

class PhuKien3 : public PhuKienSwapper
{
public:
    PhuKien3(Sung* core ) :PhuKienSwapper(core){}
    ~PhuKien3(){
        qDebug() <<"Pk3 Dtor";
    }
    // Sung interface
public:
    void ban(){
        PhuKienSwapper::ban();
        qDebug() << "PK3 Ban";
    }
};



#endif // DECORATE_H
