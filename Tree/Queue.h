#include <iostream>

using namespace std;

struct Tnode{
	Tnode *lchild;
	int d;
	Tnode *rchild;
};

struct node{
	Tnode* data;
	node* next;
};

class Queue{
private:
	node *front,*rear;
public:
	Queue():front(NULL),rear(NULL){}
	~Queue(){}

	void Display();
	void Enqueue(Tnode* x);
	bool isEmpty();
	Tnode* Dequeue();
};

bool Queue::isEmpty(){
	if(front == NULL) return true;
	return false;
}

void Queue::Enqueue(Tnode* x){
	node *t=new node;
	t->data = x;t->next=NULL;
	if(t==NULL) cout<<"Queue Overflow!!\n";
	else{
		if(front==NULL){
			front=rear=t;
		}
		else{
			rear->next = t;
			rear = t;
		}
	}
}

Tnode* Queue::Dequeue(){
	Tnode* x=NULL;
	if(front==NULL) cout<<" Queue Underflow!!\n";
	else{
		node *p=front;
		x=front->data;
		front=front->next;
		delete p;
	}
	return x;	
}

// void Queue::Display(){
// 	node*p=front;
// 	while(p){
// 		cout<<p->data<<" ";
// 		p=p->next;
// 	}
// 	cout<<endl;
// }

// int main(){
// 	Queue Q;
// 	// Q.Enqueue(2);
// 	// Q.Enqueue(45);
// 	// Q.Enqueue(6);
// 	// Q.Enqueue(1);
// 	// Q.Enqueue(89);

// 	// Q.Dequeue();

// 	// Q.Display();
// }
