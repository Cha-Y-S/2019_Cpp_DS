#include <iostream>
#include <fstream>

using namespace std;

class ShPath {
private:
	bool *found;	// ������ ���� ���� �ȿ� ���� �Ǿ��ִ��� ������ �˻��ϴ� �迭
	int *distance;	// ������������ ���� V[index]������ �ִ� �Ÿ��� ����� �迭
	int **cost;	// �־��� Cost Matrix�� ����� 2���� �迭
	int numOfVertex;	// ������ �� ����
	int MAX;	// cost �迭 �� �ִ�(���� �������� ������ �� ���� ���)
public:
	ShPath() {
		found = new bool[100];
		distance = new int[100];
	}
	void initCostMatrix1();	// testcase 1
	void initCostMatrix2();	// testcase 2
	void printCostMatrix();
	void printDistance();
	void shortestPath1(int v);	// testcase 1
	void shortestPath2(int v);	// testcase 2
	int chooseNode();
};

void ShPath::initCostMatrix1() {
	ifstream infile;
	infile.open("data1.txt", ios::in);

	infile >> numOfVertex;

	cost = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		cost[i] = new int[numOfVertex];
		for (int j = 0; j < numOfVertex; j++) {
			infile >> cost[i][j];
		}
	}
	MAX = 100;
	infile.close();
}

void ShPath::initCostMatrix2() {
	ifstream infile;
	infile.open("data2.txt", ios::in);

	infile >> numOfVertex;

	cost = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		cost[i] = new int[numOfVertex];
		for (int j = 0; j < numOfVertex; j++) {
			infile >> cost[i][j];
		}
	}
	MAX = 10000;
	infile.close();
}

void ShPath::printCostMatrix() {
	cout << "\t";
	for (int i = 0; i < numOfVertex; i++) {
		cout << "V" << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < numOfVertex; i++) {
		cout << "V" << i << "\t";
		for (int j = 0; j < numOfVertex; j++) {
			cout << cost[i][j] << "\t";
		}
		cout << endl;
	}
}

void ShPath::printDistance() {
	for (int i = 0; i < numOfVertex; i++) {
		cout << distance[i] << " ";
	}
}

void ShPath::shortestPath1(int v) {
	int i, u, w;
	for (i = 0; i < numOfVertex; i++) {
		found[i] = false;
		distance[i] = cost[v][i];
		// ���� ����(V(v))�� ���� ���������� ��ġ�� �����鿡 ���� ����ġ �ʱ�ȭ
	}

	found[v] = true; // ���� ������ ���տ� ���Խ�Ŵ
	distance[v] = 0; // ���� ������ ���� ����ġ 0���� �ʱ�ȭ

	for (i = 0; i < numOfVertex - 1; i++) {
		cout << "  Dist : ";
		printDistance();

		u = chooseNode();		// ���������� ��ĥ ���� u�� ã�´�
		found[u] = true;
		cout << "\t(Selected Node : " << u << ")" << endl;
		for (w = 0; w < numOfVertex; w++) {
			if (!found[w]) {	// ���� V(w)�� ���տ� ���ԵǾ����� ������
				if (distance[u] + cost[u][w] < distance[w])
					// ���� ���� u�������� ���� ���� w���� ����ġ�� ����
					// �������� ã�� �����������κ��� ���� w������ ����ġ���� ������
					distance[w] = distance[u] + cost[u][w];
			}
		}
	}
}

void ShPath::shortestPath2(int v) {
	int i, u, w;
	for (i = 0; i < numOfVertex; i++) {
		found[i] = false;
		distance[i] = cost[v][i];
	}

	found[v] = true;
	distance[v] = 0;
	cout << "Beginning   Dist : ";
	for (i = 0; i < numOfVertex - 1; i++) {

		printDistance();
		cout << endl;

		u = chooseNode();
		found[u] = true;

		for (w = 0; w < numOfVertex; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
			}
		}
		cout << "Select(" << u << ")-> Dist : ";
	}
	printDistance();	// ����� ����
	cout << endl;
}

int ShPath::chooseNode() {
	int min, minNode;
	min = MAX;	// cost�迭 �� �ִ����� �ʱ�ȭ

	for (int i = 0; i < numOfVertex; i++) {
		if (distance[i] < min && !found[i]) {
			// ������������ ���� ���� i������ ���� min���� �۰�
			// i��° ������ ���� ���տ� ���Ե����� ���� ��
			min = distance[i];
			minNode = i;
		}
	}
	return minNode;
}

int main() {
	ShPath sh, sh1;
	cout << "Test case 1" << endl;
	sh.initCostMatrix1();
	cout << "1)Print Cost Matrix" << endl;
	sh.printCostMatrix();
	cout << "\n2)Shortest Path" << endl;
	sh.shortestPath1(0);

	cout << endl;

	cout << "Test case 2" << endl;
	sh1.initCostMatrix2();
	cout << "1)Print Cost Matrix" << endl;
	sh1.printCostMatrix();
	cout << "\n2)Shortest Path" << endl;
	sh1.shortestPath2(4);
}