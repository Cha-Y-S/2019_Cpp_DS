#include<iostream>

using namespace std;

class Stack {
public:
	int top;
	char * stack;
	int max_size;

	Stack(int size) {
		top = -1;
		stack = new char(size);
		max_size = size;
	}

	bool isFull();
	bool isEmpty();
	void push(char value);
	char pop();
	void display();
};

bool Stack::isFull() {
	if (top == max_size - 1) return true;
	else return false;
}

bool Stack::isEmpty() {
	if (top == -1) return true;
	else return false;
}

void Stack::push(char value) {
	if (isFull()) cout << "Stack is Full" << endl;
	else stack[++top] = value;
}

char Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return 0;
	}
	else return stack[top--];
}

void Stack::display() {
	int i;
	if (isEmpty()) cout << "Stack is Empty" << endl;
	else {
		i = top;
		cout << "Stack : ";
		while (i > -1){
			cout << stack[i] << " ";
			i = i - 1;
		}
		cout << endl;
	}
}

class Queue {
public:
	char *queue;
	int front;
	int rear;
	int max_size;

	Queue(int size) {
		front = -1;	// front == rear => queue is empty
		rear = -1;
		queue = new char(size);
		max_size = size;
	}
	void enQueue(char value);
	char deQueue();
	bool isFull();
	bool isEmpty();
	void display();
};

void Queue::enQueue(char value) {
	if (isFull()) {
		cout << "Queue is Full" << endl;
	}
	else queue[++rear] = value;
}

char Queue::deQueue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
		return 0;
	}
	else {
		return queue[++front];
	}
}

bool Queue::isFull() {
	if (rear == max_size - 1) return true;
	else return false;
}

bool Queue::isEmpty() {
	if (front == rear) return true;
	else return false;
}

void Queue::display() {
	int i;
	if (isEmpty()) cout << "Queue is Empty" << endl;
	else {
		i = front + 1;
		cout << "Queue : ";
		while (i <= rear) {
			cout << queue[i] << " ";
			i = i + 1;
		}
		cout << endl;
	}
}

class cQueue {
public :
	int front;
	int rear;
	char *cqueue;
	int max_size;

	cQueue(int size){
		front = -1;
		rear = -1;
		cqueue = new char(size);
		max_size = size;
	}

	bool isFull();
	bool isEmpty();
	void cEnqueue(char value);
	char cDequeue();
	void display();
};
bool cQueue::isFull() {
	if ((rear + 1) % max_size == front) return true;
	else return false;
}

bool cQueue::isEmpty() {
	if (rear==front) return true;
	else return false;
}

void cQueue::cEnqueue(char value) {
	
	if (isFull()) cout << "Circular Queue is Full" << endl;
	else {
		rear = (rear + 1) % max_size;
		cqueue[rear] = value;
	}
}

char cQueue::cDequeue() {
	if (isEmpty()) {
		cout << "Circular Queue is Empty" << endl;
		return 0;
	}
	else {
		front = (front + 1) % max_size;
		return cqueue[front];
	}
}

void cQueue::display() {
	int i;
	if (isEmpty()) {
		cout << "Circular Queue is Empty" << endl;
	}
	else {
		i = front + 1;	// 1
		cout << "Circular Queue : ";
		while (i%max_size!=(rear+1)%max_size) {
			cout << cqueue[i] << " ";
			i = (i + 1) % max_size;
		}
		cout << endl;
	}
}

int main() {
	Stack stack(2);
	Queue queue(3);
	cQueue cqueue(3);

	stack.push('a');	// 1
	queue.enQueue('b');
	queue.enQueue('c');
	queue.enQueue('d');
	stack.push('e');

	stack.push('F');	//2
	queue.enQueue('G');

	cout << endl;

	stack.display();	//3
	queue.display();	//4
	//5
	cout << "Output : ";
	cout << stack.pop()<<" ";
	cout << queue.deQueue() << " ";
	cout << queue.deQueue() << " ";
	cout << queue.deQueue() << " ";
	cout << stack.pop() << endl;

	cout << endl;

	stack.pop();	//6
	queue.deQueue();

	cout << endl;

	cqueue.cEnqueue('A');	//7
	cqueue.cEnqueue('B');
	cqueue.cEnqueue('C');
	cqueue.cDequeue();
	cqueue.cEnqueue('D');

	cout << endl;

	cqueue.display();	//8

	cout << endl;

	cqueue.cDequeue();	//9
	cqueue.cDequeue();
	cqueue.cDequeue();
}