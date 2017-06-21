#ifndef BUILDER_H
#define BUILDER_H

#include <QString>
#include <QStringList>
#include <QDebug>

// ** ------------
// ** ------------

typedef struct tagThucDon
{
    int Numer;
    int SoLuong;
} ThucDon;


class KhayCom
{
public:
     void themMon(QString mon){
        m_KhayCom.append(mon);
    }
     void bayMon()
     {
         for (int i =0; i<m_KhayCom.size(); ++i)
             qDebug()<< m_KhayCom.at(i);
     }


private:
    QStringList m_KhayCom;
};


// interface
class Builder
{
public:
    Builder():m_khayCom(new KhayCom){}
    virtual void makeCanh()= 0;
    virtual void makeCom() = 0;
    virtual void makeTrangMieng()=0;
    KhayCom * m_khayCom;
};

class ChildBuilder: public Builder
{
    // Builder interface
public:
    void makeCanh(){
        m_khayCom->themMon("CanhThit");
    }
    void makeCom()
    {
        m_khayCom->themMon("Chao");
    }

    void makeTrangMieng(){
        m_khayCom->themMon("TraiCay");
    }
};

class AdultBuilder: public Builder
{
    // Builder interface
public:
    void makeCanh(){
        m_khayCom->themMon("CanhNguVi");
    }
    void makeCom()
    {
        m_khayCom->themMon("ComRang");
    }

    void makeTrangMieng(){
        m_khayCom->themMon("ThiGaXephay");
    }

};


class Manager
{
public:
    Manager(Builder* builder):m_builder{builder}{}
    Manager(){}
    void setBuilder(Builder *builder)
    {
        m_builder = builder;
    }

     void MakeFood(ThucDon list[], int num)
    {
         for (int i=0;i<=num;++i)
         {
             switch (list[i].Numer) {
             case 0:
                 for (int i=0;i<=list[i].SoLuong;++i)
                 m_builder->makeCanh();
                 break;
             case 1:
                 for (int i=0;i<=list[i].SoLuong;++i)
                 m_builder->makeCom();
                 break;
             case 2:
                 for (int i=0;i<=list[i].SoLuong;++i)
                 m_builder->makeTrangMieng();
                 break;
             default:
                 break;
             }
         }
    }

     void getFood()
     {
         m_builder->m_khayCom->bayMon();
     }
private:
    Builder *m_builder;
};


#endif // BUILDER_H
