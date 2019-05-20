/*************************************************************************
* File Name: singleton.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Wed 15 May 2019 03:12:44 PM CST
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

    static void destroy()
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
    Singleton(){ cout << "Singleton()" << endl; }
    ~Singleton(){ cout << "~Singleton()" << endl; }
private:
    static Singleton* _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

int main(void)
{
    Singleton * p1 = Singleton::getInstance();
    Singleton * p2 = Singleton::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    Singleton::getInstance()->print();

    Singleton::destroy();
    return 0;
}

