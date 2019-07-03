#include <iostream>

using namespace std;

class ArrayStack {
public:
	int top;
	int* stack;
	int maxSize;

	ArrayStack(int size) {
		top = -1;
		stack = new int[size];
		maxSize = size;
	}

	bool isEmpty();
	bool isFull();
	void push(int data);
	int pop();
};

bool ArrayStack::isEmpty() {
	if (top == -1) return true;
	else return false;
}

bool ArrayStack::isFull() {
	if (top == maxSize - 1) return true;
	else return false;
}

void ArrayStack::push(int data) {
	if (isFull())
		cout << "Stack is full" << endl;
	else {
		top++;
		stack[top] = data;
	}
}

int ArrayStack::pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	else return stack[top--];
}

struct Node {
	int data;
	Node *next;
	Node(int value) {
		data = value;
		next = 0;
	}
};

class List {
private:
	Node *head = 0;
public:
	List() {
		head = 0;
	}
	bool isEmpty();
	void insertNode(int value);
	void deleteNode(int value);
	void displayList();
	void searchList(int value);
	void printLast();
	void printNth(int value);
	void invertList();
	~List();
};

void List::invertList() {
	Node *p = head;
	ArrayStack stack(100);

	if (!isEmpty()) {
		while (p != 0) {
			stack.push(p->data);
			p = p->next;
		}
		cout << "List : ";
		while (stack.top != -1) {
			cout << stack.pop() << " ";
		}
		cout << endl;
	}
	else
		cout << "List is Empty" << endl;
}

List::~List() {
	Node *p = head;

	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

void List::printLast() {
	Node *p = head;
	Node *q = 0;

	if (isEmpty()) cout << "List is Empty" << endl;
	else {
		while (p != 0) {
			q = p;
			p = p->next;
		}
		cout << q->data << endl;
	}
}

void List::printNth(int value) {
	Node *p = 0;
	int cnt = 1;
	if (isEmpty()) cout << "List is Empty" << endl;
	else {
		p = head;
		while (p != 0) {
			if (cnt == value) {
				cout << p->data << endl;
				break;
			}
			p = p->next;
			cnt++;
		}
		if (p == 0) cout << value << " list is not found" << endl;
	}
}

void List::insertNode(int value) {
	Node *temp = new Node(value);
	Node *p = head;
	Node *q = 0;

	if (head == 0) {
		head = temp;
	}
	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else {
			q->next = temp;
		}
	}
}

bool List::isEmpty() {
	if (head == 0) {
		return true;
	}
	else {
		return false;
	}
}

void List::displayList() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		cout << "list : ";
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List is empty!" << endl;
	}
}

void List::deleteNode(int value) {
	Node *p = head;
	Node *q = 0;

	if (isEmpty())
		cout << value << " is not in the list" << endl;
	else if (head->data == value) {
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while (p != 0 && p->data != value) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			q->next = p->next;
			delete p;
		}
		else {
			cout << value << " is not in the list" << endl;
		}
	}
}

void List::searchList(int value) {
	Node *p;

	if (head != 0) {
		p = head;
		while (p != 0 && p->data != value) {
			p = p->next;
		}
		if (p) {
			cout << p->data << " is in the list" << endl;
		}
		else {
			cout << value << " is not in the list" << endl;
		}
	}
	else {
		cout << "List is empty" << endl;
	}
}

int main() {
	List ll;
	int input = 0;

	cout << "1.insert" << endl;
	cout << "2.delete" << endl;
	cout << "3.list" << endl;
	cout << "4.search" << endl;
	cout << "5.PrintLast" << endl;
	cout << "6.PrintNth" << endl;
	cout << "7.InvertList" << endl;
	cout << "8.Quit" << endl;

	while (1) {
		int value;
		cin >> input;
		switch (input) {
		case 1:
			cin >> value;
			ll.insertNode(value);
			break;
		case 2:
			cin >> value;
			ll.deleteNode(value);
			break;
		case 3:
			ll.displayList();
			break;
		case 4:
			cin >> value;
			ll.searchList(value);
			break;
		case 5:
			ll.printLast();
			break;
		case 6:
			cin >> value;
			ll.printNth(value);
			break;
		case 7:
			ll.invertList();
			break;
		default:
			ll.~List();
			cout << "All List is removed" << endl;
			break;
		}
		if (input == 8) break;
	}
}