/*************************************************************************
* File Name: queue.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Wed 15 May 2019 06:07:33 PM CST
 ************************************************************************/
#include<iostream>

using std::cout;
using std::endl;


class Queue
{
public:
    Queue()
    {
        _front = 0;
        _back = 0;
    }
    void push(int);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();

    static const int SIZE = 10;

private:
    int _queue[SIZE];
    int _front;
    int _back;
};

void Queue::push(int n)
{
    if(!Queue::full())
    {
        _queue[++_front] = n;
    }else{
        cout << "队列已满" << endl;
    }
}

void Queue::pop() 
{
    if(!Queue::empty())
    {
        _back = (_back+1) % SIZE;
    }
}

int Queue::front() 
{
    if(!Queue::empty())
    {
        cout << "队头元素是：" << _queue[_front] <<endl;
        return _queue[_front];
    }
    return 0;
}

int Queue::back()
{
    if(!Queue::empty())
    {
        cout << "队尾元素是：" << _queue[_back+1] <<endl;
        return _queue[_back+1];
    }
    return 0;
}

bool Queue::empty()
{
    if(_front == _back)
    {
        return true;
    }else{
        return false;
    }

}

bool Queue::full()
{
    if(_back == (_front+1) % SIZE)
    {
        return true;
    }else{
        return false;
    }

}

int main(void)
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.front();
    q.back();
    q.push(40);
    q.front();
    q.pop();
    q.back();


    return 0;
}
q

