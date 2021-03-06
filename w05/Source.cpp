#include "stdafx.h"
#include "Stack.h"
#include "Fraction.h"
#include "ownTextStack.h"
#include "ownStack.h"

using std::cout; using std::endl; using std::cin;

const int SIZE = 6;

void test_1();
void test_2();
void test_3();
void test_4();
// function template to manipulate Stack<T>
template<typename T, int SIZE = 10>
void testStack(
	Stack<T, SIZE> &theStack, // reference to Stack<T>
	T value, // initial value to push
	T increment, // increment for subsequent values
	const char *stackName); // name of the Stack<T> object

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
	Stack<double, 5> doubleStack;
	Stack<int> intStack;
	testStack(doubleStack, 1.1, 1.1, "doubleStack");
	testStack(intStack, 1, 1, "intStack");
}
void test_2()
{
	Stack<Fraction> fracStack;
	testStack(fracStack, Fraction(1, 2), Fraction(1, 4), "fracStack");
}
void test_3()
{
	ownTextStack ots;
	cout << ots << endl;
	ots.push("apple");
	ots.push("tree");
	cout << ots << endl;
}
void test_4()
{
	ownStack<int> os;
	cout << "free slots: " << os.space() << endl;
	cout << "pushing 1 item" << endl;
	os.push(5);
	cout << "free slots: " << os.space() << endl;
	cout << "pushing 2 items" << endl;
	os.push(5);
	os.push(5);
	cout << "free slots: " << os.space() << endl;
}
template<typename T, int SIZE>
void testStack(Stack<T, SIZE> &theStack, T value, T increment, const char *stackName)
{
	cout << "\nPushing elements onto " << stackName << '\n';
 	while (theStack.push(value))
	{
		cout << value << ' ';
		value += increment;
	}
	cout << "\nStack is full. Cannot push " << value
		<< "\n\nPopping elements from " << stackName << '\n';
	while (theStack.pop(value))
		cout << value << ' ';
		cout << "\nStack is empty. Cannot pop\n";
}