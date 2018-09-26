#pragma once
#ifndef BoundCheckArray_h
#define BoundCheckArray_h
#include <iostream>

template <class T>
class BoundCheckArray
{
private:
	T *arr;
	int len;
	BoundCheckArray(const BoundCheckArray &copy);
	BoundCheckArray& operator=(const BoundCheckArray &ref);

public:
	BoundCheckArray(int arrLen = 100)
		:len(arrLen)
	{
		arr = new T[len];
	}

	T& operator[](int idx)
	{
		if (idx < 0 || idx > len)
		{
			std::cout << "Array Bound Exception" << std::endl;
			exit(1);
		}
		return arr[idx];
	}

	T operator[](int idx) const
	{
		if (idx < 0 || idx > len)
		{
			std::cout << "Array Bound Exception" << std::endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetLen()
	{
		return len;
	}
	~BoundCheckArray() 
	{
		delete arr;
	}
};

#endif BoundCheckArray_h