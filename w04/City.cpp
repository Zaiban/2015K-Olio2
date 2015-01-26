#include "stdafx.h"
#include "City.h"


City::City()
{
	mData = new Data();
}
City::City(const string &name)
{
	mData = new Data(name);
}
City::City(const City &org)
{
	mData = org.mData;
	mData->operator++();
}
City::~City()
{
	mData->operator--();
	if (mData->Count() < 1)
	{
		delete mData;
		mData = nullptr;
	}
		
}
City &City::operator=(City &source)
{
	if (this == &source)
		return *this;
	
	// left side data one less
	// basically same operation as in the destructor
	mData->operator--();
	if (mData->Count() < 1)
		delete mData;
	
	// right side data one more
	source.mData->operator++();

	this->mData = source.mData;

	return *this;
}
const string &City::Name() const
{
	return mData->Name();
}

City::Data::Data(string paikkakunta) : mName(paikkakunta), mCount(1)
{
}
const string &City::Data::Name(void) const
{
	return mName;
}
long City::Data::Count()
{
	return mCount;
}
long City::Data::operator++()
{
	++mCount;
	return mCount;
}
long City::Data::operator--()
{
	--mCount;
	return mCount;
}