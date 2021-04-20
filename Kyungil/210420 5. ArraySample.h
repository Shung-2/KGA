#pragma once
#include <iostream>

using namespace std;

template<typename T>
class arraySample
{
public:
	T* buffer;
	int size;

	void pushBack(T data)
	{
		if (size != 0)
		{
			T* temp;
			temp = new T[size + 1];
			memcpy(temp, buffer, size * sizeof(T));
			delete[] buffer;
			buffer = temp;
		}

		buffer[size++] = data;
	}

	int GetSize() { return size; }

	T operator[](int index) const
	{
		return buffer[index];
	}

	arraySample()
	{
		size = 0;
		buffer = new T[1];
	}
	~arraySample()
	{
		delete[] buffer;
	}
};