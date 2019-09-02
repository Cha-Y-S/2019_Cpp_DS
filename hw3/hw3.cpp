#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {	// �ٷ�� �ϴ� data�� Node�ȿ� �������ְ� next�� ����� ��
	char name;
	int Id;
	string major;
	char grade;
	Node *next;
	Node(char value, int num,string str,char chr) { // ����ü Node ������ �Լ�
		name = value;	// �Ű������� ���� value�� name���� ����
		Id = num;		// �Ű������� ���� num�� Id�� ����
		major = str;	// �Ű������� ���� str�� major�� ����
		grade = chr;	// �Ű������� ���� chr�� grade�� ����
		next = 0;		// next�� 0���� �ʱ�ȭ
	}
};

class List {
private:
	Node *head = 0;
public:
	List() {
		head = 0;
	}	// ó�� List�� ���� �� head�� 0���� ������ ��.
	bool isEmpty();
	void insertList(char name,int Id,string major,char grade);
	void displayList();
	void searchMajor(string major);
	void searchGrade(char grade);
	List mergeList(List a, List b);
};

void List::searchMajor(string major) {
	Node *p;
	int cnt = 0;	// cnt�� 0�̸� ã�� major�� ���ٴ� �ǹ�
	if (!isEmpty()) {	
		p = head;
		while (p != 0) {
			if (p->major == major) {
				cout << "name: " << p->name << " ";
				cout << "Id: " << p->Id << " ";
				cout << "Major: " << p->major << " ";
				cout << "Grade: " << p->grade << endl;
				cnt++;
			}
			p = p->next;	// ã�� �� ���� Node�� �Ѿ
		}
		if (!cnt) cout << major << " is not in the list." << endl;
	}
	else {
		cout << "List is empty." << endl;
	}
}

void List::searchGrade(char grade) {
	Node *p;
	int cnt = 0;
	if (!isEmpty()) {
		p = head;
		while (p != 0) {
			if (p->grade == grade) {
				cout << "name: " << p->name << " ";
				cout << "Id: " << p->Id << " ";
				cout << "Major: " << p->major << " ";
				cout << "Grade: " << p->grade << endl;
				cnt++;
			}
			p = p->next;
		}
		if (!cnt) cout << grade << " is not in the list." << endl;
	}
	else {
		cout << "List is empty." << endl;
	}
}

bool List::isEmpty() {
	if (head == 0) return true;	// if head = 0 then list is empty
	else return false;
}

void List::insertList(char name, int Id, string major, char grade) {
	Node *temp = new Node(name,Id,major,grade);
	//�߰��Ϸ��� List�� ������ ������ �޾ƿͼ� ���ο� Node�� ����.
	Node *p = head;
	Node *q = 0;

	if (isEmpty()) {
		head = temp;
	}
	else if (temp->name < head->name) {
		// name�� char���̹Ƿ� ASCII�ڵ尪�� ��
		temp->next = head;	// head���� ���� ������ 
		head = temp;		// �߰��Ϸ��� List�� head�� ��
	}
	else{
		p = head;
		while ((p != 0) && p->name < temp->name) {
			q = p;			// �߰��Ϸ��� List�� name�� �� �۰�
			p = p->next;	// head�� 0�� �ƴ� �� ���� �˻�
		}
		if (p != 0) {		// head�� 0�� �Ǹ� List�� �������� �߰�
			temp->next = p;
			q->next = temp;
		}
		else {				// �ڸ��� ã���� p�� q�� ���̿� List �߰�
			q->next = temp;
		}
	}
}

void List::displayList() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		while (p) {	// Node p�� 0�� �ƴҶ� ���� List ���
			cout << "name: " << p->name << " ";
			cout << "Id: " << p->Id << " ";
			cout << "Major: " << p->major << " ";
			cout << "Grade: " << p->grade << endl;
			p = p->next;
		}
	}
	else {
		cout << "List is empty." << endl;
	}
}

List List :: mergeList(List a, List b) {
	List c;		// return type�� List��
	Node *p;
	Node *q;
	p = a.head;
	q = b.head;
	if (!a.isEmpty() || !b.isEmpty()) {	// 2���� List�� �ϳ��� ������� ������
		while (p != 0) {
			c.insertList(p->name, p->Id, p->major, p->grade);
			p = p->next;	// List c�� �Ű������� ���� List a�� insert
		}
		while (q != 0) {
			c.insertList(q->name, q->Id, q->major, q->grade);
			q = q->next;	// List c�� �Ű������� ���� List b�� insert
		}
	}
	else cout << "List is empty." << endl;	// 2���� List�� ��� ���������

	return c;
}

int main() {
	List llA;	//data1�� ������ List llA ����
	List llB;	//data2�� ������ List llB ����
	List llC;	//data1�� data2�� ������ List llC ����

	ifstream infile;
	infile.open("data1.txt", ios::in);
	
	if (infile.fail()) {
		cout << "can't open the input file." << endl;
		exit(1);
	}
	for (int i = 0; i < 7; i++) {
		char a;
		int b;
		string c;
		char d;
		infile >> a >> b >> c >> d;
		llA.insertList(a, b, c, d);
	}

	infile.close();	//data1.txt�� ����

	infile.open("data2.txt", ios::in);

	if (infile.fail()) {
		cout << "can't open the input file." << endl;
		exit(1);
	}

	for (int i = 0; i < 3; i++) {
		char a;
		int b;
		string c;
		char d;
		infile >> a >> b >> c >> d;
		llB.insertList(a, b, c, d);
	}

	cout << "Solution 1" << endl;
	llA.displayList();
	cout << endl;
	
	cout << "Solution 2" << endl;
	llA.searchGrade('A');
	cout << endl;
	
	cout << "Solution 3" << endl;
	llC = llC.mergeList(llA, llB);
	llC.searchMajor("CS");
}