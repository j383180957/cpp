/*************************************************************************
* File Name: mutexlock.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Wed 15 May 2019 09:23:19 PM CST
 ************************************************************************/
#include<iostream>
#include<pthread.h>
#include<assert.h>
using std::cout;
using std::endl;

class Mutexlock
{
    friend class Condition;//将条件变量设为友元类,访问MutexLock私有成员
public:
    Mutexlock()
    : _isLocking(false)
    {
       if( pthread_mutex_init(&_mutex, NULL))
       {
           perror("pthread_mutex_init");
       }//初始化互斥变量
    }

    void lock()
    {
        if(pthread_mutex_lock(&_mutex))
        {
            perror("pthread_mutex_lock");
        }//加锁并将锁状态设为true
        _isLocking = true;
    }
    void unlock()
    {
        if(pthread_mutex_unlock(&_mutex))
        {
            perror("pthread_mutex_unlock");
        }//解锁并将锁状态设置为false
        _isLocking = false; 
    }

    bool isLocking() const //获取锁状态
    {
        return _isLocking;
    }
    pthread_mutex_t* getMutexptr()//获取锁
    {
        return &_mutex;
    }


    ~Mutexlock()
    {
        assert(!_isLocking);//确保已解锁
        pthread_mutex_destroy(&_mutex);//摧毁互斥量
    }
private:
    pthread_mutex_t _mutex;
    bool _isLocking;
    void restoreMutexStatus()//条件变量的使用
    {
        _isLocking = true;
    }
};


class Condition
{
public:
    Condition(Mutexlock& mutex)
    : _mutex(mutex)
    {
        pthread_cond_init(&_cond, NULL);
    }
    void wait()
    {
        assert(_mutex.isLocking());//必须为上锁状态
        pthread_cond_wait(&_cond, _mutex.getMutexptr());
        _mutex.restoreMutexStatus();//还原锁状态
    }
    void notify()
    {
        pthread_cond_signal(&_cond);
    }
    void notifyall()
    {
        pthread_cond_broadcast(&_cond);
    }

    ~Condition()
    {
        pthread_cond_destroy(&_cond);
    }
private:
    pthread_cond_t _cond;
    Mutexlock & _mutex;
};



int main(void)
{
    return 0;
}

