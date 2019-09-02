#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	char ff;
	char ll;
	int cost;
	Node *next;
};

class MST {
private:
	Node *head;
	Node *list;
	int maxSize;
	int numVer;
	int *unionFind;
public:
	MST(int size, int num);
	void initUnionFind();
	void insertST(Node *arr);
	void printList();
	void sortList();
	bool checkContain();
	void kruskal();
	void printKruskal();
	int sumOfCost();
};

MST::MST(int size, int num) {
	head = NULL;
	maxSize = size;
	list = new Node[maxSize];
	numVer = num;
	unionFind = new int[numVer];
}

void MST::initUnionFind() {
	for (int i = 0; i < numVer; i++) {
		unionFind[i] = i;
	}
}

void MST::insertST(Node *arr) {
	for (int i = 0; i < maxSize; i++)
		list[i] = arr[i];
}

void MST::printList() {
	for (int i = 0; i < maxSize; i++) {
		cout << list[i].ff << " " << list[i].cost << " " << list[i].ll << endl;
	}
}

void MST::sortList() {
	for (int i = 0; i < maxSize - 1; i++) {
		for (int j = 0; j < maxSize - 1; j++) {
			if (list[j].cost > list[j + 1].cost) {
				Node temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

bool MST::checkContain() {
	Node *p = head;
	int cnt = 0;
	while (p != NULL) {
		p = p->next;
		cnt++;
	}
	if (cnt == numVer - 1)
		return true;
	else
		return false;
}

void MST::kruskal() {
	sortList();
	initUnionFind();
	int i = 0;
	/*cout << "unionFind " << i << " : ";
	for (int j = 0; j < numVer; j++) {
		cout << unionFind[j] << " ";
	}
	cout << endl;*/
	while (!checkContain()) {
		if (unionFind[(list[i].ff) - 65] < unionFind[(list[i].ll) - 65]) {
			int find = unionFind[list[i].ll - 65];
			for (int j = 0; j < maxSize; j++) {
				if (unionFind[j] == find)
					unionFind[j] = unionFind[list[i].ff - 65];
			}
			Node *temp = new Node();
			temp->ff = list[i].ff;
			temp->cost = list[i].cost;
			temp->ll = list[i].ll;
			temp->next = NULL;
			if (head == NULL)
				head = temp;
			else {
				Node *p = head;
				while (p->next != NULL)
					p = p->next;
				p->next = temp;
			}
			/*cout << "unionFind " << i << " : ";
			for (int j = 0; j < numVer; j++) {
				cout << unionFind[j] << " ";
			}
			cout << endl;*/
			i++;
		}
		else if (unionFind[list[i].ff - 65] > unionFind[list[i].ll - 65]) {
			int find = unionFind[list[i].ll];
			for (int j = 0; j < maxSize; j++) {
				if (unionFind[j] == find)
					unionFind[j] = unionFind[list[i].ll - 65];
			}
			Node *temp = new Node();
			temp->ff = list[i].ff;
			temp->cost = list[i].cost;
			temp->ll = list[i].ll;
			temp->next = NULL;
			if (head == NULL)
				head = temp;
			else {
				Node *p = head;
				while (p->next != NULL)
					p = p->next;
				p->next = temp;
			}
			i++;
			/*cout << "unionFind " << i << " : ";
			for (int j = 0; j < numVer; j++) {
				cout << unionFind[j] << " ";
			}
			cout << endl;*/
		}
		else
			i++;
	}
}

void MST::printKruskal() {
	/*cout << "unionFind " << " : ";
	for (int j = 0; j < numVer; j++) {
		cout << unionFind[j] << " ";
	}
	cout << endl;*/
	Node *p = head;
	if (p == NULL)
		cout << "MST is Empty" << endl;
	else {
		int i = 0;
		while (p != NULL) {
			cout << "Edge " << i + 1 << " : ";
			cout << p->ff << " ";
			cout << p->cost << " ";
			cout << p->ll << endl;

			p = p->next;
			i++;
		}
	}
}

int MST::sumOfCost() {
	int sum = 0;
	Node *p = head;
	while (p != NULL) {
		sum += p->cost;
		p = p->next;
	}
	return sum;
}

int main() {
	ifstream infile;
	infile.open("KData.txt", ios::in);
	int numOfEdge, numOfVertex;
	int tCost;

	infile >> numOfEdge >> numOfVertex;

	MST mst(numOfEdge, numOfVertex);
	Node *arr = new Node[numOfEdge];

	for (int i = 0; i < numOfEdge; i++) {
		infile >> arr[i].ff >> arr[i].cost >> arr[i].ll;
	}
	mst.insertST(arr);

	cout << "Original Data :" << endl;
	mst.printList();
	cout << endl;

	mst.kruskal();

	cout << "Sorted Data :" << endl;
	mst.printList();
	cout << endl;

	cout << "Kruskal's MST :" << endl;
	mst.printKruskal();
	cout << endl;

	tCost = mst.sumOfCost();

	cout << "Total Cost : " << tCost << endl;
}