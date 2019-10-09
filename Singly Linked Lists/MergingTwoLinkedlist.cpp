#include<iostream>
using namespace std;

struct linkedlist
{
	int d;
	struct linkedlist *next;
};
typedef struct linkedlist node;

node* create(node *head)
{
	node *q = new node;
	cin >> q->d;
	q->next = NULL;
	head = q;

	return head;
}

node* insert(node *head)
{
	if (head == NULL)
	{
		head = create(head);
	}
	else
	{
		node *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		node *q = new node;
		cin >> q->d;
		q->next = NULL;
		p->next = q;

	}
	return head;
}

node* delete_node(node* head)
{
	node* q = head;
	head = q->next;
	delete(q);
	return head;
}

node* insert_mid(node* head1, node* head2)
{
	node* q = head1;
	node* r = new node;
	r->d = head2->d;
	r->next = q->next;
	q->next = r;

	return head1;
}

node* insert_midmid(node* head1, node* head2)
{
	node* q = head1;
	node* p = head2;
	while (p->next != NULL)
	{
		p = p->next;
	}
	node* r = new node;
	r->d = head2->d + p->d;
	r->next = q->next;
	q->next = r;

	return head1;
}

void print(node* head)
{
	if (head == NULL)
	{
		cout << "The Linked list is Empty" << endl;
	}
	else
	{
		node* q = head;
		while (q->next != NULL)
		{
			cout << q->d << "->";
			q = q->next;
		}
		cout << q->d << endl;
	}
}

node* oddpossum(node * head1, node* head2)
{
	node* p = head1;

	if (head2 == NULL)
	{
		node *r = new node;
		r->d = p->d + p->next->next->d;
		r->next = NULL;
		head2 = r;
	}
	else
	{
		node* q = head2;
		node* r = new node;
		//while (p->next != NULL && p->next->next!=NULL)
		while (q->next != NULL)
		{
			q = q->next;
		}

		r->d = p->d + p->next->next->d;
		r->next = NULL;
		q->next = r;
	}
	return head2;
}

node* evepossum(node * head1, node* head2)
{
	node* p = head1;

	if (head2 == NULL)
	{
		node *r = new node;
		r->d = p->next->d + p->next->next->next->d;
		r->next = NULL;
		head2 = r;
	}
	else
	{
		node* q = head2;
		node* r = new node;
		//while (p->next != NULL && p->next->next!=NULL)
		while (q->next != NULL)
		{
			q = q->next;
		}

		r->d = p->next->d + p->next->next->next->d;
		r->next = NULL;
		q->next = r;
	}
	return head2;
}

int main()
{
	node *ll1 = NULL;
	node *ll2 = NULL;
	node *ll3 = NULL;
	ll1 = insert(ll1);
	ll1 = insert(ll1);
	ll1 = insert(ll1);
	ll1 = insert(ll1);
	ll1 = insert(ll1);
	ll1 = insert(ll1);
	print(ll1);



	ll2 = oddpossum(ll1, ll2);
	ll2 = oddpossum(ll1->next->next, ll2);
	print(ll2);

	ll3 = evepossum(ll1, ll3);
	ll3 = evepossum(ll1->next->next, ll3);
	print(ll3);

	ll1 = insert_mid(ll1, ll2);
	ll2 = delete_node(ll2);
	ll1->next->next = insert_mid(ll1->next->next, ll2);
	ll2 = delete_node(ll2);
	ll1->next->next->next->next = insert_midmid(ll1->next->next->next->next, ll1);
	ll1->next->next->next->next->next->next = insert_mid(ll1->next->next->next->next->next->next, ll3);
	ll3 = delete_node(ll3);
	ll1->next->next->next->next->next->next->next->next = insert_mid(ll1->next->next->next->next->next->next->next->next, ll3);
	ll3 = delete_node(ll3);
	print(ll1);
	print(ll2);
	print(ll3);

	return 0;

}