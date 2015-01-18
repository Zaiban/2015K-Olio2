#pragma once
#include "Henkilo.h"
class Opettaja :
	public Henkilo
{
public:
	Opettaja();
	~Opettaja();

	void print() const;
	
private:
	string mKnowledgeCenter;
};

