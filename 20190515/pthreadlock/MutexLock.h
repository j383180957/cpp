/*************************************************************************
* File Name: MutexLock.h
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Fri 17 May 2019 02:04:28 PM CST
 ************************************************************************/
#ifndef  __WD_MUTEXLOCK_H__
#define  __WD_MUTEXLOCK_H__
#include<stdio.h>
#include<errno.h>
#include<pthread.h>

namespace wd
{

class MutexLock
{
public:
    MutexLock() 
    : _isLocking(false)
    {
        if(pthread_mutex_init(&_mutex, NULL))
        {
            perror("pthread_mutex_init");
        }
    }
    //C++11 表达进制复制，表达对象语义
    //C++天生支持复制，表达之语义，值复制、
    
    MutexLock(const MutexLock &) = delete;
    MutexLock & operator = (const MutexLock & ) = delete;


    ~MutexLock() 
    {
        if(pthread_mutex_destroy(&_mutex))
        {
            perror("pthread_mutex_destory");
        }
    }

    void lock()
    {
        if(pthread_mutex_lock(&_mutex))
        {
            perror("pthread_mutex_lock");
        }
        _isLocking = true;
    }
    
    void unlock()
    {
        if(pthread_mutex_unlock(&_mutex))
        {
            perror("pthread_mutex_unlock");
        }
        _isLocking = false;
    }

    bool isLocking() const {    return _isLocking;  }
    pthread_mutex_t * getMutexLockptr() {   return &_mutex; }
    
private:
    pthread_mutex_t _mutex;
    bool _isLocking;

};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock & mutex)
    : _mutex(mutex)
    {
        _mutex.lock();
    }

    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    MutexLock & _mutex;
};

}//end of namespace wd 

#endif
