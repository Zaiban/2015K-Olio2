#pragma once
#include "stdafx.h"
namespace myNs
{
	template <typename T>
	T max(const T first, const T second);

	template <>
	const string &max(const string &first, const string &second);
}

template <typename T>
T myNs::max(const T first, const T second)
{
	if (first > second)
		return first;
	else
		return second;	
}

template<>
const string &myNs::max(const string &first, const string &second)
{
	// Couldnt get working

	if (first[0] > second[0])
		return first;
	else
		return second;
}