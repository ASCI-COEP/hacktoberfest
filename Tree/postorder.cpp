#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node *left, *right; 
}; 



void POSTORDER(struct Node* head) 
{ 
	struct Node* temp = head; 
	unordered_set<Node*> visited; 
	while (temp && visited.find(temp) == visited.end()) { 


		if (temp->left && 
		visited.find(temp->left) == visited.end()) 
			temp = temp->left; 

		else if (temp->right && 
		visited.find(temp->right) == visited.end()) 
			temp = temp->right; 

		else { 
			printf("%d ", temp->data); 
			visited.insert(temp); 
			temp = head; 
		} 
	} 
} 

struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return (node); 
} 

int main() 
{ 
	struct Node* root = newNode(8); 
	root->left = newNode(2); 
	root->right = newNode(9); 
	root->left->left = newNode(3); 
	root->left->right = newNode(5); 
	root->left->right->left = newNode(6); 
	root->left->right->right = newNode(4); 
	root->right->right = newNode(7); 
	root->right->right->left = newNode(13); 
	POSTORDER(root); 
	return 0; 
} 
