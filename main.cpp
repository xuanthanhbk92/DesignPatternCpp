#include <QCoreApplication>
#include <QDebug>
#include "Creation/singleton.h"
#include "Creation/abtractfactory.h"
#include "Creation/builder.h"
#include "Creation/objectpool.h"
#include "Creation/prototype.h"
#include "Creation/factorymethod.h"
#include "Behavior/command.h"
#include "Structure/adapter.h"
#include "Structure/decorate.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    // SingleTon
    qDebug() << "***************Single Ton************";
    SingleTon* singleTon = SingleTon::instanse();
    SingleTon::value = 100;
    //    singleTon.setValue(10);
    qDebug() << singleTon->getValue();
    SingleTon* singleTon1= SingleTon::instanse();
    qDebug()<< singleTon1->getValue();

    // AbstractFactory
    qDebug() << "***************Abstract Factory************";
    //    Factory* fac = new SimpleShapeFactory;
    Factory* fac = new RobustShapeFactory;
    Shape* shap = fac->createCurvedInstance();
    Shape* shap1 = fac->createStraintInstance();
    shap->draw();
    shap1->draw();

    // Builder
    qDebug() << "*************** Builder ************";
    const int num = 4;
    ThucDon list[] ={{1,3},{0,1},{2,2},{1,4}};
    Manager giamDoc;
    giamDoc.setBuilder(new AdultBuilder);
    giamDoc.MakeFood(list,num);
    giamDoc.getFood();
    // Object Pool
    qDebug() << "*************** Object Pool ************";

    ObjectPool *pool = ObjectPool::getInstance();
    Resource * one = pool->getResource();
    one->setValue(20);
    Resource *two =pool->getResource();
    two->setValue(30);
    qDebug() << one->getValue() << "|||||"<< two->getValue();
    pool->returnResource(one);
    Resource *three =pool->getResource();
    qDebug() << three->getValue();
    Resource *fore =pool->getResource();
    Resource *five =pool->getResource();
    Resource *six =pool->getResource();
    Resource *seven =pool->getResource();


    // Prototype
    qDebug() << "*************** Prototype ************";
    ObjectFactory::initialize();
    Prototype* object;

    /* All the object were created by cloning the prototypes. */
    object = ObjectFactory::getType1Value1();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType1Value2();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;
    object = ObjectFactory::getType2Value1();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType2Value2();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;



    // Factory Method
    qDebug() << "*************** Factory method ************";
    Cup* CupRed = Cup::getCup("red");
    std::cout << CupRed->color<< std::endl;
    Cup* CupBlue = Cup::getCup("blue");
     std::cout << CupBlue->color<<std::endl;


     // Adapter
     qDebug() << "*************** Command method ************";
     Adapter newRec(2,3,5,6);
     newRec.draw();
     // Decorator
     qDebug() << "*************** Decorator ************";
    Sung * SPK1 = new PhuKien1(new SungCoBan);
    Sung * SPK2 = new PhuKien2(new SungCoBan);
    Sung * SPK12 = new PhuKien1(new PhuKien2(new SungCoBan));


    SPK1->ban();
    SPK2->ban();
    SPK12->ban();

    delete SPK1;
    delete SPK2;
    delete SPK12;


     // Command
     qDebug() << "*************** Command method ************";
     Person  thanh("Thanh", Command());
     Person tung("Tung",Command(&thanh,&Person::listen));
     Person chau("Chau",Command(&tung,&Person::read));
     chau.write();
     tung.speak();


    return a.exec();




}
