#include<bits/stdc++.h>
using namespace std;
#define MAX 50 
class Node{
	public:
	char data;
	unsigned isEndOfString : 1;
	 Node *left, *eq, *right;	
};
Node* newNode(char data){
	Node* temp = new Node;
	temp -> data = data;
	temp -> isEndOfString = 0;
	temp -> left = temp -> eq = temp -> right = NULL;		
	return temp;
}	
void insert(Node** root, char *word){
	if(!(*root))
		*root = newNode(*word);
	if((*word) < (*root) -> data)
		insert(&( (*root) -> left ), word);
	else if( (*word) > (*root) -> data)
		insert( &( (*root) -> right ), word);
	else
	{
		if(*(word + 1))
			insert(&((*root) -> eq), word + 1);
		else
			(*root) -> isEndOfString = 1;
	}
}
void traverseTSTUtil(Node* root, char* buffer, int depth) 
{ 
	if (root) 
	{ 
		// First traverse the left subtree 
		traverseTSTUtil(root->left, buffer, depth); 

		// Store the character of this node 
		buffer[depth] = root->data; 
		if (root->isEndOfString) 
		{ 
			buffer[depth+1] = '\0'; 
			printf( "%s\n", buffer); 
		} 

		// Traverse the subtree using equal pointer (middle subtree) 
		traverseTSTUtil(root->eq, buffer, depth + 1); 

		traverseTSTUtil(root->right, buffer, depth); 
	} 
}
void traverseTST(Node* root){
	char buffer[MAX];
	traverseTSTUtil(root, buffer, 0);
}
void autotraverseTSTUtil(Node* root, char* buffer, int depth, char* word) 
{ 
	if (root) 
	{ 
		autotraverseTSTUtil(root->left, buffer, depth, word); 
		buffer[depth] = root->data; 
		if (root->isEndOfString) 
		{ 
			buffer[depth+1] = '\0'; 
			printf( "%s%s\n", word, buffer); 
		} 
		autotraverseTSTUtil(root->eq, buffer, depth + 1, word); 
		autotraverseTSTUtil(root->right, buffer, depth, word); 
	} 
} 
void autotraverseTST(Node* root, char* word) 
{ 
	char buffer[MAX]; 
	autotraverseTSTUtil(root, buffer, 0, word); 
} 
int searchTST(Node *root, char *word) 
{ 
	if (!root) 
		return 0; 
	if (*word < (root)->data) 
		return searchTST(root->left, word); 
	else if (*word > (root)->data) 
		return searchTST(root->right, word); 
	else
	{ 
		if (*(word+1) == '\0')
			return root->isEndOfString; 
		return searchTST(root->eq, word+1); 
	} 
} 
int autocompleteTST(Node *root, char *word, char* fullword) 
{ 
	if(!root)
		return 0;
	if(*word < (root) -> data)
		return autocompleteTST(root -> left, word, fullword);
	else if(*word > (root) -> data)
		return autocompleteTST(root -> right, word, fullword);
	else{
		if(*(word + 1) == '\0')
		{
			autotraverseTST(root -> eq, fullword);
		}
		return autocompleteTST(root -> eq, word + 1, fullword);
	}
}

int main() 
{ 
	Node *root = NULL; 

	insert(&root, "cat"); 
	insert(&root, "cats"); 
	insert(&root, "up"); 
	insert(&root, "bug"); 
	insert(&root, "laugh");
	insert(&root, "laughed");
	insert(&root, "laughing");
	insert(&root, "laugher");

/*
	insert(root, "cat"); 
	insert(root, "cats"); 
	insert(root, "up"); 
	insert(root, "bug"); 
	insert(root, "laugh");
	insert(root, "laughed");
	insert(root, "laughing");
	insert(root, "laugher");
/*
	printf("Following is traversal of ternary search tree\n"); 
	traverseTST(root); 

	printf("\nFollowing are search results for cats, bu and cat respectively\n"); 
	searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n"); 
	searchTST(root, "bu")? printf("Found\n"): printf("Not Found\n"); 
	searchTST(root, "cat")? printf("Found\n"): printf("Not Found\n"); 
*/
	char *s = "lau";
	printf("\nautocomplete for %s is \n", s);
	autocompleteTST(root, s, "lau");
	return 0; 
} 
