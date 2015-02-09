#pragma once
#include "stdafx.h"

const int CREATE_LIMIT = 5;

class Painter
{
public:
	static Painter *Create(unsigned int data);
	static int countPainters();
	void Destroy();
	unsigned int getData() const;

private:
	Painter(int data);
	~Painter();

	static int sCounter;
	unsigned int mData;
};

