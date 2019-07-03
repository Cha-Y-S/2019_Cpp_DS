#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
	string name;
	int weight;
	int height;
	Node *next;
	Node *prev;
	Node(string s, int w, int h) {
		name = s;
		weight = w;
		height = h;
		next = 0;
		prev = 0;
	}
};

class Dll {
private:
	Node *head;
public:
	Dll() {
		head = 0;
	}
	~Dll();
	bool isEmpty();
	void insertList(string s, int w, int h);
	void insertAfter(string s, int w, int h, int value);
	void deleteList(string s);
	void forwardList();
	void backwardList();
	void searchList(string s);
	void findNth(int value);
};

Dll::~Dll() {
	Node *p = head;

	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

bool Dll::isEmpty() {
	if (head == 0) return true;
	else return false;
}

void Dll::insertAfter(string s, int w, int h, int value) {
	Node *temp = new Node(s, w, h);
	Node *p = 0;
	Node *q = 0;
	int pos = 1;

	if (isEmpty()) cout << "List is empty." << endl;
	else {
		p = head;
		while (p != 0) {
			if (pos == value) {
				q = p;
				p = p->next;
				temp->next = p;
				temp->prev = q;
				p->prev = temp;
				q->next = temp;
				break;
			}
			q = p;
			p = p->next;
			pos++;
		}
		if (p == 0) cout << value << " list is not in the list." << endl;
	}
	forwardList();
}

void Dll::insertList(string s, int w, int h) {
	Node *temp = new Node(s, w, h);
	Node *p = 0;
	Node *q = 0;

	if (isEmpty()) {
		head = temp;
	}
	else if (temp->name < head->name) {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		p = head;
		while (p != 0 && p->name < temp->name) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			temp->prev = q;
			q->next = temp;
			p->prev = temp;
		}
		else {
			q->next = temp;
			temp->prev = q;
		}
	}
}

void Dll::deleteList(string s) {
	Node *p = 0;
	Node *q = 0;

	if (isEmpty())
		cout << "List is empty." << endl;
	else if (head->name == s) {
		if (head->next != 0) {
			p = head;
			head = head->next;
			head->prev = 0;
			delete p;
		}
		else
			head = 0;
	}
	else {
		p = head;
		while (p != 0 && p->name != s) {
			q = p;
			p = p->next;
		}
		if (p->next != 0 && p->name == s) {
			q->next = p->next;
			p->next->prev = q;
			delete p;
		}
		else if (p->next == 0 && p->name == s) {
			q->next = 0;
			delete p;
		}
		else
			cout << s << " is not in the list" << endl;
	}
	forwardList();
}

void Dll::forwardList() {
	if (!isEmpty()) {
		Node *p = head;
		cout << "name\tweight\theight" << endl;
		cout << "--------------------------" << endl;
		while (p != 0) {
			cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
			p = p->next;
		}
	}
	else
		cout << "List is empty." << endl;
}

void Dll::backwardList() {
	if (!isEmpty()) {
		Node *p = head;
		while (p->next != 0)
			p = p->next;
		cout << "name\tweight\theight" << endl;
		cout << "--------------------------" << endl;
		while (p != 0) {
			cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
			p = p->prev;
		}
	}
	else
		cout << "List is empty." << endl;
}

void Dll::searchList(string s) {
	if (!isEmpty()) {
		Node *p = head;
		while (p != 0 && p->name != s)
			p = p->next;
		if (p != 0)
			cout << p->name << " is in the list" << endl;
		else
			cout << s << " is not in the list" << endl;
	}
	else
		cout << "List is empty." << endl;
}

void Dll::findNth(int value) {
	Node *p = head;
	int pos = 1;

	if (isEmpty())
		cout << "List is empty." << endl;
	else {
		while (p != 0) {
			if (pos == value) {
				cout << p->name << "\t" << p->weight << "\t" << p->height<< endl;
				break;
			}
			p = p->next;
			pos++;
		}
		if (p == 0) {
			cout << value << " list is not in the list." << endl;
		}
	}
}

int main() {
	Dll ll;
	int input = 0;
	string src;
	int find;
	int inWeight;
	int inHeight;

	ifstream infile;
	infile.open("data.txt", ios::in);

	if (infile.fail()) {
		cout << "can't open the input file." << endl;
		exit(1);
	}

	for (int i = 0; i < 4; i++) {
		string s;
		int w;
		int h;
		infile >> s >> w >> h;
		ll.insertList(s, w, h);
	}
	cout << "Menu" << endl;
	cout << "---------------------" << endl;
	cout << "1.Insert-after(nth)\t";
	cout << "2.Delete\t";
	cout << "3.Forward" << endl;;
	cout << "4.Backward\t\t";
	cout << "5.Search\t";
	cout << "6.Find-nth" << endl;
	cout << "7.Exit" << endl;

	while (input <= 6) {
		cin >> input;

		if (input >= 7) {
			ll.~Dll();
			break;
		}

		switch (input) {
		case 1:
			cin >> src >> inWeight >> inHeight >> find;
			ll.insertAfter(src, inWeight, inHeight, find);
			break;
		case 2:
			cin >> src;
			ll.deleteList(src);
			break;
		case 3:
			ll.forwardList();
			break;
		case 4:
			ll.backwardList();
			break;
		case 5:
			cin >> src;
			ll.searchList(src);
			break;
		case 6:
			cin >> find;
			ll.findNth(find);
			break;
		}
	}
}