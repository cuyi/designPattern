// g++ -pthread -std=c++11 Singleton_2.cpp

#include <iostream>
#include <pthread.h>
#include <unistd.h>

class singleton{
private:
    singleton()
    {
        pthread_mutex_init(&mutex, nullptr);
    }

private:
    static singleton* p;

public:
    static pthread_mutex_t mutex;
    static singleton* instance();
};

pthread_mutex_t singleton::mutex;
singleton* singleton::p = nullptr;
singleton* singleton::instance()
{
    if(p == nullptr)
    {
        pthread_mutex_lock(&mutex);
        if(p == nullptr)
        {
            p = new singleton();
            printf("I will print only once\n");
        }
        pthread_mutex_unlock(&mutex);
    }

    return p;
}

void* thread1(void*)//第一组线程的线程函数
{
    std::cout << "thread1 is running\n" << std::endl;
    singleton::instance();
}

 void* thread2(void *)//第二组线程的线程函数
{
    std::cout << "thread2 is running\n" << std::endl;
    singleton::instance();
}

int main(void)
{
    const unsigned int thread_num = 5;
    pthread_t thread_id[thread_num];
    
    for(unsigned int i = 0; i<thread_num;i++)//创建1组5个线程
    {
        pthread_create(&thread_id[i], NULL, thread1, NULL);
    }
    
    for(unsigned int i = 0; i<thread_num;i++)//创建另一组的五个线程
    {
        pthread_create(&thread_id[i], NULL, thread2, NULL);
    }
    
    sleep(1);   // 等待线程结束
    
    return 0;
}