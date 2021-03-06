#pragma once
#include <string>
using std::string;
class Henkilo
{
public:
	Henkilo();
	Henkilo(string firstName, string lastName, string personalIndentityCode);
	~Henkilo();
	Henkilo& operator=(const string &);
	operator string();

	virtual void print() const;
	void changeFirstName(string firstName) const;

private:
	mutable string mFirstName;
	string mLastName;
	string mPersonalIdentityCode;
};

