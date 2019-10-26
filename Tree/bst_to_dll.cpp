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
void fun(Node* root, Node** head_ref, Node** prev){
	if(root){
		fun(root -> left, head_ref, prev);
		if(!(*head_ref)){
			*head_ref = root;
		}
		if((*prev)){
			(*prev) -> right = root;
		}
		root -> left = *prev;
		(*prev) = root;
		fun(root -> right, head_ref, prev);
	}
}
void print_dll(Node* head){
	while(head){
		cout << head -> data << " ";
		head = head -> right;
	}
	cout << endl;
}
int main(){
	Node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	root -> left -> right -> right = newNode(8);
	root -> left -> left -> right = newNode(9);
	Node *head = NULL;
	Node *prev = NULL;
	fun(root, &head, &prev);
	// print created doubly linked list	
	print_dll(head);
	return 0;
}
