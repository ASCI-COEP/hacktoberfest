#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
	bool isend;
	TrieNode *child[26];
};
TrieNode* newNode()
{
	TrieNode *p = new TrieNode;
	p -> isend = false;
	for(int i = 0; i < 26; i++){
		p -> child[i] = NULL;
	}
	return p;
}
void insert(TrieNode *root, string str){
	TrieNode *p = root;
	for(int i = 0; i < str.length(); i++)
	{
		int index = str[i] - 'a';
		if(!p -> child[index])
			p -> child[index] = newNode();
		p = p -> child[index];
	}
	p -> isend = true;
}
bool search(TrieNode *root, string str){
	TrieNode *p = root;
	for(int i = 0; i < str.length(); i++)
	{
		int index = str[i] - 'a';
		if(!p -> child[index])
			return false;
		p = p -> child[index];
	}
	return (p && p -> isend);
}
int main(){
	TrieNode *root = newNode();
	
	insert(root, "word");

	if(search(root, "word"))
		cout << "Word Found\n";
	else
		cout << "Word Not Found\n";

	if(search(root, "wordd"))
		cout << "Word Found\n";
	else
		cout << "Word Not Found\n";
	return 0;
}