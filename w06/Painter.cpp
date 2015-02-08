#include "stdafx.h"
#include "Painter.h"

int Painter::sCounter = 0;

Painter::Painter(int data) :mData(data)
{}

Painter::~Painter()
{
	sCounter--;
}

Painter *Painter::Create(unsigned int data)
{
	if (sCounter < CREATE_LIMIT)
	{
		sCounter++;
		return new Painter(data);
	}
		
	else
		return nullptr;
}

int Painter::countPainters()
{
	return sCounter;
}

void Painter::Destroy()
{
	delete this;
}

unsigned int Painter::getData() const
{
	return mData;
}