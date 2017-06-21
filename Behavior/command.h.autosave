#ifndef COMMAND_H
#define COMMAND_H
#include <QDebug>
class QString;
class Person;


class Command
{

private:
    Person *m_person;
    void (Person:: *m_method)();
public:
    Command(Person* person = 0, void (Person:: *mth)()= 0):m_person(person),m_method(mth){}
    void execute(){
        if (m_person != 0)
            (m_person->*m_method)();
    }

};

class Person
{
public:
    Person(QString name, Command cmd  ):m_name{name},m_command(cmd){}
    void listen();
    void speak();
    void read();
    void write();
private:
    Command m_command;
    QString m_name;
};

#endif // COMMAND_H
