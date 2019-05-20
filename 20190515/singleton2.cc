/*************************************************************************
* File Name: singleton2.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Wed 15 May 2019 04:33:21 PM CST
 ************************************************************************/
#include<iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destory()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

    void print() const
    {
        cout << "Singleton::print()" << endl;
    }

private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }

    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

private:
    static Singleton* _pInstance;

};


int main(void)
{
    return 0;
}

