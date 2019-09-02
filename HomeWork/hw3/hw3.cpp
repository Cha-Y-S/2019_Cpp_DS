#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {	// 다뤄야 하는 data를 Node안에 선언해주고 next를 만들어 줌
	char name;
	int Id;
	string major;
	char grade;
	Node *next;
	Node(char value, int num,string str,char chr) { // 구조체 Node 생성자 함수
		name = value;	// 매개변수로 받은 value를 name으로 설정
		Id = num;		// 매개변수로 받은 num을 Id로 설정
		major = str;	// 매개변수로 받은 str을 major로 설정
		grade = chr;	// 매개변수로 받은 chr를 grade로 설정
		next = 0;		// next를 0으로 초기화
	}
};

class List {
private:
	Node *head = 0;
public:
	List() {
		head = 0;
	}	// 처음 List를 만들 때 head를 0으로 설정해 줌.
	bool isEmpty();
	void insertList(char name,int Id,string major,char grade);
	void displayList();
	void searchMajor(string major);
	void searchGrade(char grade);
	List mergeList(List a, List b);
};

void List::searchMajor(string major) {
	Node *p;
	int cnt = 0;	// cnt가 0이면 찾는 major가 없다는 의미
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
			p = p->next;	// 찾은 후 다음 Node로 넘어감
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
	//추가하려는 List의 데이터 값들을 받아와서 새로운 Node를 만듬.
	Node *p = head;
	Node *q = 0;

	if (isEmpty()) {
		head = temp;
	}
	else if (temp->name < head->name) {
		// name이 char형이므로 ASCII코드값을 비교
		temp->next = head;	// head보다 값이 작으면 
		head = temp;		// 추가하려는 List가 head가 됨
	}
	else{
		p = head;
		while ((p != 0) && p->name < temp->name) {
			q = p;			// 추가하려는 List의 name이 더 작고
			p = p->next;	// head가 0이 아닐 때 까지 검사
		}
		if (p != 0) {		// head가 0이 되면 List의 마지막에 추가
			temp->next = p;
			q->next = temp;
		}
		else {				// 자리를 찾으면 p와 q의 사이에 List 추가
			q->next = temp;
		}
	}
}

void List::displayList() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		while (p) {	// Node p가 0이 아닐때 까지 List 출력
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
	List c;		// return type이 List임
	Node *p;
	Node *q;
	p = a.head;
	q = b.head;
	if (!a.isEmpty() || !b.isEmpty()) {	// 2개의 List가 하나라도 비어있지 않으면
		while (p != 0) {
			c.insertList(p->name, p->Id, p->major, p->grade);
			p = p->next;	// List c에 매개변수로 받은 List a를 insert
		}
		while (q != 0) {
			c.insertList(q->name, q->Id, q->major, q->grade);
			q = q->next;	// List c에 매개변수로 받은 List b를 insert
		}
	}
	else cout << "List is empty." << endl;	// 2개의 List가 모두 비어있으면

	return c;
}

int main() {
	List llA;	//data1를 저장할 List llA 선언
	List llB;	//data2를 저장할 List llB 선언
	List llC;	//data1과 data2를 저장할 List llC 선언

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

	infile.close();	//data1.txt를 닫음

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