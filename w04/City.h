#pragma once
#include "stdafx.h"
using std::string;
class City
{
public:
	City();
	City(const string &name);
	City(const City &org);
	~City();
	City &operator=(City &source);
	const string &Name() const;

private:
	class Data
	{
	public:
		Data(string paikkakunta = "");
		const string &Name(void) const;
		long Count();
		long operator++();
		long operator--();

	private:
		string mName;
		long mCount;
	};
	Data *mData;
};

