#include <iostream>
#include <fstream>

using namespace std;

const char const prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node {
	char data;
	int prio;
	Node* left;
	Node* right;
	Node(char value) {
		data = value;
		prio = 4;
		left = 0;
		right = 0;
	}
};

class Tree {
private:
	Node *root;
public:
	Tree() {
		root = 0;
	}
	bool isEmpty();
	bool isdigit(int value);
	void inorder(Node *ptr);
	void postorder(Node *ptr);
	void preorder(Node *ptr);
	void Operand(Node *ptr);
	void Operator(Node *ptr);
	void buildTree(char input);
	int evalTree(Node *ptr);
	void parentheses(Node *ptr);
	Node* getRoot();
};

bool Tree::isdigit(int value) {
	if (value == 5)
		return true;
	else
		return false;
}

bool Tree::isEmpty() {
	if (root == 0)
		return true;
	else
		return false;
}

void Tree::inorder(Node *ptr) {
	{
		if (ptr) {
			inorder(ptr->left);
			cout << ptr->data << " ";
			inorder(ptr->right);
		}
	}
}

void Tree::postorder(Node *ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << " ";

	}
}

void Tree::preorder(Node *ptr) {
	if (ptr) {
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void Tree::buildTree(char input) {
	while (input != NULL) {
		Node *temp = new Node(input);

		for (int i = 0; i < 4; i++) {
			if (temp->data == prec[i][0]) {
				temp->prio = prec[i][1] - '0';
				break;
			}
			else {
				temp->prio = 5;
			}
		}

		if (temp->prio == 5) {
			Operand(temp);
			break;
		}
		else {
			Operator(temp);
			break;
		}
	}
}

void Tree::Operand(Node *ptr) {
	Node *p;
	if (isEmpty()) {
		root = ptr;
	}
	else {
		p = root;
		while (p->right != NULL) {
			p = p->right;
		}
		p->right = ptr;
	}
}

void Tree::Operator(Node *ptr) {
	if (root->prio >= ptr->prio) {
		ptr->left = root;
		root = ptr;
	}
	else {
		ptr->left = root->right;
		root->right = ptr;
	}
}

Node* Tree::getRoot() {
	return root;
}

int Tree::evalTree(Node *ptr) {
	int value, left, right;
	if (!isEmpty()) {
		if (ptr->left == 0 && ptr->right == 0)
			value = ptr->data - '0';
		else {
			left = evalTree(ptr->left);
			right = evalTree(ptr->right);
			switch (ptr->data) {
			case '+':
				value = left + right;
				break;
			case '-':
				value = left - right;
				break;
			case '*':
				value = left * right;
				break;
			case '/':
				value = left / right;
				break;
			}
		}
	}
	else {
		cout << "Empty Tree" << endl;
		return 0;
	}

	return value;
}

void Tree::parentheses(Node *ptr) {
	if (ptr != NULL) {
		if (!isdigit(ptr->prio))
			cout << "( ";
		parentheses(ptr->left);
		cout << ptr->data<< " ";
		parentheses(ptr->right);
		if (!isdigit(ptr->prio))
			cout << ") ";
	}
}

int main() {
	ifstream infile;
	infile.open("lab7.txt", ios::in);
	char input[100];
	for (int j = 0; j < 3; j++) {
		
		
		while (infile.getline(input, 100)) {
			Tree tree;
			int i = 0;
			cout << "Math expression : ";
			cout << input;
			while (input[i] != 0) {
				tree.buildTree(input[i]);
				i++;
			}

			cout << endl;
			cout << "  Inorder : ";
			tree.inorder(tree.getRoot());
			cout << endl;

			cout << endl;
			cout << "  Postorder : ";
			tree.postorder(tree.getRoot());
			cout << endl;

			cout << endl;
			cout << "  Preorder : ";
			tree.preorder(tree.getRoot());
			cout << endl;

			cout << endl;
			cout << "  Evaluation : ";
			cout << tree.evalTree(tree.getRoot()) << endl;

			cout << endl;
			cout << "  Parentheses : ";
			tree.parentheses(tree.getRoot());
			cout << endl;
		}
	}
}