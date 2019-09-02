#include <iostream>

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
	void inorder(Node *ptr);
	void postorder(Node *ptr);
	void preorder(Node *ptr);
	void buildTree(char input);
	void Operand(Node *ptr);
	void Operator(Node *ptr);
	int evalTree(Node *ptr);
	void drawTree(Node *ptr, int level);
	Node* getRoot();
};

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
				temp->prio = 4;
			}
		}

		if (temp->prio == 4) {
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

void Tree::drawTree(Node *ptr, int level) {
	if (ptr != 0) {
		drawTree(ptr->right, level + 1);
		for (int i = 1; i <= level - 1; i++)
			cout << "    ";
		cout << ptr->data;
		if (ptr->left != 0 && ptr->right != 0)
			cout << " < " << endl;
		else if (ptr->right != 0)
			cout << " / " << endl;
		else if (ptr->left != 0)
			cout << "\\" << endl;
		else
			cout << endl;
		drawTree(ptr->left, level + 1);
	}
	
}

int main() {
	Tree tree;
	char input[100] = { 0 };
	
	cout << "Enter expression : ";

	cin >> input;

	int i = 0;
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
	cout << "  Treestructure" << endl;
	cout << endl;
	tree.drawTree(tree.getRoot(), 1);
	cout << endl;

}