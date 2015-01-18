#include "Opiskelija.h"
#include <iostream>
using std::cout; using std::endl;

Opiskelija::Opiskelija()
{
}
Opiskelija::~Opiskelija()
{
}
void Opiskelija::print() const
{
	Henkilo::print();
	cout << "Student Number: " << mStudentNumber << endl;
}
