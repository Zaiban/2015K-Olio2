#include "stdafx.h"
#include "henkilo.h"
#include "Henkilo_ptr.h"
#include <memory>

using std::cout; using std::endl;

const int SIZE = 6;

int main()
{
	cout << "\n===========";
	cout << "\nExercise 1";
	cout << "\n===========" << endl;

	Henkilo_ptr Person1("Donald", "Duck", "123");
	Person1->getPIC();
	cout << "Address of Person1:" << &Person1 << endl;
	cout << "Address of data that Person1 points to:" << Person1.getS() << endl;

	Henkilo_ptr table[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		string firstname = string("Matti_") + string(std::to_string(1 + i));
		string lastname = "Meikalainen";
		string pic = std::to_string(12345 + i);
		table[i] = Henkilo_ptr(firstname, lastname, pic);
	}
	cout << "Searching for person who has a PIC of '12347'.." << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (table[i]->getPIC() == "12347")
		{
			cout << "Found!" << endl;
			cout << "First name: " << table[i]->getFirstName() << endl;
			cout << "Last name: " << table[i]->getLastName() << endl;
		}
	}

	system("pause");
	return 0;
}