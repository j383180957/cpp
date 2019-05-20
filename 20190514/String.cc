/*************************************************************************
* File Name: String.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Tue 14 May 2019 08:59:03 PM CST
 ************************************************************************/
#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(nullptr)
    {
        cout << "String()" << endl;
    }
    //构造函数
    String(const char* pstr)
    : _pstr(new char[strlen(pstr)+1]())
    {
        cout << "String(const char* pstr)" << endl;
        strcpy(_pstr, pstr);
    }
    
    //复制构造函数
    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr)+1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }
    
    //赋值运算符函数
    String & operator = (const String & rhs)
    {
        cout << "String & operator = (const String & )" << endl;
        if(this != & rhs) //自复制
        {
            delete [] _pstr; //回收左操作数开辟的空间
            //进行深拷贝
            _pstr = new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr, rhs._pstr);
        }

        return * this;
    }


    void release()
    {
        delete [] _pstr;
    }
    ~String()
    {
        release();
        cout << "~String()" << endl;
    }

    void print()
    {
        if(this->_pstr)
        {
            cout << " >>str = " << _pstr << endl;
        }
    }
private:
    char * _pstr;
};

int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello, world";
    String str3("wangdao");
    
    str2.print();
    str3.print();

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
} 
