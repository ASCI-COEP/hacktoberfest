#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

typedef struct list {
	node *front, *rear;
}list;

void init(list *l) {
	l->front = NULL;
	l->rear = NULL;
}

int length(list *l) {
	node *curr = l->front;
	int i = 1;
	if(curr == NULL) {
		return 0;
	}
	else {
		while(curr->next != l->front) {
			i++;
			curr = curr->next;
		}
	}
	return i;
}


void insert(list *l, int num, int pos) {
	if(pos > (length(l)+1)) {
		printf("\n");
	}
	else {
		node *temp;
		if((l->front == NULL) && (l->rear == NULL) && (pos == 1)) {
			temp = (node *)malloc(sizeof(node));
			if(temp == NULL) {
				printf("Cannot allocate\n");
			}
			l->front = temp;
			l->rear = temp;
			temp->data = num;
			temp->next = l->front;
		}
		else if((l->front != NULL) && (pos == 1)) {
			temp = (node *)malloc(sizeof(node));
			temp->data = num;
			temp->next = l->front;
			l->front = temp;
			l->rear->next = temp;
		}
		else {
			int a = pos;
			node *temp2 = l->front;
			while(a-2) {
				temp2 = temp2->next;
				a--;
			}
			temp = (node *)malloc(sizeof(node));
			if(pos == length(l)+1) {
				temp->data = num;
				temp->next = temp2->next;
				temp2->next = temp;
				l->rear = temp;
			}
			else {
				temp->data = num;
				temp->next = temp2->next;
				temp2->next = temp;
			}
		}
	}
}

	
int winner(int people, int skips) {
	list n;
	init(&n);
	
	for(int i=0; i<people; i++) {
		insert(&n, i+1, i+1);
	}
	node *sword, *prev;
	
	int count = 1;
	sword = n.front;
	prev = n.front;
	while(length(&n)!=1) {
		while(count != skips) {
			prev = sword;
			sword = sword->next;
			count++;
		}
		prev->next = sword->next;
		if(sword == n.front) {
			n.front = prev->next;
		}
		sword->next = NULL;
		sword = prev->next;
		prev = sword;
		count = 1;
	}
	n.front = NULL;
	n.rear = NULL;
	return sword->data;
}


