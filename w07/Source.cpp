#include "stdafx.h"
#include "Deal.h"
using std::cout; using std::cin; using std::endl;

const bool DEBUG = false;

void test_1();
void test_2();

int main()
{
	char command[2];

	cout << "Type the number of the test program(1, 2, 3, 4) ";
	cin.getline(command, 2);

	switch (command[0]){
	case '1':
		test_1();
		break;
	case '2':
		test_2();
		break;
	};



	system("pause");
	return 0;
}
void test_1()
{
	std::string remove;
	std::vector<Deal> V;
	std::ifstream input;
	std::ofstream output;
	input.open("nokia18032009.txt");
	
	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(V));

		sort(V.begin(), V.end());

		output.open("harjoitus5t1.txt");
		if (output.is_open())
		{
			copy(V.begin(), V.end(), std::ostream_iterator<Deal>(output, "\n"));
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