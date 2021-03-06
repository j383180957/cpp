/*************************************************************************
* File Name: Condition.h
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Fri 17 May 2019 08:13:34 PM CST
 ************************************************************************/
#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include"MutexLock.h"
#include<pthread.h>

namespace wd
{
class Condition
{
public:
    Condition(MutexLock & mutex) 
    : _mutex(mutex)
    {
        if(pthread_cond_init(&_cond, nullptr))
        {
            perror("pthread_cond_init");
        }
    }

    Condition(const Condition & rhs) = delete;
    Condition & operator = (const Condition & rhs) = delete;
    
    void wait()
    {
        if(pthread_cond_wait(&_cond, _mutex.getMutexLockptr()))
        {
            perror("pthread_cond_wait");
        }
    }
    void notify()
    {
        if(pthread_cond_signal(&_cond))
        {
            perror("pthread_cond_signal");
        }
    }

    void notifyAll()
    {
        if(pthread_cond_broadcast(&_cond))
        {
            perror("pthread_cond_broadcast");
        }
    }

    ~Condition() 
    {
        if(pthread_cond_destroy(&_cond))
        {
            perror("pthread_mutex_destroy");
        }
    }

private:
    pthread_cond_t _cond;
    MutexLock & _mutex;

};
}//end of namespace wd
#endif
