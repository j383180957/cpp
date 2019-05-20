/*************************************************************************
* File Name: TestThread.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Fri 17 May 2019 02:34:25 PM CST
 ************************************************************************/
#include "MutexLock.h"
#include "Condition.h"
#include <iostream>

using std::cout;
using std::endl;

int gTicket = 100;
bool flag = true;

wd::MutexLock mutex; //系统资源，不能进行复制
wd::Condition condition(mutex);

void * threadFunc1(void* arg)
{ //flag 为true时， 执行减1的操作
    int cnt = 20;

    while(cnt--)
    {
        {
            wd::MutexLockGuard autolock(mutex);//防止死锁
            if(false == flag)
            {
                condition.wait();
            }

            --gTicket;
            cout << "sub thread" << pthread_self() << ":"
                 << "gTicket = " << gTicket << endl;
            if(flag)
            {
                flag = false;
            }
        }
        condition.notify();
    }
        return NULL;
}

void * threadFunc2(void* arg)
{ //flag 为true时， 执行减1的操作
    int cnt = 20;
    while(cnt--)
    {
        {
        wd::MutexLockGuard autolock(mutex);//防止死锁
        if(false == flag)
        {
            condition.wait();
        }

        --gTicket;
        cout << "sub thread" << pthread_self() << ":"
             << "gTicket = " << gTicket << endl;
        if(false == flag)            
        {
            flag = true;
        }
        }
    condition.notify();
    }
    return NULL;
}


int main(void)
{
    pthread_t pthid1, pthid2;
    pthread_create(&pthid1, NULL, threadFunc1, NULL);
    pthread_create(&pthid2, NULL, threadFunc2, NULL);

    pthread_join(pthid1, NULL);
    pthread_join(pthid2, NULL);

    
    return 0;
}

