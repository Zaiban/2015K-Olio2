#pragma once
#include "stdafx.h"
#include "Stack.h"
class ownTextStack :
	public Stack<std::string>
{
public:
	friend std::ostream& operator<<(std::ostream &output, const ownTextStack &S);
};

