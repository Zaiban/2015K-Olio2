#include "stdafx.h"
#include "Fraction.h"

Fraction::Fraction() : mNumerator(0), mDenominator(0)
{
}


Fraction::Fraction(int numerator, int denominator)
	: mNumerator(numerator), mDenominator(denominator)
{
}


Fraction::Fraction(const Fraction &org)
	: mNumerator(org.mNumerator), mDenominator(org.mDenominator)
{
	
}


Fraction::~Fraction()
{
}


Fraction& Fraction::operator=(const Fraction &source)
{
	if (this != &source)
	{
		mDenominator = source.mDenominator;
		mNumerator = source.mNumerator;
	}
	return *this;
}


Fraction& Fraction::operator+=(const Fraction &other)
{
	Fraction first = *this;
	Fraction second = other;
	Fraction sum;
	this->mDenominator = first.mDenominator * second.mDenominator;
	this->mNumerator = (first.mNumerator * second.mDenominator) + (second.mNumerator * first.mDenominator);
	while ((this->mDenominator % 2 == 0) && (this->mNumerator % 2 == 0))
	{
		this->mDenominator /= 2;
		this->mNumerator /= 2;
	}
	return *this;
}


std::ostream& operator<<(std::ostream &output, const Fraction &F)
{
	output << F.mNumerator << "/" << F.mDenominator;
	return output;
}