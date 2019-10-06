/*
Given a binary tree, connect the nodes that are at same level.
Structure of the given Binary Tree node is like following.

struct Node
{
      int data;
      Node* left;
      Node* right;
      Node* nextRight;
}
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

Input Format:
The input contains T, denoting number of testcases. For each testcase there will be third lines. The first line contains number of edges. The second line contains relation between nodes. The second line contains two nodes and a character separated by space. The first node denotes data value, second node denotes where it will be assigned to the previous node which will depend on character 'L' or 'R' i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on. The first node of second line is root node. The struct or class Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print the level order and inorder traversals.

Your Task:
You don't have to take input. Complete the function connect() that takes node as parameter and connects the nodes at same level. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
1 3 2
10 20 30 40 60
40 20 60 10 30

Explanation:
Testcase1: The connected tree is
        3 ------> NULL
     /      \
   1 -----> 2 ------ NULL
Testcase2: The connected tree is
                           10 ----------> NULL
                        /        \
                     20 ------> 30 -------> NULL
                  /       \
               40 ----> 60 ----------> NULL
*/

/* struct Node
{
int data;
Node *left,  *right;
Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    Node(int x){
        data = x;
        left = right = NULL;
        nextRight = NULL;
    }
};
void connect(struct Node *p);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      cout<<node->data<<" ";
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}

//Solution to the problem

void connect(Node *p)
{
	if(!p)
		return ;
	int i = 0, j = 0, k;
	vector < int > arr(102, 0);
	Node* tmp;
	queue < Node* > q;
	arr[0] = 1;
	q.push(p);

	while(!q.empty()) {
		//pop left most and print it and dec a[i] by one
		tmp = q.front();
		q.pop();
		if(!q.empty())
			tmp->nextRight = q.front();
		else tmp->nextRight = NULL;
		arr[i]--;
		if(tmp->left) {
			arr[i + 1]++;
			q.push(tmp->left);
		}
		if(tmp->right) {
			arr[i + 1]++;
			q.push(tmp->right);
		}
		while(arr[i] > 1) {

		// pop until a[i] == 1 and keep pushing children of popped parents at a[i+1]
			if(q.empty())
				break;

			tmp = q.front();
			if(tmp->left) {
				arr[i + 1]++;
				q.push(tmp->left);
			}
			if(tmp->right) {
				arr[i + 1]++;
				q.push(tmp->right);
			}
			q.pop();
			if(!q.empty())
				tmp->nextRight = q.front();
			else tmp->nextRight = NULL;
			arr[i]--;
		}
		//pop right most and print it and push it's children at a[i+1]
		if(!q.empty() && arr[i] == 1) {
			tmp = q.front();
			tmp->nextRight = NULL;
			q.pop();
			arr[i]--;
			if(tmp->left) {
				arr[i + 1]++;
				q.push(tmp->left);
			}
			if(tmp->right) {
				arr[i + 1]++;
				q.push(tmp->right);
			}
		}
		i++;
	}
		return ;
}
