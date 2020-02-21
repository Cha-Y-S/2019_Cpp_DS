#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
private:
	Node *root;
public:
	Tree();
	bool isEmpty();
	Node* insertTree(Node *ptr,int value);
	void callInsert(int value);
	Node* deleteTree(Node *ptr,int value);
	void callDelete(int value);
	Node* searchTree(Node *ptr,int value);
	void callSearch(int value);
	void preorder(Node *ptr);
	void callPreorder();
	void inorder(Node *ptr);
	void callInorder();
	void postorder(Node *ptr);
	void callPostorder();
	int leafNode(Node *ptr);
	int callLeafNode();
	void drawTree(Node *ptr,int level);
	void callDrawTree();
	Node* findMax(Node *ptr);
};

Tree::Tree()
{
	root = NULL;
}

bool Tree::isEmpty()
{
	if (root == NULL) return true;
	else return false;
}

Node* Tree::insertTree(Node *ptr,int value)
{
	if (ptr == NULL)
	{
		Node *temp = new Node(value);
		ptr = temp;
	}
	else if (value < ptr->data)
		ptr->left = insertTree(ptr->left, value);
	else
		ptr->right = insertTree(ptr->right, value);
	return ptr;
}

void Tree::callInsert(int value)
{
	root = insertTree(root, value);
}

Node* Tree::deleteTree(Node *ptr,int value)
{
	if (ptr != NULL)
	{
		if (value < ptr->data)
			ptr->left = deleteTree(ptr->left, value);
		else if (value > ptr->data)
			ptr->right = deleteTree(ptr->right, value);
		else if ((ptr->left == NULL) && (ptr->right == NULL))
			ptr = NULL;
		else if (ptr->left == NULL)
		{
			Node *p = ptr;
			ptr = ptr->right;
			delete p;
		}
		else if (ptr->right == NULL)
		{
			Node *p = ptr;
			ptr = ptr->left;
			delete p;
		}
		else
		{
			Node *temp = findMax(ptr->right);
			ptr->data = temp->data;
			ptr->right = deleteTree(ptr->right, ptr->data);
		}
	}
	else
		cout << "Not Found" << endl;
	return ptr;
}

void Tree::callDelete(int value)
{
	root = deleteTree(root, value);
}

Node* Tree::searchTree(Node *ptr, int value)
{
	if (ptr == NULL)
		return NULL;
	else
	{
		if (value == ptr->data) return ptr;
		else if (value < ptr->data)
			ptr = searchTree(ptr->left, value);
		else if (value > ptr->data)
			ptr = searchTree(ptr->right, value);
	}
	return ptr;
}

void Tree::callSearch(int value)
{
	Node *ptr = searchTree(root, value);
	if (ptr)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
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

int Tree::leafNode(Node *ptr)
{
	int count = 0;
	if (ptr == NULL)
		return count;
	else
	{
		if ((ptr->left == NULL) && (ptr->right == NULL))
			count++;
		else
			count = leafNode(ptr->left) + leafNode(ptr->right);
	}

	return count;
}

int Tree::callLeafNode()
{
	return leafNode(root);
}

void Tree::drawTree(Node* ptr,int level)
{
	if ((ptr != NULL) && level <= 7)
	{
		drawTree(ptr->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
			cout << "    ";
		cout << ptr->data;
		if ((ptr->left != NULL) && (ptr->right != NULL))
			cout << " < " << endl;
		else if (ptr->right != NULL)
			cout << " / " << endl;
		else if (ptr->left != NULL)
			cout << " \\ " << endl;
		else
			cout << endl;
		drawTree(ptr->left, level + 1);
	}
}

void Tree::callDrawTree()
{
	drawTree(root, 1);
}

Node* Tree::findMax(Node *ptr)
{
	if (ptr->right == NULL)
		return ptr;
	else
		findMax(ptr->right);
}

int main()
{
	Tree tree;

	cout << "1) Delete : ";
	tree.callDelete(20);

	cout << "2) Traverse : ";
	tree.callInorder();
	cout << endl;

	cout << "3) Insert : ";
	tree.callInsert(30);
	tree.callInsert(40);
	tree.callInsert(20);
	tree.callInsert(10);
	tree.callInsert(50);
	cout << endl;
	tree.callDrawTree();

	cout << "4) Leaf : ";
	cout << tree.callLeafNode() << endl;

	cout << "5) Delete test : " << endl;
	cout << endl;
	cout << " - Single Node Test - > delete 20" << endl;
	tree.callDelete(20);
	tree.callDrawTree();
	cout << endl;
	cout << " - Leaf Noe Test -> delete 50" << endl;
	tree.callDelete(50);
	tree.callDrawTree();
	cout << endl;
	cout << " - Both Side Node Test -> delete 30" << endl;
	tree.callDelete(30);
	tree.callDrawTree();
	cout << endl;

	cout << "6) Search : 30\t";
	tree.callSearch(30);
	cout << "\tSearch : 10\t";
	tree.callSearch(10);
	cout << endl;

	cout << "7) Traverse : " << endl;
	cout << " - inorder : ";
	tree.callInorder();
	cout << "\t - postorder : ";
	tree.callPostorder();
	cout << "\t - preorder : ";
	tree.callPreorder();
	cout << endl;

	return 0;
}