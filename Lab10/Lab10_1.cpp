#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 9;

bool visited[MAX];
bool visited1[MAX];


int weightgraph[6][6] = { 0, 5, 100, 12 ,100, 100,
					5, 0, 6, 10, 24, 100,
					100, 6, 0, 17, 100, 30,
					12, 10, 17, 0, 20, 100,
					100, 24, 100, 20, 0, 13,
					100, 100, 30, 100, 13, 0 };

class Node {
private:
	int vertex;
	int cost;
	Node* next;
	Node* prev;
public:
	Node() {
	}
	int getvertex() {
		return this->vertex;
	}
	int getcost() {
		return this->cost;
	}
	void setcost(int cost) {
		this->cost = cost;
	}
	void setvertex(int vertex) {
		this->vertex = vertex;
	}
	Node* getprev() {
		return this->prev;
	}
	void setprev(Node* prev) {
		this->prev = prev;
	}
	Node(int num, int cost) :vertex(num), cost(cost), next(NULL) {}
	friend class Graph;
};

class Graph {
private:
	Node* graph[MAX];
	Node* front;
	Node* rear;
public:
	Graph() :front(NULL), rear(NULL) {}
	void Graph_graph_init();
	void Graph_visited_init();
	void Graph_insert(int from, int to, int cost);
	void Graph_display();
	Node* method1(int start);
	Node* method2(int start);
};

void Graph::Graph_graph_init()
{
	for (int i = 0; i < MAX; i++)
		graph[i] = NULL;
}

void Graph::Graph_visited_init()
{
	for (int i = 0; i < MAX; i++)
		visited[i] = 0;
	for (int i = 0; i < MAX; i++)
		visited1[i] = 0;
}

void Graph::Graph_insert(int from, int to, int cost)
{
	if (graph[from] == NULL)
	{
		Node* temp_1 = new Node(from, cost);
		graph[from] = temp_1;
	}
	if (graph[to] == NULL)
	{
		Node* temp_2 = new Node(to, cost);
		graph[to] = temp_2;
	}


	Node* p = graph[from];
	Node* temp1 = new Node(to, cost);
	while (p->next != NULL)
		p = p->next;
	p->next = temp1;

	p = graph[to];
	Node* temp2 = new Node(from, cost);
	while (p->next != NULL)
		p = p->next;
	p->next = temp2;
}

void Graph::Graph_display()
{
	for (int i = 0; i < MAX; i++)
	{
		if (graph[i] != NULL) {
			Node* p = graph[i];
			while (p != NULL) {
				cout << p->vertex << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
}

Node* Graph::method1(int start) {

	Node* p;
	Node* min_v = new Node();
	min_v->cost = 999999;
	min_v->vertex = -1;
	visited[start] = 1;

	for (p = graph[start]; p; p = p->next) {
		if (!visited[p->vertex])
		{
			if (min_v->cost > p->cost)
			{
				min_v->cost = p->cost;
				min_v->vertex = p->vertex;
			}
		}
	}

	return min_v;
}

Node* Graph::method2(int start) {
	Node* p1;
	Node* min_v1 = new Node();
	min_v1->cost = 999999;
	min_v1->vertex = -1;
	visited1[start] = 1;

	for (p1 = graph[start]; p1; p1 = p1->next) {
		if (!visited1[p1->vertex])
		{
			if (min_v1->cost > p1->cost)
			{
				min_v1->prev = graph[start];
				min_v1->cost = p1->cost;
				min_v1->vertex = p1->vertex;
			}
		}
	}

	return min_v1;
}

int main(void)
{
	Graph g;
	g.Graph_graph_init();
	g.Graph_visited_init();
	ifstream inStream;
	inStream.open("PData.txt",ios::in);
	char from, to;
	int cost;
	int V = 6;
	int find;

	for (int i = 0; i < MAX; i++)
	{
		inStream >> from >> cost >> to;
		from = from - 65;
		to = to - 65;
		g.Graph_insert(from, to, cost);
	}

	cout << "1) Weighted Graph" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << weightgraph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	
	cout << "Start from : ";
	cin >> find;
	cout << endl;

	cout << "2)Minimal Spanning Tree (Greedy algorithm)" << endl;

	int find1 = find;
	int count = 0;
	int sum = 0;
	int sum1 = 0;
	while (count < V - 1)
	{
		Node* min = new Node();
		min = g.method1(find);
		char minc = min->getvertex() + 65;
		char findc = find + 65;
		if (visited[find] != visited[min->getvertex()]) {
			visited[find] = 1;
			visited[min->getvertex()] = 1;
			count++;
			sum += min->getcost();
			cout << findc << "," << minc << "   ";
		}
		else
			continue;
		find = min->getvertex();
	}
	cout << endl;


	cout << "Weight : " << sum << endl;
	cout << endl;

	count = 0;

	cout << "3)Revised Prim's Algorithm" << endl;

	while (count < V - 1) {

		Node* min1 = new Node();
		min1 = g.method2(find1);
		char find1c = find1 + 65;
		char min1c = min1->getvertex() + 65;
		if (visited1[find1] != visited1[min1->getvertex()]) {
			visited1[find1] = 1;
			visited1[min1->getvertex()] = 1;
			count++;
			sum1 += min1->getcost();
			cout << find1c << "," << min1c << "   ";
		}
		else
			continue;

		while (count < V - 1) {

			Node* small = new Node();
			small->setcost(999);
			small->setvertex(-1);

			for (int i = 0; i < V; ++i) {
				if (visited1[i] == 1) {
					if (small->getcost() > g.method2(i)->getcost()) {
						small->setcost(g.method2(i)->getcost());
						small->setvertex(g.method2(i)->getvertex());
						small->setprev(g.method2(i)->getprev());
					}
				}
			}
			visited1[small->getprev()->getvertex()] = 1;
			visited1[small->getvertex()] = 1;
			char smallc = small->getprev()->getvertex() + 65;
			char smallcg = small->getvertex() + 65;
			cout << smallc << "," << smallcg << "   ";
			count++;
			sum1 += small->getcost();
		}
		cout << endl;
		cout << "Weight : " << sum1 << endl;
	}

	return 0;

}