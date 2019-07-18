#include<iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int value) {
		data = value;
		left = 0;
		right = 0;
	}
};

class Tree {
private:
	Node *root;
public:
	Tree() { root = 0; }
	void insertNode(int value);
	void deleteNode(int value);
	void searchNode(int value);
	Node* insertTree(Node *ptr, int value);
	Node* searchTree(Node *ptr, int value);
	Node* deleteTree(Node *ptr, int value);
	Node* findMax(Node *ptr);
	void drawTree();
	void drawBSTree(Node *ptr, int level);
	void pre();
	void preOrder(Node *ptr);
	void in();
	void inOrder(Node *ptr);
	void post();
	void postOrder(Node *ptr);
	int callLeaf();
	int leaf(Node *ptr);
};

void Tree::insertNode(int value) { root = insertTree(root, value); }

void Tree::deleteNode(int value) { root = deleteTree(root, value); }

void Tree::searchNode(int value) {
	Node *p = 0;
	p = searchTree(root, value);
	if (p == NULL)
		cout << "Not Found";
	else
		cout << "Found";
}

Node* Tree::insertTree(Node *ptr, int value) {
	if (ptr == NULL) {
		ptr = new Node(value);
	}
	else if (value < ptr->data)
		ptr->left = insertTree(ptr->left, value);
	else if (value > ptr->data)
		ptr->right = insertTree(ptr->right, value);
	return ptr;
}

Node* Tree::searchTree(Node*ptr, int value) {
	if (ptr == NULL)
		return NULL;
	else {
		if (value == ptr->data)
			return ptr;
		else if (value < ptr->data)
			ptr = searchTree(ptr->left, value);
		else if (value > ptr->data)
			ptr = searchTree(ptr->right, value);
	}
	return ptr;
}

Node* Tree::deleteTree(Node *ptr, int value) {
	if (ptr != NULL) {
		Node *p;
		if (value < ptr->data)
			ptr->left = deleteTree(ptr->left, value);
		else if (value > ptr->data)
			ptr->right = deleteTree(ptr->right, value);
		else if ((ptr->left == NULL) && (ptr->right == NULL))
			ptr = NULL;
		else if (ptr->left == NULL) {
			p = ptr;
			ptr = ptr->right;
			delete(p);
		}
		else if (ptr->right == NULL) {
			p = ptr;
			ptr = ptr->left;
			delete(p);
		}
		else {
			Node *temp = findMax(ptr->left);
			ptr->data = temp->data;
			ptr->left = deleteTree(ptr->left, ptr->data);
		}
	}
	else if (root == 0)
		cout << "Tree is empty" << endl;
	else
		cout << "Not Found" << endl;

	return ptr;
}

Node* Tree::findMax(Node *ptr) {
	if (ptr->right == NULL)
		return ptr;
	else
		findMax(ptr->right);
}

void Tree::drawTree() {
	drawBSTree(root, 1);
}

void Tree::drawBSTree(Node *ptr, int level) {
	if (ptr != 0 && level <= 7) {
		drawBSTree(ptr->right, level + 1);
		for (int i = 1; i < level * 2; i++)
			cout << "  ";
		cout << ptr->data;
		if (ptr->left != 0 && ptr->right != 0)
			cout << " < " << endl;
		else if (ptr->right != 0)
			cout << " / " << endl;
		else if (ptr->left != 0)
			cout << " ¡¬ " << endl;
		else
			cout << endl;
		drawBSTree(ptr->left, level + 1);
	}
}

void Tree::pre() { preOrder(root); }

void Tree::preOrder(Node *ptr) {
	if (ptr) {
		cout << ptr->data << " ";
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
	else if (root == 0)
		cout << "Tree is empty" << endl;
}

void Tree::in() { inOrder(root); }

void Tree::inOrder(Node *ptr) {
	if (ptr) {
		inOrder(ptr->left);
		cout << ptr->data << " ";
		inOrder(ptr->right);
	}
	else if (root == 0)
		cout << "Tree is empty" << endl;
}

void Tree::post() { postOrder(root); }

void Tree::postOrder(Node *ptr) {
	if (ptr) {
		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->data << " ";
	}
	else if (root == 0)
		cout << "Tree is empty" << endl;
}

int Tree::callLeaf() {
	int count = leaf(root);
	return count;
}

int Tree::leaf(Node* ptr) {
	int count = 0;
	if (ptr == NULL) {
		return count;
	}
	else {
		if ((ptr->left == NULL) && (ptr->right == NULL))
			count++;
		else
			count = leaf(ptr->left) + leaf(ptr->right);
		return count;
	}
}

int main() {
	Tree tree;

	cout << "1) Delete : ";
	tree.deleteNode(20);

	cout << "2) Traverse : ";
	tree.in();

	cout << "3) Insert : ";
	tree.insertNode(30);
	tree.insertNode(40);
	tree.insertNode(20);
	tree.insertNode(10);
	tree.insertNode(50);
	cout << endl;
	tree.drawTree();

	cout << "4) Leaf : ";
	cout << tree.callLeaf() << endl;
	
	cout << "5) Delete test : " << endl;
	cout << endl;
	cout << " - Single Node Test -> delete 20" << endl;
	tree.deleteNode(20);
	tree.drawTree();
	cout << endl;
	cout << " - Leaf Node Test -> delete 50" << endl;
	tree.deleteNode(50);
	tree.drawTree();
	cout << endl;
	cout << " - Both Side Node Test -> delete 30" << endl;
	tree.deleteNode(30);
	tree.drawTree();
	cout << endl;

	cout << "6) Search : 30\t";
	tree.searchNode(30);
	cout << "\tSearch : 10\t";
	tree.searchNode(10);
	cout << endl;

	cout << "7) Traverse : " << endl;
	cout << " - inorder : ";
	tree.in();
	cout << "\t- postorder : ";
	tree.post();
	cout << "\t- preorder : ";
	tree.pre();
	cout << endl;

}