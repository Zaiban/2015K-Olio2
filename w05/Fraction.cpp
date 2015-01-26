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
{
	//TODO
}


Fraction::~Fraction()
{
}


Fraction& Fraction::operator=(const Fraction &source)
{
	//TODO
	return Fraction();
}


std::ostream& operator<<(std::ostream &output, const Fraction &F)
{
	output << F.mNumerator << "/" << F.mDenominator;
	return output;
}