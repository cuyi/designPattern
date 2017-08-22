// g++ -pthread -std=c++11 Singleton.cpp

#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
//单例类模板
template <class T>
class Singleton
{
protected:
	Singleton(){}
public:
	static T* instance()//返回某类型的单例对象
	{
		if(m_pInstance == NULL)//这里进行了两遍检查
		{
			pthread_mutex_lock(&mutex);//上锁
			if(m_pInstance == NULL)//保证只能执行一次
			{
				T* temp = new T;//构造一个新的对象
				m_pInstance = temp;
			}
			pthread_mutex_unlock(&mutex);//解锁
		}
		
		return m_pInstance;//返回该类型的单例对象
	}
	
private:
    static T* m_pInstance;
    static pthread_mutex_t mutex;//需要互斥锁
};

template<class T>
T* Singleton<T>::m_pInstance = NULL;

template<class T>
pthread_mutex_t Singleton<T>::mutex;

class Test:public Singleton<Test>   
{
public:
	Test()
	{
		cout << "This will be printed only once!\n" << endl;
	}
};


void* thread1(void*)//第一组线程的线程函数
{
	cout << "thread1 is running\n" << endl;
	Test* test1 = Test::instance();//调用该函数，但是Test对象只会创建一次
}

 void* thread2(void *)//第二组线程的线程函数
{
	cout << "thread2 is running\n" << endl;
	Test* test2 = Test::instance();//调用该函数，但是Test对象只会创建一次
}
int main()
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
	
	sleep(1);//等待线程结束
	return 0;
} 
