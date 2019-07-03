#include <iostream>

struct Node {
	char data;
	Node *next;
	Node(int value) {
		data = value;
		next = 0;
	}
};

class LinkedList {
private:
	Node *head = 0;
public:
	LinkedList() {
		head = 0;
	}
	bool isEmpty();
	void insertNode(char value);
	void deleteNode(char value);
	void displayNode();

};