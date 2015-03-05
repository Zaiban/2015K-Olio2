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
	std::ifstream input;
	std::string line, word; 
	std::string::size_type wordStart, wordEnd;
	std::multiset<std::string> stringSet;
	std::multiset<std::string>::iterator wordPos;
	input.open("textfile.txt");

	if (input.is_open())
	{
		cout << "Reading text file 'textfile.txt'..\n" << endl;
		while (std::getline(input, line))
		{
			wordEnd = wordStart = 0;
			while( wordEnd < line.size())
			{
				wordEnd = line.find(' ', wordStart);
				stringSet.insert(line.substr(wordStart, wordEnd - wordStart));
				wordStart = line.find_first_not_of(' ', wordEnd);
			}
			
		}

		wordPos = stringSet.begin();
		while (wordPos != stringSet.end())
		{
			cout << "Word '" << *wordPos << "' appears " << stringSet.count(*wordPos) << " times." << endl;
			wordPos = stringSet.upper_bound(*wordPos);
		}
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
void test_3()
{

}
void test_4()
{

}
