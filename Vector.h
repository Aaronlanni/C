//#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

template<class T>//声明模板类
struct Vector
{
public:
	//typedef T* Iterator;//定义了一个迭代器，原生态的指针
public:
	//构造函数
	Vector()//容器中什么元素都没有
		: _start(0)
		, _finish(0)
		, _endOfStorage(0)
	{}

	Vector(const T* array, size_t size)//容器中有元素之时
		:_start(new T[size])
		, _finish(_start + size)
		, _endOfStorage(_start+size)
	{
		for (int i = 0; i < size; i++)
		{
			_start[i] = array[i];
		}
	}
	//拷贝构造函数
	Vector(const Vector<T>& v)
	{
		size_t size = v.Size();
		_start = new T[size];//开辟空间
		for (int i = 0; i < size; ++i)
		{
			_start[i] = v._start[i];
		}
		_finish = _start + size;
		_endOfStorage = _finish;
	}

	//赋值运算符的重载
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
//	Iterator Begin()//返回顺序表中的第一个位置
//	{
//		return _start;
//	}
//
//	Iterator End()//返回顺序表中最后的位置
//	{
//		return _finish;
//	}
//
	void PushBack(const T& data)//尾插
	{
		_CheckCapacity();
		*_finish++ = data;
	}
//
//	void PopBack()//尾删
//	{
//		--_finish;
//	}
//
//	void Insert(size_t pos, const T& data)//任意位置插入
//	{
//		assert(pos <= Size());
//		_CheckCapacity();
//		//搬移数据
//		for (size_t i = Size(); i>pos; --i)
//		{
//			_start[i] = _start[i - 1];
//		}
//		_start[pos] = data;
//		++_finish;
//	}
//
//	void Erase(size_t pos)//任意位置删除
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
//	size_t Size()const//元素的个数
//	{
//		return _finish - _start;
//	}
//	size_t Capacity()const//容器的大小
//	{
//		return _endOfStorage - _start;
//	}
//	bool Empty()const//容器判空
//	{
//		return (Size() == NULL);//_start==_finish;
//	}
//	//增加个数到Resize
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
//			//开辟空间
//			T*tmp = new T[newSize];
//			//将元素拷贝到新空间中
//			for (size_t i = 0; i < size1; ++i)
//			{
//				tmp[i] = _start[i];
//			}
//			//拷贝新元素
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
//	//void Display()//打印函数
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
			size_t NewCapacity = capacity * 2 + 3;//改变容量的大小
		}
		//申请新空间
		T*tmp = new T[NewCapacity];

		//拷贝元素

		//memcpy(tmp, _start, size*sizeof(T));

		for (int i = 0; i < size; ++i)
		{
			tmp[i] = _start[i];
		}

		//释放旧空间
		if (_start)//如果原来的空间本来就是空的，则不需要在进行释放，防止其成为野指针。
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



