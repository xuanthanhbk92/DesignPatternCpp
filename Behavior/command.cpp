#include "command.h"


void Person::listen()
{
    qDebug() << this->m_name << " - Listen" ;
    m_command.execute();

}

void Person::speak()
{
    qDebug() << this->m_name << " - Speak " ;
    m_command.execute();


}

void Person::read()
{
    qDebug() << this->m_name << " - Read" ;
    m_command.execute();


}

void Person::write()
{
    qDebug() << this->m_name << " - Write " ;
    m_command.execute();
}
