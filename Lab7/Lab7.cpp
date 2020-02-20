#include <iostream>
#include <fstream>

using namespace std;

char prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node
{
	char data;
	int prio;
	Node *left;
	Node *right;
	Node(char data)
	{
		this->data = data;
		prio = 4;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
public:
	Tree();
	~Tree();
	bool isDigit(int value);
	bool isEmpty();
	void buildTree(char value);
	void insertOperand(Node *ptr);
	void insertOperator(Node *ptr);
	void inorder(Node *ptr);
	void callInorder();
	void preorder(Node *ptr);
	void callPreorder();
	void postorder(Node *ptr);
	void callPostorder();
	void expression(Node *ptr);
	void callExpression();
	int evaluation(Node *ptr);
	int callEvaluation();
private:
	Node *root;
};

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	delete root;
}

bool Tree::isDigit(int value)
{
	if (value == 4)
		return true;
	else
		return false;
}

bool Tree::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

void Tree::buildTree(char value)
{
	Node *temp = new Node(value);

	for (int i = 0; i < 4; i++)
	{
		if (temp->data == prec[i][0])
		{
			temp->prio = prec[i][1] - '0';
			break;
		}
		else
			temp->prio = 4;
	}
	
	if (isDigit(temp->prio))
		insertOperand(temp);
	else
		insertOperator(temp);
}

void Tree::insertOperand(Node *ptr)
{
	if (isEmpty())
		root = ptr;
	else
	{
		Node *p = root;
		while (p->right != NULL)
			p = p->right;
		p->right = ptr;
	}
}

void Tree::insertOperator(Node *ptr)
{
	if (root->prio >= ptr->prio)
	{
		ptr->left = root;
		root = ptr;
	}
	else
	{
		ptr->left = root->right;
		root->right = ptr;
	}
}

void Tree::inorder(Node *ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		cout << ptr->data << " ";
		inorder(ptr->right);
	}
}

void Tree::callInorder()
{
	inorder(root);
}

void Tree::preorder(Node *ptr)
{
	if (ptr)
	{
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void Tree::callPreorder()
{
	preorder(root);
}

void Tree::postorder(Node *ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << " ";
	}
}

void Tree::callPostorder()
{
	postorder(root);
}

void Tree::expression(Node *ptr)
{
	if (ptr)
	{
		if (!isDigit(ptr->prio))
			cout << "( ";

		expression(ptr->left);
		cout << ptr->data << " ";
		expression(ptr->right);

		if (!isDigit(ptr->prio))
			cout << ") ";
	}
}

void Tree::callExpression()
{
	expression(root);
}

int Tree::evaluation(Node *ptr)
{
	int value, left, right;
	if (ptr)
	{
		if (isDigit(ptr->prio))
			value = ptr->data - '0';
		else
		{
			left = evaluation(ptr->left);
			right = evaluation(ptr->right);
			switch (ptr->data)
			{
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
	else
	{
		cout << "Tree is empty" << endl;
		return 0;
	}
	return value;
}

int Tree::callEvaluation()
{
	return evaluation(root);
}

int main()
{
	Tree tree;
	ifstream input;
	input.open("data.txt", ios::in);
	cout << "Math Expression : ";
	while (true)
	{
		char value;
		input >> value;
		if (input.eof())
			break;
		tree.buildTree(value);
		cout << value << " ";
		// cout << "input : " << input.eof() << endl;
	}

	cout << endl;

	cout << "preorder : ";
	tree.callPreorder();
	cout << endl;

	cout << "inorder : ";
	tree.callInorder();
	cout << endl;

	cout << "postorder : ";
	tree.callPostorder();
	cout << endl;

	cout << "Expression : ";
	tree.callExpression();
	cout << endl;
	
	cout << "Evaluation : ";
	cout << tree.callEvaluation();
	cout << endl;

	return 0;
}