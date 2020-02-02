// Linked Stack and Queue
#include <iostream>
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

struct Node
{
	char data;
	Node *next;
	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class LinkedStack
{
private:
	Node *head;
public:
	LinkedStack();
	bool isEmpty();
	void push(char value);
	char pop();
	void displayStack();
};

LinkedStack::LinkedStack()
{
	head = NULL;
}

bool LinkedStack::isEmpty()
{
	if (head == NULL) return true;
	else return false;
}

void LinkedStack::push(char value)
{
	Node *temp = new Node(value);

	if (isEmpty())
		head = temp;
	else
	{
		temp->next = head;
		head = temp;
	}
}

char LinkedStack::pop()
{
	Node *p; char a;
	if (isEmpty())
	{
		a = -1;
	}
	else
	{
		a = head->data;
		p = head;
		head = head->next;
		delete p;
	}
	return a;
}

void LinkedStack::displayStack()
{
	if (isEmpty())
		cout << "Stack is empty" << endl;
	else
	{
		Stack stack(MAX_SIZE);
		
		cout << "List 1 : ";

		while (!isEmpty())
		{
			char a = pop();
			stack.push(a);
			cout << a << " ";
		}
		cout << endl;
			
		while (!stack.isEmpty())
			push(stack.pop());
	}
}

class LinkedQueue
{
private:
	Node *front;
	Node *rear;
public:
	LinkedQueue();
	bool isEmpty();
	void enqueue(char value);
	char dequeue();
	void displayQueue();
};

LinkedQueue::LinkedQueue()
{
	front = NULL; rear = NULL;
}

bool LinkedQueue::isEmpty()
{
	if (front == NULL) return true;
	else return false;
}

void LinkedQueue::enqueue(char value)
{
	Node *temp = new Node(value);

	if (isEmpty())
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

char LinkedQueue::dequeue()
{
	Node *p; char a;

	if (isEmpty())
		a = -1;
		
	else
	{
		a = front->data;
		p = front;

		if (front == rear)
		{
			front = NULL;
			rear = NULL;
		}
		else
			front = front->next;

		delete p;
	}
	return a;
}

void LinkedQueue::displayQueue()
{
	Node *p;
	
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else
	{
		p = front;
		cout << "List 2 : ";
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	bool isEmpty();
	void insertNode(char value);
	void printList(int value);
	void invertList();
	void concatenate(LinkedStack ls, LinkedQueue lq);
};

LinkedList::LinkedList()
{
	head = NULL;
}

bool LinkedList::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void LinkedList::insertNode(char value)
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

void LinkedList::printList(int value)
{
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
	{
		Node *p = head;
		cout << "List " << value << " : ";
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;

	}
}

void LinkedList::invertList()
{
	LinkedStack stack;
	LinkedList returnList;

	Node *p = head;

	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
		
	else
	{
		while (p != NULL)
		{
			stack.push(p->data);
			p = p->next;
		}
		cout << "List 4 : ";
		while (!stack.isEmpty())
		{
			char a = stack.pop();
			insertNode(a);
			cout << a << " ";
		}
	}
}

void LinkedList::concatenate(LinkedStack ls, LinkedQueue lq)
{
	while (!ls.isEmpty())
		insertNode(ls.pop());
	while (!lq.isEmpty())
		insertNode(lq.dequeue());
}

int main()
{
	LinkedStack list1;
	LinkedQueue list2;
	LinkedList list3;
	LinkedList list4;

	list1.push('a');
	list1.push('e');
	list1.displayStack();

	list2.enqueue('b');
	list2.enqueue('c');
	list2.enqueue('d');
	list2.displayQueue();

	list3.concatenate(list1, list2);	
	list3.printList(3);

	list3.invertList();

	return 0;
}