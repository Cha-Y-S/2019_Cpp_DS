#include <iostream>
#include <fstream>
#define MAX_SIZE 999

using namespace std;

class Stack 
{
private:
	int top;
	int size;
	char* stack;
public:
	Stack(int value);
	bool isFull();
	bool isEmpty();
	void push(char value);
	char pop();
};

Stack::Stack(int value)
{
	top = -1;
	size = value;
	stack = new char[size];
}

bool Stack::isFull()
{
	if (top == size - 1)
		return true;
	else
		return false;
}

bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

void Stack::push(char value)
{
	if (isFull())
		return;
	else
		stack[++top] = value;
}

char Stack::pop()
{
	if (isEmpty())
		return -1;
	else
		return stack[top--];

}

bool checkParenthesis(char* buffer);
bool match(char a, char b);

int main()
{
	ifstream infile;
	infile.open("lab3-1.dat", ios::in);
	char buffer[80];

	while (infile.getline(buffer, 80))
	{
		cout << buffer << "\t\t";
		bool validity = checkParenthesis(buffer);
		if (validity)
			cout << "Valid" << endl;
	}
}

bool checkParenthesis(char* buffer)
{
	Stack stack(MAX_SIZE);
	int i = 0;
	
	while(buffer[i]!='\0')
	{
		if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[')
			stack.push(buffer[i]);
		if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']')
		{
			if (stack.isEmpty())
			{
				cout << "Invalid(Unbalanced parentheses)" << endl;
				return false;
			}
			else
			{
				char temp = stack.pop();
				if (!match(temp, buffer[i]))
				{
					cout << "Invalid(Mismatched Parentheses)" << endl;
					return false;
				}
			}
		}
		i++;
	}
	if (stack.isEmpty())
		return true;
	else
	{
		cout << "Invalid(Unbalanced Parentheses)" << endl;
		return false;
	}

}

bool match(char a, char b)
{
	switch (a)
	{
	case '(':
		if (b == ')')
			return true;
		else
			return false;
	case '{':
		if (b == '}')
			return true;
		else
			return false;
	case '[':
		if (b == ']')
			return true;
		else
			return false;
	}
}