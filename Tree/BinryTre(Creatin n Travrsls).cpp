#include "Queue.h"
#include <iostream>

using namespace std;

class tree{
	Tnode *root;
public:
	tree():root(NULL){}
	~tree(){}

	void createTree();
	void PreOrder(Tnode *p);
	void PreOrder(){PreOrder(root);}
	void PostOrder(Tnode* p);
	void PostOrder(){PostOrder(root);}
	void InOrder(Tnode* p);
	void InOrder(){InOrder(root);}
	void LevlOrder(Tnode* p);
	void LevlOrder(){LevlOrder(root);}
};

void tree::createTree(){
	Tnode *p,*t;
	Queue q;
	int x;
	cout<<"giv me the root elem :: ";
	cin>>x;
	root = new Tnode;
	root->d = x;
	root->lchild=root->rchild = NULL;
	q.Enqueue(root);

	while (!q.isEmpty())
	{
		p=q.Dequeue();
		cout<<"giv left child of "<<p->d<<" ,if no giv -1 :: ";
		cin >>x;
		if(x!=-1){
			t =new Tnode;
			t->d = x;
			t->lchild=t->rchild=NULL;
			p->lchild = t;
			q.Enqueue(t);
		}
		cout<<"giv right child,if no giv -1 :: ";
		cin>>x;
		if(x!=-1){
			t =new Tnode;
			t->d = x;
			t->lchild=t->rchild=NULL;
			p->rchild = t;
			q.Enqueue(t);
		}
	}

}

void tree::PreOrder(Tnode*p){
	if(p==nullptr) return;
	else{
		cout<<p->d<<" ";
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void tree::PostOrder(Tnode*p){
	if(p==nullptr) return;
	else{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		cout<<p->d<<" ";
	}
}

void tree::InOrder(Tnode*p){
	if(p==nullptr) return;
	else{
		InOrder(p->lchild);
		cout<<p->d<<" ";
		InOrder(p->rchild);
	}
}

void tree::LevlOrder(Tnode* p){
	Queue q;
	q.Enqueue(p);
	while (!q.isEmpty())
	{
		p=q.Dequeue();
		cout<<p->d<<" ";
		if(p->lchild)
		q.Enqueue(p->lchild);
		if(p->rchild)
		q.Enqueue(p->rchild);
	}
}


int main(){
	tree t;
	t.createTree();cout<<endl;
	t.PreOrder();cout<<endl;
	t.PostOrder();cout<<endl;
	t.InOrder();cout<<endl;
	t.LevlOrder();cout<<endl;
}