#include <iostream>

using namespace std;

class Stack {
private:
	int size;
	int top;
	char *stack;
public:
	Stack(int value);
	int getSize();
	bool isFull();
	bool isEmpty();
	void push(char value);
	char pop();
	void display();
};

Stack::Stack(int value) {
	size = value;
	top = -1;
	stack = new char[size];
}

int Stack::getSize() {
	return size;
}

bool Stack::isFull() {
	if (top == size - 1)
		return true;
	else
		return false;
}

bool Stack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

void Stack::push(char value) {
	if (isFull())
		cout << "Stack is Full" << endl;
	else
		stack[++top] = value;
}

char Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return 0;
	}
	else
		return stack[top--];
}

void Stack::display() {
	if (isEmpty())
		cout << "Stack is Empty" << endl;
	else {
		int i = top;
		cout << "List1 : ";
		for (; i > -1; i--)
			cout << stack[i] << " ";
		cout << endl;
	}
}

class Queue{
private:
	int front;
	int rear;
	int size;
	char *queue;
public:
	Queue(int value);
	int getSize();
	bool isFull();
	bool isEmpty();
	void enqueue(char value);
	char dequeue();
	void display();
};

Queue::Queue(int value) {
	size = value;
	front = -1;
	rear = -1;
	queue = new char[size];
}

int Queue::getSize() {
	return size;
}

bool Queue::isFull() {
	if (rear == size - 1)
		return true;
	else
		return false;
}

bool Queue::isEmpty() {
	if (rear == front)
		return true;
	else
		return false;
}

void Queue::enqueue(char value) {
	if (isFull())
		cout << "Queue is Full" << endl;
	else
		queue[++rear] = value;
}

char Queue::dequeue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
		return 0;
	}
	else
		return queue[++front];
}

void Queue::display() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		int i = front + 1;
		cout << "List2 : ";
		for (; i < rear + 1; i++)
			cout << queue[i] << " ";
		cout << endl;
	}
}

struct Node {
	char data;
	Node* next;
	Node(char value) {
		data = value;
		next = 0;
	}
};

class List {
private:
	Node *head;
public:
	List() { head = 0; }
	bool isEmpty();
	void insert(char value);
	void concatenate(Stack stack, Queue queue);
	// 2개의 리스트를 합쳐서 새로운 리스트를 만드는 함수
	void display();
	void invert();
	// 현재의 리스트를 역순으로 출력하는 함수;
};

bool List::isEmpty() {
	if (head == 0)
		return true;
	else
		return false;
}

void List::insert(char value) {
	Node * temp = new Node(value);
	Node *p = 0, *q = 0;
	
	if (isEmpty()) head = temp;
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
		else
			q->next = temp;
	}
}

void List::concatenate(Stack stack, Queue queue) {
	int stackSize = stack.getSize();
	int queueSize = queue.getSize();

	for (int i = 0; i < stackSize; i++)
		insert(stack.pop());
	for (int i = 0; i < queueSize; i++)
		insert(queue.dequeue());
}

void List::display() {
	if (isEmpty())
		cout << "Linked List is Empty" << endl;
	else {
		Node *p = head;
		cout << "List3 : ";
		while (p != 0) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void List::invert() {
	if (isEmpty())
		cout << "Linked List is Empty" << endl;
	else {
		Node *p = head;
		Stack stack(100);
		cout << "List4 : ";
		while (p != 0) {
			stack.push(p->data);
			p = p->next;
		}
		while (!stack.isEmpty()) {
			cout << stack.pop() << " ";
		}
		cout << endl;
	}
}

int main() {
	Stack stack(2);
	Queue queue(3);
	List list;

	stack.push('a');
	stack.push('e');
	stack.display();

	queue.enqueue('b');
	queue.enqueue('c');
	queue.enqueue('d');
	queue.display();

	list.concatenate(stack, queue);
	list.display();
	list.invert();
}