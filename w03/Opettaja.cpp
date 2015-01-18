#include "Opettaja.h"
#include <iostream>
using std::cout; using std::endl;

Opettaja::Opettaja()
{
}
Opettaja::~Opettaja()
{
}
void Opettaja::print() const
{
	Henkilo::print();
	cout << "Knowledge Center: " << mKnowledgeCenter << endl;
}
