#include "singleton.h"


// init static value ;
int SingleTon::value = 10;
// init static instance
SingleTon *SingleTon::m_instanse = 0;
// function instance
SingleTon *SingleTon::instanse()
{
    if (!m_instanse)
        m_instanse = new SingleTon();
    return m_instanse;
}
// constructor
SingleTon::SingleTon()
{

}
