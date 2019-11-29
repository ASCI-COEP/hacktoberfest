/*
Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST, because 11 is in left subtree of 10. The task is to complete the function isBST() which takes one argument, root of Binary Tree.

        10
     /     \
   7       39
     \
      11

Input:
The input contains T, denoting number of testcases. For each testcase there will be two lines. The first line contains number of edges. The second line contains two nodes and a character separated by space. The first node denotes data value, second node denotes where it will be assigned to the previous node which will depend on character 'L' or 'R' i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on. The first node of second line is root node. The struct or class Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, the function will be called individually.

Output:
The function should return 1 if BST else return 0.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isBST().

Constraints:
1 <= T <= 100
0 <= Number of edges <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
0

Explanation:
Testcases 1: The given binary tree is not BST, hence the answer is 0.
*/


#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;

	Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool checkkBST(Node* root, int minimum, int maximum);
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     cout << isBST(root) << endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

//Upto this point, all the content was in the question from geeksforgeeks
//This was functional problem so the solution is as follows:

bool isBST(Node* root) {
    static node *prev = NULL;  
      
    // traverse the tree in inorder fashion  
    // and keep track of prev node  
    if (root)  
    {  
        if (!isBST(root->left))  
        return false;  
  
        // Allows only distinct valued nodes  
        if (prev != NULL &&  
            root->data <= prev->data)  
        return false;  
  
        prev = root;  
  
        return isBST(root->right);  
    }  
  
    return true;  
}

