#include <iostream>

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
	void printStack();
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
		cout << "Stack is Full\t";
	else
		stack[++top] = value;
}

char Stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty\t";
	}
	else
		return stack[top--];
}

void Stack::printStack()
{
	if (isEmpty())
		cout << "Stack is Empty\t";
	else
	{
		cout << "Stack : ";
		for (int i = top; i > -1; i--)
		{
			cout << stack[i] << " ";
		}
		cout << "\t";
	}
}

class Queue
{
protected:
	int rear;
	int front;
	int size;
	char* queue;
public:
	Queue(int value);
	bool isEmpty();
	bool isFull();
	void enqueue(char value);
	char dequeue();
	void printQueue();
};

Queue::Queue(int value)
{
	front = rear = -1;
	size = value;
	queue = new char[size];
}

bool Queue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if (rear == size - 1)
		return true;
	else
		return false;

}

void Queue::enqueue(char value)
{
	if (isFull())
		cout << "Queue is Full\t";
	else
		queue[++rear] = value;
}

char Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty\t";
		return -1;
	}
		
	else
		return queue[++front];
}

void Queue::printQueue()
{
	if (isEmpty())
		cout << "Queue is empty\t";
	else
	{
		cout << "Queue : ";
		for (int i = front + 1; i <= rear; i++)
			cout << queue[i] << " ";
		cout << "\t";
	}
}

class CQueue
{
private:
	int front;
	int rear;
	int size;
	char* cqueue;
public:
	CQueue(int value);
	bool isEmpty();
	bool isFull();
	void enqueue(char value);
	char dequeue();
	void printCQueue();
};

CQueue::CQueue(int value)
{
	front = rear = -1;
	size = value;
	cqueue = new char[size];
}

bool CQueue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}

bool CQueue::isFull()
{
	if (front == (rear + 1) % size)
		return true;
	else
		return false;
}

void CQueue::enqueue(char value)
{
	if (isFull())
		cout << "CQueue is Full\t";
	else
	{
		rear = (rear + 1) % size;
		cqueue[rear] = value;
	}
}

char CQueue::dequeue()
{
	if (isEmpty())
	{
		cout << "CQueue is Empty\t";
		return -1;
	}
		
	else
	{
		front = (front + 1) % size;
		return cqueue[front];
	}

}

void CQueue::printCQueue()
{
	if (isEmpty())
		cout << "CQueue is Empty\t";
	else
	{
		cout << "CQueue : ";
		int i = front;
		while (i != rear)
		{
			i = (i + 1) % size;
			cout << cqueue[i] << " ";
		}
		cout << "\t";
	}
}

int main()
{
	Stack stack(2);
	Queue queue(3);
	CQueue cqueue(3);

	stack.push('a');
	queue.enqueue('b');
	queue.enqueue('c');
	queue.enqueue('d');
	stack.push('e');

	stack.push('F');
	queue.enqueue('G');
	cout << endl;

	stack.printStack();
	queue.printQueue();
	cout << endl;

	cout << "Output : ";
	cout << stack.pop() << " ";
	cout << queue.dequeue() << " ";
	cout << queue.dequeue() << " ";
	cout << queue.dequeue() << " ";
	cout << stack.pop() << " ";
	cout << endl;

	stack.pop();
	queue.dequeue();
	cout << endl;

	cqueue.enqueue('A');
	cqueue.enqueue('B');
	cqueue.enqueue('C');
	cqueue.dequeue();
	cqueue.enqueue('D');
	cout << endl;

	cqueue.printCQueue();
	cout << endl;

	cqueue.dequeue();
	cqueue.dequeue();
	cqueue.dequeue();
	cout << endl;
	
	return 0;
}