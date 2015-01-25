#include "stdafx.h"
#include "henkilo.h"
#include "Henkilo_ptr.h"
#include "City.h"
#include "max.h"
#include <memory>

using std::cout; using std::endl; using std::cin;

const int SIZE = 6;

void test_1();
void test_2();
void test_3();
void test_4();

int main()
{
	char command[2];

	cout << "Type the number of the test program(1, 2, 3, 4)" << endl;
	cin.getline(command, 2);

	switch (command[0]){
	case '1':
		test_1();
		break;
	case '2':
		test_2();
		break;
	case '3':
		test_3();
		break;
	case '4':
		test_3();
		break;
	};



	system("pause");
	return 0;
}

void test_1()
{
	cout << "\n===========";
	cout << "\nExercise 1";
	cout << "\n===========" << endl;

	myNs::Henkilo_ptr Person1("Donald", "Duck", "123");
	Person1->getPIC();

	myNs::Henkilo_ptr table[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		string firstname = string("Matti_") + string(std::to_string(1 + i));
		string lastname = "Meikalainen";
		string pic = std::to_string(12345 + i);
		table[i] = myNs::Henkilo_ptr(firstname, lastname, pic);
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
}

void test_2()
{
	cout << "\n===========";
	cout << "\nExercise 2";
	cout << "\n===========" << endl;

	City c1("TAMPERE");//creation
	City c2(c1);//copy constructor
	City c3; //default constructor
	cout << "Assignment" << endl;
	c3 = c1;
	cout << "End" << endl;

	cout << "\nc1.Name: " << c1.Name() << endl;
	cout << "\nc2.Name: " << c2.Name() << endl;
	cout << "\nc3.Name: " << c3.Name() << endl;
}

void test_3()
{
	int i = myNs::max(3, 5);
	cout << "intmax: " << i << endl;

	float f = myNs::max(5.2, 0.6);
	cout << "floatmax: " << f << endl;

	string s = myNs::max(string("abcd"), string("edfg"));
	cout << "stringmax: " << s << endl;
}

void test_4()
{
	cout << "\n===========";
	cout << "\nExercise 4";
	cout << "\n===========" << endl;

	using myNs::Henkilo_ptr;

	Henkilo_ptr Person1("Donald", "Duck", "123");
	Person1->getPIC();

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
}