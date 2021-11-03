#include <iostream>

using namespace std;

int n;

typedef struct node {
	char data;
	node *leftChild;
	node *rightChild;
}node;

node* nodes;

//전위 순회
void preorder(node *ptr) {
	cout << ptr->data;
	if (ptr->leftChild)
		preorder(ptr->leftChild);
	if (ptr->rightChild)
		preorder(ptr->rightChild);
}

//중위 순회
void inorder(node* ptr) {
	if (ptr->leftChild)
		inorder(ptr->leftChild);
	cout << ptr->data;
	if (ptr->rightChild)
		inorder(ptr->rightChild);
}

//후위 순회
void postorder(node* ptr) {
	if (ptr->leftChild)
		postorder(ptr->leftChild);
	if (ptr->rightChild)
		postorder(ptr->rightChild);
	cout << ptr->data;
}

int main() {
	char a, b, c;
	cin >> n;
	nodes = (node*)malloc(sizeof(node) * n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		int num = a - 'A';
		nodes[num].data = a;
		if (b == '.')
			nodes[num].leftChild = NULL;
		else
			nodes[num].leftChild = &nodes[b - 'A'];
		if (c == '.')
			nodes[num].rightChild = NULL;
		else
			nodes[num].rightChild = &nodes[c - 'A'];
	}
	preorder(&nodes[0]);
	cout << "\n";
	inorder(&nodes[0]);
	cout << "\n";
	postorder(&nodes[0]);
	return 0;
}