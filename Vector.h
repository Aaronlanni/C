//#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

template<class T>//����ģ����
struct Vector
{
public:
	//typedef T* Iterator;//������һ����������ԭ��̬��ָ��
public:
	//���캯��
	Vector()//������ʲôԪ�ض�û��
		: _start(0)
		, _finish(0)
		, _endOfStorage(0)
	{}

	Vector(const T* array, size_t size)//��������Ԫ��֮ʱ
		:_start(new T[size])
		, _finish(_start + size)
		, _endOfStorage(_start+size)
	{
		for (int i = 0; i < size; i++)
		{
			_start[i] = array[i];
		}
	}
	//�������캯��
	Vector(const Vector<T>& v)
	{
		size_t size = v.Size();
		_start = new T[size];//���ٿռ�
		for (int i = 0; i < size; ++i)
		{
			_start[i] = v._start[i];
		}
		_finish = _start + size;
		_endOfStorage = _finish;
	}

	//��ֵ�����������
	Vector& operator=(const Vector<T>& s)
	{
		if (*this != &s)
		{
			for (int i = 0; i < s._finish; i++)
			{
				_start[i] = s._start[i];
			}
		}
		return *this;
	}

	~Vector()
	{
		if (_start != NULL)
		{
			delete[]_start;
			_start = NULL;
			_finish = NULL;
			_endOfStorage = NULL;
		}
	}

//		//////////////Iterator///////////////////////////////// 
//	Iterator Begin()//����˳����еĵ�һ��λ��
//	{
//		return _start;
//	}
//
//	Iterator End()//����˳���������λ��
//	{
//		return _finish;
//	}
//
	void PushBack(const T& data)//β��
	{
		_CheckCapacity();
		*_finish++ = data;
	}
//
//	void PopBack()//βɾ
//	{
//		--_finish;
//	}
//
//	void Insert(size_t pos, const T& data)//����λ�ò���
//	{
//		assert(pos <= Size());
//		_CheckCapacity();
//		//��������
//		for (size_t i = Size(); i>pos; --i)
//		{
//			_start[i] = _start[i - 1];
//		}
//		_start[pos] = data;
//		++_finish;
//	}
//
//	void Erase(size_t pos)//����λ��ɾ��
//	{
//		assert(pos < Size());
//		for (size_t i = pos; i < Size(); ++i)
//		{
//			_start[i] = _start[i + 1];
//		}
//		--_finish;
//	}
//
//		//////////////////capacity////////////////////////////
//	size_t Size()const//Ԫ�صĸ���
//	{
//		return _finish - _start;
//	}
//	size_t Capacity()const//�����Ĵ�С
//	{
//		return _endOfStorage - _start;
//	}
//	bool Empty()const//�����п�
//	{
//		return (Size() == NULL);//_start==_finish;
//	}
//	//���Ӹ�����Resize
//	void Resize(size_t newSize, const T& data = T())
//	{
//		size_t size1 = Size();
//		size_t capacity1 = Capacity();
//		if (newSize <= size1)
//		{
//			_finish = _start + newSize;
//		}
//		else if (size1 < newSize && newSize<= capacity1)
//		{
//			for (size_t i = size1; i < newSize; ++i)
//			{
//				_start[i] = data;
//			}
//			_finish = _start + newSize;
//		}
//		else
//		{
//			//���ٿռ�
//			T*tmp = new T[newSize];
//			//��Ԫ�ؿ������¿ռ���
//			for (size_t i = 0; i < size1; ++i)
//			{
//				tmp[i] = _start[i];
//			}
//			//������Ԫ��
//			for (int i = size1; i < newSize; ++i)
//			{
//				tmp[i] = data;
//			}
//			delete[] _start;
//			_start = NULL;
//			_start = tmp;
//			_finish = _start + newSize;
//			_endOfStorage = _start + newSize;
//		}
//	}
//
//		//////////////Acess/////////////////////////// 
//	T& operator[](size_t index)
//	{
//		return _start[index];
//	}
//
//	const T& operator[](size_t index)const
//	{
//		return _start[index];
//	}
//
//	T& Front()
//	{
//		return *Begin();
//	}
//	const T& Front()const
//	{
//		return *Begin();
//	}
//	T& Back()
//	{
//		return *(_finish - 1);
//	}
//	const T& Back()const
//	{
//		return *(_finish - 1);
//	}
//	void Clear()
//	{
//		_finish = _start;
//	}
//
//	//void Display()//��ӡ����
//	//{
//	//	if
//	//}
friend ostream& operator<<(ostream& _cout, const Vector<T>& v)
{
	for (int i = 0; i < Size(); ++i)
	{
		cout << v._start[i];
	}
	return _cout;
}

private:
	void _CheckCapacity()
	{
		int size = Size();
		int capacity = Capacity();
		if (capacity <= size)
		{
			size_t NewCapacity = capacity * 2 + 3;//�ı������Ĵ�С
		}
		//�����¿ռ�
		T*tmp = new T[NewCapacity];

		//����Ԫ��

		//memcpy(tmp, _start, size*sizeof(T));

		for (int i = 0; i < size; ++i)
		{
			tmp[i] = _start[i];
		}

		//�ͷžɿռ�
		if (_start)//���ԭ���Ŀռ䱾�����ǿյģ�����Ҫ�ڽ����ͷţ���ֹ���ΪҰָ�롣
			delete[] _start;
		_start = tmp;
		_finish = _start + size;
		__endOfStorage = _start + NewCapacity;

	}

	
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
//
//

void FunTest()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
}



