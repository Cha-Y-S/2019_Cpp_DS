#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

class ArrayStack {
public:
	int top;
	char* stack;
	int maxSize;

	ArrayStack(int size) {
		top = -1;
		stack = new char[size];
		maxSize = size;
	}

	bool isEmpty();
	bool isFull();
	void push(char data);
	char pop();
};

bool ArrayStack::isEmpty() {
	if (top == -1) return true;
	else return false;
}

bool ArrayStack::isFull() {
	if (top == maxSize - 1) return true;
	else return false;
}

void ArrayStack::push(char data) {
	if (isFull())
		cout << "Stack is full" << endl;
	else {
		top++;
		stack[top] = data;
	}
}

char ArrayStack::pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	else return stack[top--];
}

int check(char *buffer);
bool match(char a, char b);

int main() {
	ifstream infile;
	char buffer[80];
	bool validity;
	infile.open("lab3.txt", ios::in);
	if (infile.fail()) {
		cout << "can't open the input file" << endl;
		exit(1);
	}
	while (infile.getline(buffer, 80)) {
		cout << buffer;
		validity = check(buffer);
		if (validity) cout << "Valid" << endl;
	}
}

bool match(char a, char b) {
	switch (a) {
	case '(':
		if (b == ')') return true;
		else return false;
	case '{':
		if (b == '}') return true;
		else return false;
	case '[':
		if (b == ']') return true;
		else return false;
	}
}
int check(char *buffer) {
	ArrayStack op(80);
	int i = 0;
	while(buffer[i]!=0){
		if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[')  op.push(buffer[i]);
		if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']') {
			/*for (int j = 0; j <= op.top; j++) {
				cout << "1 : Stack[" << j << "] = " << op.stack[j] << endl;
			}*/
			if (op.isEmpty()) {
				cout << "Invalid(UnBalanced parentheses)" << endl;
				return 0;
			}
			else {
				
				char temp = op.pop();
				// cout << "temp : " << temp <<"\t\t"<<"buffer : "<<buffer[i]<< endl;
				if (!match(temp, buffer[i])) {
					cout << "Invalid(Mismatched parentheses)" << endl;
					
					return 0;
				}
			}
			
		}
		i++;
	}
	if (op.isEmpty())return true;
	else {
		cout << "Invalid(UnBalanced parentheses)" << endl;
		return false;
	}
}