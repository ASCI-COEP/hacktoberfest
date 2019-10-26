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
void leftboundary(Node *root, vector<int>& left){
	if(root){
		left.push_back(root -> data);
		if(root -> left){
			leftboundary(root -> left, left);
		}
		else if(root -> right){
			leftboundary(root -> right, left);
		}
	}
}
void rightboundary(Node *root, vector<int>& right){
	if(root){
		right.push_back(root -> data);
		if(root -> right){
			rightboundary(root -> right, right);
		}
		else if(root -> right){
			rightboundary(root -> left, right);
		}
	}
}
void bottomlevel(Node *root, vector<int>& bottom){
	if(!root)
		return;
	if(root -> left == NULL && root -> right == NULL){
		bottom.push_back(root -> data);
		return;
	}
	bottomlevel(root -> left, bottom);
	bottomlevel(root -> right, bottom);
}
void boundary(Node *root){
	vector<int> left;
	leftboundary(root, left);
	vector<int> right;
	rightboundary(root, right);
	reverse(right.begin(), right.end());
	
	vector<int> bottom;
	bottomlevel(root, bottom);

	for(auto x : left){
		cout << x << " " ;
	}
	bottom.erase(bottom.begin());
	bottom.pop_back();
	for(auto x : bottom){
		cout << x << " ";
	}
	right.pop_back();
	for(auto x : right){
		cout << x << " ";
	}
}
int main(){
	Node *root = NULL;
	root = insert(root, 7);
	root = insert(root, 3);
	root = insert(root, 11);
	root = insert(root, 1);
	root = insert(root, 5);
	root = insert(root, 0);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 1);
	root = insert(root, 9);
	root = insert(root, 13);
	root = insert(root, 12);
	root = insert(root, 14);
	root = insert(root, 8);
	root = insert(root, 10);
	/*
		Generated BST is 
						7
	
				3		       11
	
			1	  	5 	   9       13
	
		0     2   4   6   8  10  12   14

		Boundary traversal will be   7 3 1 0 2 4 6 8 10 12 14 13 11 
	*/
	cout << "Boundary traversal of BST is \n";
	boundary(root);
	cout << endl;
	return 0;
}
