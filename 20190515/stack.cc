/*************************************************************************
* File Name: stack.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Wed 15 May 2019 04:55:44 PM CST
 ************************************************************************/
#include<iostream>

using std::cout;
using std::endl;

class Stack
{
public:
    Stack()
    { _top = -1; }

    void push(int);//入栈
    void pop();//出栈
    int top();//输出栈顶元素
    bool empty();//判断栈是否为空
    bool full();//判断是否栈满

private:
    int _stack[10];
    int _top;
};

void Stack::push(int n)
{
    if(!Stack::full())
    {
        _stack[++_top] = n;
    }
    else{
        cout << "栈溢出" << endl;
    }
}

void Stack::pop()
{
    if(!Stack::empty())
    {
        _top--;
    }
}

int Stack::top()
{
    if(!Stack::empty())
    {
        cout << "栈顶元素：" << _stack[_top] << endl; 
        return _stack[_top];
    }
    else{
        cout << "栈已空" << endl;
        return 0;
    }
}

bool Stack::full()
{
    if(_top == 9)
    {
        return true;
    }
    else{
        return false;
    }

}

bool Stack::empty()
{
    if(_top == -1)
    {
        return true;
    }
    else{
        return false;
    }

}

int main(void)
{
    Stack s;
    s.push(10);
    s.push(12);
    s.push(14);
    s.top();
    s.pop();
    s.top();

    return 0;
}

