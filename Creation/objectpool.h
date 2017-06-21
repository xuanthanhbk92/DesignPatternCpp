#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H


#include <string>
#include <iostream>
#include <list>

class Resource
{
    int value;

    public:
        Resource()
        {
            value = 0;
        }

        void reset()
        {
            value = 0;
        }

        int getValue()
        {
            return value;
        }

        void setValue(int number)
        {
            value = number;
        }
};

/* Note, that this class is a singleton. */
class ObjectPool
{
    private:
        std::list<Resource*> resources;

        static ObjectPool* instance;
        ObjectPool():m_max(5) , m_numResource(0) {}
        int m_max;
        int m_numResource;

    public:
        /**
         * Static method for accessing class instance.
         * Part of Singleton design pattern.
         *
         * @return ObjectPool instance.
         */
        static ObjectPool* getInstance()
        {
            if (instance == 0)
            {
                instance = new ObjectPool;
            }
            return instance;
        }

        /**
         * Returns instance of Resource.
         *
         * New resource will be created if all the resources
         * were used at the time of the request.
         *
         * @return Resource instance.
         */
        Resource* getResource()
        {
            if (resources.empty()&&(m_numResource < m_max))
            {
                m_numResource++;
                std::cout << "Creating new." << std::endl;
                return new Resource;
            }
            else if(m_numResource>=m_max)
            {
                std::cout << "Exceed resource limitation." << std::endl;
                return nullptr;
            }
            else
            {
                std::cout << "Reusing existing." << std::endl;
                Resource* resource = resources.front();
                resources.pop_front();
                return resource;
            }
        }

        /**
         * Return resource back to the pool.
         *
         * The resource must be initialized back to
         * the default settings before someone else
         * attempts to use it.
         *
         * @param object Resource instance.
         * @return void
         */
        void returnResource(Resource* object)
        {
            object->reset();
            resources.push_back(object);
        }

        void setMaxResource(int max){m_max = max;}
};



#endif // OBJECTPOOL_H
