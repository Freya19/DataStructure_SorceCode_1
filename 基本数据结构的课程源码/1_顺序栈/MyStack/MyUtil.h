#ifndef _MYUTIL_H
#define _MYUTIL_H

//����һ���ܹ��Ŵ�����ĺ��� ======> C++��ΪʲôҪʹ��ģ��: ����ͨ�õ�ģ��, �����߸�����
template<class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize);

template<class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize)
{
	if(newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize]; //�����µ�����,��СΪnewsize��С,����ΪT,temp���ָ��ָ���������
	int number = min(oldSize, newSize);   //����,���ԷŴ������С
	std::copy(a,a+number, temp);  //����C++�Դ���copy������ԭ��������һ������������
	delete[] a;
	a=temp;
}

#endif