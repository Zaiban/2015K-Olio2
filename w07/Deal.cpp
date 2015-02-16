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
Deal::~Deal()
{

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

bool Deal::operator<(const Deal &rhs) const
{
	if (mPrice < rhs.mPrice) return true;
	else return false;
}

bool Deal::operator==(const Deal &rhs) const
{
	if (mQuantity == rhs.mQuantity) return true;
	else return false;
}