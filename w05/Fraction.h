#pragma once
#include "stdafx.h"
class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(const Fraction &org);
	~Fraction();
	Fraction& operator=(const Fraction &source);
	Fraction& operator+=(const Fraction &other);
	friend std::ostream& operator<<(std::ostream &output, const Fraction &F);

private:
	int mNumerator;
	int mDenominator;
};

