#include <iostream>

using namespace std;

class Tree {
private:
	int max_size;
	int index;
	int *arr;
public:
	Tree(int size) {
		max_size = size;
		arr = new int[size];
		index = 0;
	}
	void insertTree(int value);
	void plusIndex();
	void zeroIndex();
	void printTree();
	int getTree();
};

void Tree::insertTree(int value) {
	arr[index] = value;
	plusIndex();
}

void Tree::plusIndex() {
	index++;
}

void Tree::zeroIndex() {
	index = 0;
}

void Tree::printTree() {
	cout << "( ";
	for (int i = 0; i < max_size; i++) {
		cout << arr[i] << " ";
	}
	cout << ")";
}

int Tree::getTree() {
	int result;
	result = arr[index];
	plusIndex();
	return result;
}

class Heap {
private:
	int max_size;
	int index;
	int *heap;
public:
	Heap(int size) {
		max_size = size;
		heap = new int[max_size];
		index = 0;
	}
	bool isFull();
	bool isEmpty();
	void insertHeap(int element);
	int deleteHeap();
	int levelHeap();
	void printHeap();
};

bool Heap::isFull() {
	if (index == max_size)
		return true;
	else
		return false;
}

bool Heap::isEmpty() {
	if (index == 0)
		return true;
	else
		return false;
}

void Heap::insertHeap(int element) {
	int i;
	if (isFull()) {
		cout << "Heap is Full" << endl;
		return;
	}
	i = ++index;
	while ((i != 1) && (element < heap[i / 2])) {
		heap[i] = heap[i / 2]; // 부모보다 값이 작으면
		i = i / 2;				// 부모를 현재 index로 옮김
	}
	heap[i] = element;		// 조정이 완료되면 element 삽입
}

int Heap::deleteHeap() {
	if (isEmpty()) {
		cout << "Heap is empty" << endl;
		return 0;
	}
	
	int parent, child, temp, item;

	item = heap[1];	// 최상위 부모의 값을 저장
	temp = heap[index--];	//가장 마지막 값을 저장
	parent = 1;	// 부모 인덱스를 의미
	child = 2;		// 자식 인덱스를 의미

	while (child <= index) {
		if ((child < index) && (heap[child] > heap[child + 1]))
			child++;	// 더 작은 자식값을 찾음
		else if (temp <= heap[child])
			break;
		heap[parent] = heap[child];	// 작은 자식값을 부모 위치로 변경
		parent = child;
		child = child * 2;
	}
	heap[parent] = temp; // heap의 마지막 값을 부모자리에 삽입
	return item;
}

int Heap::levelHeap() {
	return int(log2(index)+1);
}

void Heap::printHeap() {
	cout << "( ";
	for (int i = 1; i < index + 1; i++) {
		cout << heap[i] << " ";
	}
	cout << ")" << endl;
}

int main() {
	int size;
	int amountInput;
	int input;

	cout << "Enter Heap size : ";
	cin >> size;

	cout << "Enter amount of input : ";
	cin >> amountInput;

	Heap h1(size);
	Tree tree(amountInput);

	cout << "Enter " << amountInput << " data : ";

	for (int i = 0; i < amountInput; i++) {
		cin >> input;
		tree.insertTree(input);
	}
	
	cout << "Print Tree : ";

	tree.printTree();
	cout << endl;

	tree.zeroIndex();
	// insert하면서 증가된 index를 0으로 초기화시킴

	for (int i = 0; i < amountInput; i++) {
		h1.insertHeap(tree.getTree());
		// tree에서 값을 추출해 heap에 insert
	}

	cout << "Min Heap : ";

	h1.printHeap();

	cout << "-----------------" << endl;
	cout << "| Menu\t\t|" << endl;
	cout << "| 1.Insert\t|" << endl;
	cout << "| 2.Delete\t|" << endl;
	cout << "| 3.Empty-test\t|" << endl;
	cout << "| 4.Full-test\t|" << endl;
	cout << "| 5.Level-test\t|" << endl;
	cout << "| 6.Exit Program|" << endl;
	cout << "-----------------" << endl;

	while (1) {
		cin >> input;
		switch (input) {
		case 1:
			int data;
			cin >> data;
			h1.insertHeap(data);
			cout << "Insert " << data << "\t\t : ";
			h1.printHeap();
			break;
		case 2:
			h1.deleteHeap();
			cout << "Delete\t\t\t : ";
			h1.printHeap();
			break;
		case 3:
			cout << "Empty test\t\t : ";
			if (h1.isEmpty())
				cout << "Heap is Empty" << endl;
			else
				cout << "Heap is not Empty" << endl;
			break;
		case 4:
			cout << "Full test\t\t : ";
			if (h1.isFull())
				cout << "Heap is Full" << endl;
			else
				cout << "Heap is not Full" << endl;
			break;
		case 5:
			cout << "Level test\t\t : ";
			cout << h1.levelHeap() << endl;
			break;
		default :
			cout << "Exit Program";
			return 0;
			break;
		}
	}
}