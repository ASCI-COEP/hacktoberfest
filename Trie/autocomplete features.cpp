// problem statement is in autocomplete features.pdf

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node* child[26];
    bool eow;
};
class trie{
    struct node*root;
    public:
    trie();
    node* createnode(char s);
    void insertdata(node*t,string s);
    void insert(string s);
    void autocomplete(string s);
    void printsubtree(node*t,string s);
};
trie::trie()
{
    for(int i=0;i<26;i++)
    {
        root->child[i]=NULL; 
    }
    root->eow=false;
}
node* trie::createnode(char s)
{
    struct node* t= new struct node;
    t->data=s;
    for(int i=0;i<26;i++)
    {
        t->child[i]=NULL; 
    }
    t->eow=false;
   return t;
}
void trie::insertdata(node*t,string s)
{
    int pos;
    for(int i=0;i<s.length();i++)
    {
        pos=s.at(i)-'a';
        if(t->child[pos]==NULL)
        {
            t->child[pos]=createnode(s[i]);
        }
        t=t->child[pos];
    }
    t->eow=true;
}
void trie::insert(string s)
{
     struct node*t=root;
     insertdata(t,s);
}
void trie::printsubtree(node*t,string s)
{
    if(t->eow==true)
        cout<<s<<endl;
    for(int i=0;i<26;i++)
    {
        if(t->child[i]!=NULL)
        {
            s.push_back(i+'a');
            printsubtree(t->child[i],s);
            s.pop_back();
        }
    }
}
void trie::autocomplete(string s)
{
    struct node*t=root;
    int flag=0;
    int pos;
    for(int i=0;i<s.length();i++)
    {
        pos=s.at(i)-'a';
        if(t->child[pos]!=NULL)
        {
            t=t->child[pos];
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printsubtree(t,s);
        cout<<endl;
    }  
    else{
        cout<<"not found"<<endl;
        cout<<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    cin>>n>>q;
    trie t;
    while(n--)
    {
        string s;
        cin>>s;
        t.insert(s);
    }
    while(q--)
    {
        string c;
        cin>>c;
        t.autocomplete(c);
    } 
    return 0;
}
