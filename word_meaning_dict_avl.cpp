//AVL Tree implementation for a dictionary
#include<bits/stdc++.h> 
using namespace std; 
class Node{
public:
	string data, meaning; 
	int height;
	Node *left, *right;
};
int height(Node *n)
{
	if(n == NULL)
		return 0;
	return n -> height;
}
#define max(a, b) ((a > b) ? a : b)
Node* newNode(string data, string meaning) 
{ 
	Node* node = new Node(); 
	node->data = data; 
	node -> meaning = meaning;
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
	return node; 
} 

Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 
	x->right = y; 
	y->left = T2; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 
	return x; 
} 
Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 
	y->left = x; 
	x->right = T2; 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	return y; 
} 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 
Node* insert(Node* node, string data, string meaning) 
{ 
	if (node == NULL) 
		return(newNode(data, meaning)); 
	if (data < node->data) 
		node->left = insert(node->left, data, meaning); 
	else if (data > node->data) 
		node->right = insert(node->right, data, meaning); 
	else
		return newNode(data, meaning); 
	node->height = 1 + max(height(node->left), 
						height(node->right)); 
	int balance = getBalance(node); 
	if (balance > 1 && data < node->left->data) 
		return rightRotate(node); 
	if (balance < -1 && data > node->right->data) 
		return leftRotate(node); 
	if (balance > 1 && data > node->left->data) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	if (balance < -1 && data < node->right->data) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
}
void inOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		inOrder(root->left); 
		cout << root -> data << endl;
		//cout << "word " << root->data << "    meaning " << root -> meaning << endl; 
		inOrder(root->right); 
	} 
} 
int main() 
{ 
	Node *root = NULL; 
					  //word   meaning		
	root = insert(root, "as", "kash");
	root = insert(root, "pqp", "oiash"); 
	root = insert(root, "osfj", "kuasghdk"); 
	root = insert(root, "oi", "kuashdk"); 
	root = insert(root, "oihaf", "uashdk"); 
	root = insert(root, "isf", "kashd"); 
	inOrder(root); 	
	return 0; 
} 
