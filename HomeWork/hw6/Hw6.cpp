#include <iostream>
#include <fstream>

using namespace std;

class ShPath {
private:
	bool *found;	// 정점이 현재 집합 안에 포함 되어있는지 없는지 검사하는 배열
	int *distance;	// 기준정점으로 부터 V[index]까지의 최단 거리가 저장될 배열
	int **cost;	// 주어진 Cost Matrix가 저장될 2차원 배열
	int numOfVertex;	// 정점의 총 갯수
	int MAX;	// cost 배열 내 최댓값(기준 정점에서 도달할 수 없는 경우)
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
		// 기준 정점(V(v))로 부터 직접적으로 거치는 정점들에 대한 가중치 초기화
	}

	found[v] = true; // 기준 정점을 집합에 포함시킴
	distance[v] = 0; // 기준 정점에 대한 가중치 0으로 초기화

	for (i = 0; i < numOfVertex - 1; i++) {
		cout << "  Dist : ";
		printDistance();

		u = chooseNode();		// 다음번으로 거칠 정점 u를 찾는다
		found[u] = true;
		cout << "\t(Selected Node : " << u << ")" << endl;
		for (w = 0; w < numOfVertex; w++) {
			if (!found[w]) {	// 정점 V(w)가 집합에 포함되어있지 않으면
				if (distance[u] + cost[u][w] < distance[w])
					// 현재 정점 u에서부터 다음 정점 w까지 가중치의 합이
					// 이전까지 찾은 기준정점으로부터 정점 w까지의 가중치보다 작으면
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
	printDistance();	// 결과값 도출
	cout << endl;
}

int ShPath::chooseNode() {
	int min, minNode;
	min = MAX;	// cost배열 내 최댓값으로 초기화

	for (int i = 0; i < numOfVertex; i++) {
		if (distance[i] < min && !found[i]) {
			// 기준정점으로 부터 정점 i까지의 값이 min보다 작고
			// i번째 정점이 현재 집합에 포함되있지 않을 때
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