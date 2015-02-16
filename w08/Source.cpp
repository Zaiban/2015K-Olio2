#include "stdafx.h"
#include "Deal.h"
#include "IsLower.h"
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
		test_2();
		break;
	case '4':
		test_2();
		break;
	case '5':
		test_2();
		break;
	};



	system("pause");
	return 0;
}
void test_1()
{
	std::string remove;
	std::vector<Deal> deals;
	std::vector<Deal>::const_iterator i, j;
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
				output << *i << '\n';
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

}
void test_3()
{

}
void test_4()
{

}
void test_5()
{

}