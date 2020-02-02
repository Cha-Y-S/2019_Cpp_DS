// SLL
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class Stack
{
private:
	int top;
	vector<int> stack;
public:
	Stack();
	bool isEmpty();
	void push(int value);
	int pop();
};

Stack::Stack()
{
	top = -1;
	vector<int> stack(1);
}

bool Stack::isEmpty()
{
	if (top == -1) return true;
	else return false;
}

void Stack::push(int value)
{
	stack.push_back(value);
	top++;
}

int Stack::pop()
{
	if (top == -1)
		return -1;
	else
	{
		int num = stack[top--];
		stack.pop_back();
		return num;
	}
}

class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	void insertNode(int value);
	void deleteNode(int value);
	void searchNode(int value);
	void printLast();
	void printList();
	void printNth(int value);
	void invertList();
};

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Node *p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

bool LinkedList::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void LinkedList::insertNode(int value)
{
	Node *temp = new Node(value);
	Node *p, *q;

	if (isEmpty())
		head = temp;
	else if (temp->data < head->data)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		p = head;
		q = head;
		while ((p != NULL) && (p->data < temp->data))
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			temp->next = p;
			q->next = temp;
		}
		else
			q->next = temp;
	}
}

void LinkedList::deleteNode(int value)
{
	Node *p = NULL;
	Node *q = NULL;

	if (isEmpty())
		cout << "List is Empty" << endl;
	else if (head->data == value)
	{
		p = head;
		head = head->next;
		delete p;
	}
	else
	{
		p = head;
		while ((p != NULL) && (p->data != value))
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			q->next = p->next;
			delete p;
		}
		else
			cout << value << " is not in the list" << endl;
	}
}

void LinkedList::searchNode(int value)
{
	Node *p = head;
	int cnt = 1;
	while ((p != NULL) && (p->data == value))
	{
		p = p->next;
		cnt++;
	}
	if (p == NULL)
		cout << value << " is not in the list" << endl;
	else
		cout << value << " is in the list at " << cnt << " position." << endl;
}

void LinkedList::printLast()
{
	Node *p = head;
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
	{
		while (p->next != NULL)
			p = p->next;
		cout << p->data << " is last data of list" << endl;
	}
}

void LinkedList::printList()
{
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
	{
		Node *p = head;
		cout << "List : ";
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;

	}
}

void LinkedList::printNth(int value)
{
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
	{
		Node *p = head;
		int cnt = 1;
		while ((p != NULL) && (cnt == value))
		{
			p = p->next;
			cnt++;
		}
		if (p != NULL)
			cout << value << " th data is not in the list" << endl;
		else
			cout << value << " th data is " << p->data << endl;
	}
}

void LinkedList::invertList()
{
	Stack stack;
	
	Node *p = head;
	
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
	{
		while (p != NULL)
		{
			stack.push(p->data);
			p = p->next;
		}
		cout << "Invert List : ";
		while (!stack.isEmpty())
		{
			cout << stack.pop() << " ";
		}
		cout << endl;
	}
}

int main()
{
	LinkedList sll;

	sll.deleteNode(10);
	
	sll.insertNode(10);
	sll.insertNode(5);
	sll.printList();

	sll.insertNode(30);
	sll.searchNode(5);

	sll.deleteNode(5);
	sll.printList();

	sll.printNth(3);
	sll.printLast();

	sll.insertNode(40);
	sll.invertList();

	return 0;
}