#ifndef SINGLETON_H
#define SINGLETON_H

/*  1. Duoc su dung khi can duy nhat 1 class cho ung dung
 *  2. Tao doi tuong ngay lan dau khoi tao va cung cap global poiter to access doi tuong nay
 *
*/

class SingleTon
{
public:
    void setValue(int value){this->value = value;}
    int getValue(){return value;}
    static int value ;
    // provide function to get instance
    static SingleTon* instanse();
protected:
    // move instructor to protected
    SingleTon();
private:
    // provide pointer to instance
    static SingleTon * m_instanse;

};

#endif // SINGLETON_H
