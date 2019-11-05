#ifndef _MYSTACK_H
#define _MYSTACK_H
#include<algorithm>

#include "MyUtil.h"

template<class T>
class MyStack
{
public:
	MyStack(int stackCapacity=10);
	~MyStack();

	bool IsEmpty() const;
	T& Top() const;					//top��Ҫ��ʾ��������������ݵ�,�������з���ֵ,������ʲô��������������(T)�й�,������ T
	void Push(const T& item);
	void Pop();						//popֻ���������������,���ǲ���Ҫ����ѽ,����void
private:
	T *stack;
	int top;
	int capacity;
};

template<class T>
void MyStack<T>::Pop()
{
	if(IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}

template<class T>
inline bool MyStack<T>::IsEmpty() const  //inline -- ��������.һ���ǳ��򵥵ĺ���(�����Ĵ������),����Ҫ���úܶ��,
										 //Ϊ�˼���ÿ�ε��������ĵ�ʱ��(���ù��̺ܸ��ӵ�,�ͺܷ�ʱ��),ʹ����������(���ǵ��ú���ʱ),
										 //�൱�ڰ�������������ڲ��ĺ�������д���õ���λ��ֱ��ʹ��,ͨ�����Ӵ����������������ʱ��
										 //����, ��ʱ��Ҳ�ǲ����õ�,��ʱ��������?  �Ǻ�ʱӦ������?
{
	return top == -1;
}

template<class T>
inline T& MyStack<T>::Top() const
{
	if(IsEmpty()) throw "Stack is empty";
	return stack[top]; //����ջ�������Ԫ��(����)
}

//����ջ-----���캯�� ? ? ?
template<class T>
MyStack<T>::MyStack(int stackCapacity):capacity(stackCapacity)
{
	if(capacity < 1) throw "stack capacity must be > 0";
	stack = new T[capacity]; //����new����(����)һ��������
	top = -1; //��������topָ��-1��λ��(��ʼû�����ݵ�ʱ��,topָ��-1)
}

template<class T>
MyStack<T>::~MyStack()
{
	delete[] stack; //ɾ��������new��stack
}

template<class T>
void MyStack<T>::Push(const T& item)
{
	if(top == capacity-1)   //����
	{
		ChangeSize1D(stack, capacity, 2*capacity);
		capacity *= 2;
	}
	stack[++top] = item;
}

#endif