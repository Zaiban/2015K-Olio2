#include "stdafx.h"
#include "Deal.h"

Deal::Deal()
	: mTime(""), mPrice(0), mQuantity(0), mSeller(""), mBuyer("")
{

}


Deal::Deal(std::string clock, double price,
	int quantity, std::string seller, std::string buyer)
	: mTime(clock), mPrice(price), mQuantity(quantity), mSeller(seller), mBuyer(buyer)
{

}


Deal::Deal(const Deal &org)
	: mTime(org.mTime), mPrice(org.mPrice), mQuantity(org.mQuantity), mSeller(org.mSeller), mBuyer(org.mBuyer)
{
}


Deal::~Deal()
{

}


Deal& Deal::operator=(const Deal &source)
{
	if (this != &source)
	{
		mTime = source.mTime;
		mPrice = source.mPrice;
		mQuantity = source.mQuantity;
		mSeller = source.mSeller;
		mBuyer = source.mBuyer;
	}
	return *this;
}


bool Deal::operator<(const Deal &rhs) const
{
	if (mQuantity < rhs.mQuantity) return true;
	else return false;
}


bool Deal::operator==(const Deal &rhs) const
{
	if (mQuantity == rhs.mQuantity) return true;
	else return false;
}


std::ostream &operator<<(std::ostream &out, const Deal &s)
{
	out << s.mTime << "	" << s.mPrice << "	" << s.mQuantity << "	" << s.mBuyer << "	" << s.mSeller;
	return out;
}


std::istream &operator>>(std::istream &in, Deal &s)
{
	in >> s.mTime >> s.mPrice >> s.mQuantity >> s.mBuyer >> s.mSeller;
	return in;
}