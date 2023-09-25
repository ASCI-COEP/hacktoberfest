#include<stdio.h>
#include<stdlib.h>
#include"q.h"
#include<string.h>


void init(queue *a){

	a->head = NULL;
	a->tail = NULL;
	a->count = 0;
	
}

int isEmpty(queue *a){
	if(a->count  == 0){
		return 1;
	}
	else return 0;
}

void nq(queue *a, data st){
	node *temp = (node *)malloc(sizeof(node));
	if(!temp){
		printf("Unable to allocate mem");
		return;
	}
	if(a->head == NULL){
		a->head = temp;
		a->tail = temp;
		temp->front = NULL;
		temp->back = NULL;
		strcpy(temp->d.name,st.name);
		temp->d.mob = st.mob;
		a->count++;
		
	}
	else{
		a->tail->front = temp;
		temp->back = a->tail;
		temp->front = NULL;
		strcpy(temp->d.name,st.name);
		temp->d.mob = st.mob;
		a->tail = temp;
		a->count++;
		
	}
}


data dq(queue *a){
	data temp;
	strcpy(temp.name,a->head->d.name);
	temp.mob = a->head->d.mob;
	/*
	puts(temp.name);
	printf("%lld",temp.mob);
	*/
	if(a->count == 1){
		free(a->head);
		a->count--;
	}
	else{
		node *ptr = a->head;
		a->head = a->head->front;
		a->head->back = NULL;
		a->count--;
		free(ptr);
	}
	
	return temp;
	
}
