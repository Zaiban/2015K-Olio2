#include "stdafx.h"
using std::cout; using std::cin; using std::endl;

const bool DEBUG = true;

void test_1();
void test_2();
void test_3();
void test_4();

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
	std::vector<std::string> words;
	std::string line;
	std::string::size_type pos, size;
	std::ifstream file;
	file.open("merkkijono.txt");

	while (std::getline(file, line)){
		pos = 0;
		while (size = line.find(" ", pos))
		{
			words.push_back(line.substr(pos, size - pos));
			pos = size + 1;
			if (size > line.size()) break;
		}
	}
	std::sort(words.begin(), words.end());
	if (DEBUG)
	{
		for (int i = 0; i < words.size(); i++)
		{
			cout << words.at(i) << endl;
		}
	}
	else
	{
		// TODO: output to file
	}

}
void test_2()
{
	std::vector<std::string> words;
	std::string line;
	std::string word;
	std::string::size_type pos, size;
	std::ifstream file;
	file.open("merkkijono.txt");

	while (std::getline(file, line)){
		pos = 0;
		while (size = line.find(" ", pos))
		{
			word = line.substr(pos, size - pos);
			for (int i = 0; i < word.size(); i++)
			{
				if ((word[i] > ' ' && word[i] < '/') 
					|| (word[i] > '9' && word[i] < 'A')
					|| (word[i] > 'Z' && word[i] < 'a')
					|| (word[i] > 'z') )
					word.erase(i, 1);
			}
			words.push_back(word);
			pos = size + 1;
			if (size > line.size()) break;
		}
	}
	std::sort(words.begin(), words.end());
	if (DEBUG)
	{
		for (int i = 0; i < words.size(); i++)
		{
			cout << words.at(i) << endl;
		}
	}
	else
	{
		// TODO: output to file
	}
}
void test_3()
{

}
void test_4()
{

}
