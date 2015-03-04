#include "stdafx.h"
#include "Deal.h"
#include "IsLower.h"
#include "SumDeals.h"
#include "IsBetween.h"
using std::cout; using std::cin; using std::endl;

const bool DEBUG = false;

void test_1();
void test_2();
void test_3();
void test_4();
void test_5();

int main()
{
	char command[2];

	cout << "Type the number of the test program(1, 2, 3, 4, 5) ";
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
		test_4();
		break;
	case '5':
		test_5();
		break;
	};



	system("pause");
	return 0;
}
void test_1()
{
	std::string remove;
	std::vector<Deal> deals;
	std::vector<Deal>::iterator i, j;
	std::ifstream input;
	std::ofstream output;
	input.open("nokia18032009.txt");

	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(deals));

		sort(deals.begin(), deals.end());

		int limit;
		cout << "Input upper limit: ";
		cin >> limit;
		Deal limitD = Deal("", 0, limit, "", "");
		i = deals.begin();
		j = deals.end();
		output.open("pikkukaupat.txt");
		if (output.is_open())
		{
			while ((i = std::find_if(i, j, IsLower<Deal>(limitD))) != deals.end())
			{
				if (DEBUG)
					cout << *i << endl;
				else
					output << *i << endl;
				++i;
			}
		}
		else
			std::cerr << "Error opening file for writing." << endl;
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
void test_2()
{
	std::string remove;
	std::vector<Deal> deals;
	std::ifstream input;
	input.open("nokia18032009.txt");

	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(deals));

		SumDeals sum = std::for_each(deals.begin(), deals.end(), SumDeals());

		cout.precision(2);
		cout << "The total sum for all deals is: " << std::fixed << sum.getSum() << endl;
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
void test_3()
{
	std::string remove;
	std::vector<Deal> deals;
	std::vector<Deal>::iterator i, j;
	std::ifstream input;
	std::ofstream output;
	input.open("nokia18032009.txt");

	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(deals));

		sort(deals.begin(), deals.end());

		int size;
		cout << "Input size: ";
		cin >> size;
		i = deals.begin();
		j = deals.end();
		output.open("halututkaupat.txt");
		if (output.is_open())
		{

			while ((i = find_if(i, j, std::bind1st(std::equal_to<Deal>(), Deal("", 0, size, "", "")))) != j)
			{
				if (DEBUG)
					cout << *i << endl;
				else
					output << *i << endl;
				i++;
			}
			cout << endl;
			
		}
		else
			std::cerr << "Error opening file for writing." << endl;
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
void test_4()
{
	std::string remove;
	std::vector<Deal> deals, temp;
	std::vector<Deal>::iterator i, j;
	std::ifstream input;
	std::ofstream output;
	input.open("nokia18032009.txt");

	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(deals));

		sort(deals.begin(), deals.end());

		int lower, upper;
		cout << "Input lower limit: ";
		cin >> lower;
		cout << "Input upper limit: ";
		cin >> upper;
		i = deals.begin();
		j = deals.end();
		output.open("kaupatvalilta.txt");
		if (output.is_open())
		{

			while ((i = find_if(i, j, std::bind1st(std::less<Deal>(), Deal("", 0, lower, "", "")))) != j)
			{
				temp.push_back(*i);
				i++;
			}
			i = temp.begin();
			j = temp.end();
			while ((i = find_if(i, j, std::bind2nd(std::less_equal<Deal>(), Deal("", 0, upper, "", "")))) != j)
			{
				if (DEBUG)
					cout << *i << endl;
				else
					output << *i << endl;
				i++;
			}
			cout << endl;

		}
		else
			std::cerr << "Error opening file for writing." << endl;
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
void test_5()
{
	std::string remove;
	std::vector<Deal> deals;
	std::vector<Deal>::iterator i, j;
	std::ifstream input;
	std::ofstream output;
	input.open("nokia18032009.txt");

	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(deals));

		sort(deals.begin(), deals.end());

		int lower, upper;
		cout << "Input lower limit: ";
		cin >> lower;
		cout << "Input upper limit: ";
		cin >> upper;
		IsBetween<Deal> functor(Deal("", 0, lower, "", ""), Deal("", 0, upper, "", ""));
		i = deals.begin();
		j = deals.end();
		output.open("kaupatvalilta.txt");
		if (output.is_open())
		{

			while ((i = find_if(i, j, functor )) != j)
			{
				if (DEBUG)
					cout << *i << endl;
				else
					output << *i << endl;
				i++;
			}

			cout << endl;

		}
		else
			std::cerr << "Error opening file for writing." << endl;
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
