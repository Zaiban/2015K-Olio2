#include "stdafx.h"
#pragma once
class Deal
{
public:
	Deal();
	Deal(std::string clock, double price,
		int quantity, std::string seller, std::string buyer);
	~Deal();
	friend std::ostream &operator<<(std::ostream &out, const Deal &s);
	friend std::istream &operator>>(std::istream &in, Deal &s);

	bool operator<(const Deal& rhs) const;
	bool operator==(const Deal& rhs) const;

private:
	std::string mTime;
	double mPrice;
	int mQuantity;
	std::string mSeller;
	std::string mBuyer;
};

