#include "Henkilo.h"
#include <iostream>
using std::cout; using std::endl;


Henkilo::Henkilo()
{
}
Henkilo::Henkilo(string firstName, string lastName, string personalIndentityCode)
	:mFirstName(firstName), mLastName(lastName), mPersonalIdentityCode(personalIndentityCode)
{
}
Henkilo::~Henkilo()
{
}
Henkilo& Henkilo::operator= (const string &source)
{
	mFirstName = source.substr(0, source.find(" "));
	mLastName = source.substr(source.rfind(" ")+1);

	return *this;
}
Henkilo::operator string()
{
	return string(mFirstName + " " + mLastName);
}
void Henkilo::print() const
{
	cout << "\nFirst Name: " << mFirstName;
	cout << "\nLast Name: " << mLastName;
	cout << "\nPersonal Identity Code: " << mPersonalIdentityCode << endl;
}
void Henkilo::changeFirstName(string firstName) const
{
	mFirstName = firstName;
}