#include <iostream>
#include <exception>
#include "Henkilo.h"
#include "Opettaja.h"
#include "Opiskelija.h"
class Perittava {};
class PerittyA : public Perittava {};
class PerittyB : public Perittava {};
using std::cout; using std::cin; using std::endl;

int main()
{
	cout << "\n===========";
	cout << "\nExercise 1";
	cout << "\n===========" << endl;

	Henkilo h1;
	h1 = "Juice Leskinen";
	h1.print();
	std::string fullName;
	fullName = h1;
	cout << "\nfullName: " << fullName << endl;

	cout << "\n===========";
	cout << "\nExercise 2";
	cout << "\n===========" << endl;

	const Henkilo model("Matti", "Meikalainen", "123456-789");
	model.print();
	model.changeFirstName("Maija");
	model.print();

	cout << "\n===========";
	cout << "\nExercise 3";
	cout << "\n===========" << endl;

	const int SIZE = 10;
	Henkilo *table[SIZE];
	Henkilo *person;
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
		{
			table[i] = new Opettaja();
		}
		else
		{
			table[i] = new Opiskelija();
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		try{
			person = dynamic_cast<Opiskelija*>(table[i]);

			if (person != nullptr)
				counter++;
		}
		catch (std::exception& e){ cout << "Expection: " << e.what(); }

		delete table[i];
		table[i] = nullptr;
		person = nullptr;

	}
	cout << "Counter: " << counter << endl;

	cout << "\n===========";
	cout << "\nExercise 4";
	cout << "\n===========" << endl;

	Perittava *pk1 = new PerittyA;
	Perittava *pk2 = new PerittyB;
	PerittyA * pPA;
	PerittyB *pPB;
	pPA = static_cast<PerittyA *>(pk1); // Works
	
	pPB = static_cast<PerittyB *>(pk2); // Works
	pPB = (PerittyB *)pk2;				// Works

	delete pk1;
	delete pk2;

	void *ppii = new double(3.14);
	double *pd;
	pd = static_cast<double *>(ppii);	// Works

	delete ppii;

	system("pause");
	return 0;
}