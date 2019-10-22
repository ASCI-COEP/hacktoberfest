#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *left, *right;
};
Node* newNode(int data){
	Node *p = new Node;
	p -> data = data;
	p -> left = p -> right = NULL;
	return p;
}
Node* insert(Node* root, int data){
	if(root == NULL){
		return newNode(data);
	}
	if(root -> data < data)
		root -> right = insert(root -> right, data);
	else if(root -> data > data)
		root -> left = insert(root -> left, data);
	return root;
}
void inorder(Node *root){
	if(root){
		inorder(root -> left);
		cout << root -> data << " ";
		inorder(root -> right);
	}
}
int minbst(Node *root){
	if(root -> left == NULL){
		return root -> data;
	}
	return minbst(root -> left);
}
int maxbst(Node *root){
	if(root -> right == NULL){
		return root -> data;
	}
	return maxbst(root -> right);
}
int main(){
	Node *root = NULL;
	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 2);
	cout << endl;
	inorder(root);
	cout << endl << minbst(root) << endl << maxbst(root) << endl;
	return 0;
}
