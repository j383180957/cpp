/*************************************************************************
* File Name: student.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Thu 16 May 2019 10:40:20 AM CST
 ************************************************************************/
#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class Student
{
public:
    Student (const char* name, int id)
    : _name(new char[strlen(name)+1]())
    , _id(id)
    {
        cout << "Student(const char*, int )" << endl;
        strcpy(_name, name);
    }

    void print() const
    {
        cout << "name: " << _name << endl
             << "id: " << _id << endl;
    }

    ~Student()
    {
        delete [] _name;
        cout << "~Student" << endl;
    }

private:
    void* operator new(size_t sz);
    void operator delete(void* ret);
private:
    char* _name;
    int _id;
};

int main(void)
{
    Student stu("morning", 521);
    stu.print();

    return 0;
}

