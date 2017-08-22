// g++ -pthread -std=c++11 Singleton.cpp

#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
//������ģ��
template <class T>
class Singleton
{
protected:
	Singleton(){}
public:
	static T* instance()//����ĳ���͵ĵ�������
	{
		if(m_pInstance == NULL)//���������������
		{
			pthread_mutex_lock(&mutex);//����
			if(m_pInstance == NULL)//��ֻ֤��ִ��һ��
			{
				T* temp = new T;//����һ���µĶ���
				m_pInstance = temp;
			}
			pthread_mutex_unlock(&mutex);//����
		}
		
		return m_pInstance;//���ظ����͵ĵ�������
	}
	
private:
    static T* m_pInstance;
    static pthread_mutex_t mutex;//��Ҫ������
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


void* thread1(void*)//��һ���̵߳��̺߳���
{
	cout << "thread1 is running\n" << endl;
	Test* test1 = Test::instance();//���øú���������Test����ֻ�ᴴ��һ��
}

 void* thread2(void *)//�ڶ����̵߳��̺߳���
{
	cout << "thread2 is running\n" << endl;
	Test* test2 = Test::instance();//���øú���������Test����ֻ�ᴴ��һ��
}
int main()
{
	const unsigned int thread_num = 5;
	pthread_t thread_id[thread_num];
	
	for(unsigned int i = 0; i<thread_num;i++)//����1��5���߳�
	{
		pthread_create(&thread_id[i], NULL, thread1, NULL);
	}
	
	for(unsigned int i = 0; i<thread_num;i++)//������һ�������߳�
	{
		pthread_create(&thread_id[i], NULL, thread2, NULL);
	}
	
	sleep(1);//�ȴ��߳̽���
	return 0;
} 
