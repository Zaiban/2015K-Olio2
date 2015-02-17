#include "stdafx.h"
#include "Deal.h"
#pragma once
class SumDeals
{
public:

	SumDeals();
	~SumDeals();
	inline void operator()(Deal deal);
	inline long double getSum() const;

private:
	long double mSum;
};


SumDeals::SumDeals() : mSum(0)
{}


SumDeals::~SumDeals()
{}


inline void SumDeals::operator()(Deal deal)
{
	mSum += deal.getPrice() * deal.getQuantity();
}


inline long double SumDeals::getSum() const
{
	return mSum;
}