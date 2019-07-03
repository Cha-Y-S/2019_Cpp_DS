#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class stack {
public:
	int top;
	char *pal;
	int maxSize;
	
	stack(int size){
		top = -1;
		pal = new char[size];
		maxSize = size;
	}

	bool isEmpty();
	bool isFull();
	void push(char value);
	char pop();
};
bool stack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

bool stack::isFull() {
	if (top == maxSize - 1)
		return true;
	else
		return false;
}

void stack::push(char value) {
	if (isFull())
		cout << "Stack is Full" << endl;
	else
		pal[++top] = value;
}

char stack::pop() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return 0;
	}
	else
		return pal[top--];
}

void palindrome(string a);

int main() {
	string input;
	
	ifstream infile;
	infile.open("Ext.txt", ios::in);

	for (int i = 0; i < 4; i++) {
		infile >> input;
		cout << input << "\t\t";
		palindrome(input);
	}
}

void palindrome(string a) {
	stack palin(20);
	int len = a.size();
	int check = 0;
	
	for (int i = len - 1; i > len/2; i--) {
		palin.push(a.at(i));
		if (a.at((len - 1) - i) == palin.pop())
			check = 1;
		else {
			check = 0;
			break;
		}
	}
	if (check) cout << "a palindrome" << endl;
	else cout << "not a palindrome" << endl;
}