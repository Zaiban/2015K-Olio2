#include "stdafx.h"
#include "Deal.h"

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
	std::ifstream input;
	std::string line, word;
	std::string::size_type wordStart, wordEnd;
	std::map<std::string, int> stringMap;
	input.open("textfile.txt");

	if (input.is_open())
	{
		cout << "Reading text file 'textfile.txt'..\n" << endl;
		while (std::getline(input, line))
		{
			wordEnd = wordStart = 0;
			while (wordEnd < line.size())
			{
				wordEnd = line.find(' ', wordStart);
				auto resultPair = stringMap.insert(std::pair<std::string, int>(line.substr(wordStart, wordEnd - wordStart), 1));
				if (resultPair.second == false)
					resultPair.first->second++;
				wordStart = line.find_first_not_of(' ', wordEnd);
			}

		}

		std::for_each(stringMap.begin(), stringMap.end(), [](std::pair<std::string, int> pair){
			cout << "Word'" << pair.first << "' appears " << pair.second << " times." << endl;
		});
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
void test_4()
{
	std::string remove;
	std::vector<Deal> V;
	std::map < std::string, std::pair<int, double> > dealMap;
	std::pair<int, double> quantityAndPrice;
	std::ifstream input;
	std::ofstream output;
	std::string sellerName;
	cout << "Please input seller name: ";
	getline(cin, sellerName);

	input.open("nokia18032009.txt");
	if (input.is_open())
	{
		getline(input, remove);
		copy(std::istream_iterator<Deal>(input), std::istream_iterator<Deal>(), back_inserter(V));

		std::for_each(V.begin(), V.end(), [&](Deal deal){
			quantityAndPrice.first = deal.getQuantity();
			quantityAndPrice.second = deal.getPrice() * quantityAndPrice.first;
			auto result = dealMap.insert(std::pair<std::string, std::pair<int, double>>(deal.getSeller(), quantityAndPrice));
			if (result.second == false)
			{
				result.first->second.first += quantityAndPrice.first;
				result.first->second.second += quantityAndPrice.second;
			}
		});

		output.open("kaikki.txt");
		if (output.is_open())
		{
			quantityAndPrice = dealMap.find(sellerName)->second;
			cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
			cout << "Seller " << sellerName << " has " << quantityAndPrice.first << " deals for a total value of " <<  quantityAndPrice.second << endl;
			output << std::setiosflags(std::ios::fixed) << std::setprecision(2);
			output << "Seller " << sellerName << " has " << quantityAndPrice.first << " deals for a total value of " << quantityAndPrice.second << endl;
		}
		else
			std::cerr << "Error opening file for writing." << endl;
	}
	else
		std::cerr << "Error opening file for reading." << endl;
}
