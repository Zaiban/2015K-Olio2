#include "stdafx.h"

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

	cout << "Type the number of the test program(1, 2, 3, 4) ";
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

	};



	system("pause");
	return 0;
}
void test_1()
{
	std::set<char> charSet;
	std::string userInput;

	cout << "Please input a line of characters" << endl;
	std::getline(cin, userInput);

	std::for_each(userInput.begin(), userInput.end(), [&](char userInput){
		charSet.insert(userInput);
	});
	std::for_each(charSet.begin(), charSet.end(), [](char outputChar){
		cout << outputChar << endl;
	});

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
