#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void qinit(queue *q){
	q->front = NULL;
	q->end = NULL;
}

int qfull(queue *q){
	return 0;
}

int qempty(queue *q){
	return q->front == NULL;
}
void enq(queue *q, data d){
	data *newnode = (data*) malloc(sizeof(data));
	if(q->front == NULL){
		strcpy(newnode->name, d.name);
		//printf("%s\n",newnode->name );
		newnode->age =  d.age;
		newnode->next = newnode;
		q->front = newnode;
		q->end = newnode;
		return;
	}
	//data *ptr = q->end;
	strcpy(newnode->name,d.name);
	//printf("%s\n",newnode->name );
	newnode->age =  d.age;
	newnode->next = q->front;
	q->end->next = newnode;
	q->end = newnode;
}

data deq(queue *q){
	data * ptr = q->front;
	data d;
	if(q->end == q->front){
		d.age = ptr->age;
		strcpy(d.name, ptr->name);
		d.next = NULL;
		qinit(q);
		free(ptr);
		return d;
	}
	d.age = ptr->age;
	strcpy(d.name, ptr->name);
	d.next = NULL;
	q->front = q->front->next;
	free(ptr);
	return d;
}