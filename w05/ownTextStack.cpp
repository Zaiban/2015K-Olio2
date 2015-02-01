#include "stdafx.h"
#include "ownTextStack.h"


std::ostream& operator<<(std::ostream &output, const ownTextStack &S)
{
	std::string str;
	if (S.top(str))
		output << str;	else
		output << "empty";

	return output;
}