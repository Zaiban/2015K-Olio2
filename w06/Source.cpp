#include "stdafx.h"
#include "Painter.h"
using std::cout; using std::cin; using std::endl;

const bool DEBUG = false;

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
	std::ifstream ifs;
	ifs.open("merkkijono.txt");
	if (ifs.is_open())
	{
		while (std::getline(ifs, line)){
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
		else // if debug is OFF
		{
			std::ofstream ofs;
			ofs.open("merkkijono_abc.txt");

			if (ofs.is_open())
			{
				for (int i = 0; i < words.size(); i++)
				{
					ofs << words.at(i) << endl;
				}
			}
			else
				std::cerr << "Error: cannot open file" << endl;
		}
	}
	else
		std::cerr << "Error: cannot open file" << endl;

}
void test_2()
{
	std::vector<std::string> words;
	std::string line;
	std::string word;
	std::string::size_type pos, size;
	std::ifstream ifs;
	ifs.open("merkkijono.txt");

	if (ifs.is_open())
	{
		// loop through all the lines in the file
		while (std::getline(ifs, line)){
			pos = 0;
			// find the next empty space in the line
			while (size = line.find(" ", pos))
			{
				// save the next word in a substring
				word = line.substr(pos, size - pos);
				// loop through the word to check in case of illegal characters
				for (int i = 0; i < word.size(); i++)
				{
					if ( (word[i] == '	')
						|| (word[i] >= ' ' && word[i] <= '/')
						|| (word[i] > '9' && word[i] < 'A')
						|| (word[i] > 'Z' && word[i] < 'a')
						|| (word[i] > 'z'))
					{
						word.erase(i, 1);
						// decrease i so that the following character is checked also
						// (has to be done because erase decreased the index numbers of all following characters by one)
						i--;
					}

				}
				if (word.size() > 0)
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
			std::ofstream ofs;
			ofs.open("merkkijono_abc.txt");
			
			if (ofs.is_open())
			{
				for (int i = 0; i < words.size(); i++)
				{
					ofs << words.at(i) << endl;
				}
			}
			else
				std::cerr << "Error: cannot open file" << endl;
		}
	}
	else
		std::cerr << "Error: cannot open file" << endl;
}
void test_3()
{
	std::vector<std::string> words;
	std::string line;
	std::string word;
	std::string::size_type pos, size;
	std::ifstream ifs;
	ifs.open("merkkijono.txt");

	if (ifs.is_open())
	{
		// loop through all the lines in the file
		while (std::getline(ifs, line)){
			pos = 0;
			// find the next empty space in the line
			while (size = line.find(" ", pos))
			{
				// save the next word in a substring
				word = line.substr(pos, size - pos);
				// loop through the word to check in case of illegal characters
				for (int i = 0; i < word.size(); i++)
				{
					if ((word[i] == '	')
						|| (word[i] >= ' ' && word[i] <= '/')
						|| (word[i] > '9' && word[i] < 'A')
						|| (word[i] > 'Z' && word[i] < 'a')
						|| (word[i] > 'z'))
					{
						word.erase(i, 1);
						// decrease i so that the following character is checked also
						// (has to be done because erase decreased the index numbers of all following characters by one)
						i--;
					}

				}
				if (word.size() > 2)
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
			std::ofstream ofs;
			ofs.open("merkkijono_abc.txt");

			if (ofs.is_open())
			{
				for (int i = 0; i < words.size(); i++)
				{
					ofs << words.at(i) << endl;
				}
			}
			else
				std::cerr << "Error: cannot open file" << endl;
		}
	}
	else
		std::cerr << "Error: cannot open file" << endl;
}
void test_4()
{
	std::vector<Painter*> painters;

	char command[2];

	cout << "(c) = create painter"
		<< "\n(n) = count existing painter objects"
		<< "\n(d) = destroy painter"
		<< "\n(p) = print container"
		<< "\n(q) = quit" << endl;

	while (true)
	{
		cout << "Input: ";
		cin.getline(command, 2);

		switch (command[0]){
		case 'c':
			painters.push_back(Painter::Create( painters.size() ));
			break;
		case 'n':
			cout << "Currently there are " << Painter::countPainters() << " living painter objects" << endl;
			break;
		case 'd':
			for (int i = 0; i < painters.size() ; i++)
			{
				if (painters.at(i) != nullptr)
				{
					painters.at(i)->Destroy();
					painters.at(i) = nullptr;
					break;
				}
			}
			break;
		case 'p':
			for (int i = 0; i < painters.size(); i++)
			{
				cout << "\npainters[" << i << "]: address=" << painters.at(i);
				if (painters.at(i) != nullptr)
					cout << " data=" << painters.at(i)->getData();
			}
			cout << endl;
			break;
		case 'q':
			return;
		};
	}

}
