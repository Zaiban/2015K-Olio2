#pragma once
#include "Stack.h"
template<typename T, int SIZE = 10>
class ownStack :
	public Stack<T, SIZE>
{
public:
	int space() const;
};

template<typename T, int SIZE>
int ownStack<T, SIZE>::space() const
{
	T item;
	top(item);
	return SIZE - mTop - 1;
}