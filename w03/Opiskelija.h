#pragma once
#include "Henkilo.h"
class Opiskelija :
	public Henkilo
{
public:
	Opiskelija();
	~Opiskelija();

	void print() const;

private:
	string mStudentNumber;
};

