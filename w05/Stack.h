#pragma once
#include "stdafx.h"

template<typename T, int SIZE = 10>
class Stack
{
public:
	Stack();
	~Stack();
	bool push(const T&);
	bool pop(T&);
	bool isEmpty() const;
	bool isFull() const;

private:
	int mTop; // location of the top element
	T *mStackPtr;
};

template<typename T, int SIZE>
Stack<T, SIZE>::Stack()
{
	mTop = -1; // Stack initially empty
	mStackPtr = new T[SIZE];
} // end Stack constructor
// push element onto stack;
// if successful, return true; otherwise, return false
template<typename T, int SIZE>
Stack<T, SIZE>::~Stack()
{
	delete[] mStackPtr;
}
template<typename T, int SIZE>
bool Stack<T, SIZE>::push(const T &pushValue)
{
	if (!isFull())
	{
		mStackPtr[++mTop] = pushValue; // place item on Stack
		return true; // push successful
	}
	return false; // push unsuccessful
}
template<typename T, int SIZE>
bool Stack<T, SIZE>::pop(T &popValue)
{
	if (!isEmpty())
	{
		popValue = mStackPtr[mTop--]; // remove item from Stack
		return true; // pop successful
	}
	return false; // pop unsuccessful
}
template<typename T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
	return mTop == -1;
}
template<typename T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
	return mTop == SIZE - 1;
}