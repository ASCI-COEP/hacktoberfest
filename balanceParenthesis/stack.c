#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

node* createNode(char v) {
	node* temp = malloc(sizeof(node*));
	temp->data = v;
	temp->next = NULL;
	return temp;
}

void push(stack * s, char v) {
	node* temp = *s;
	*s = createNode(v);
	(*s)->next = temp;
}

char pop(stack * s) {
	node* temp = *s;
	char v = temp->data;
	*s = temp->next;
	free(temp);
	return v;
}

int isEmpty(stack * s) {
	if(*s)
		return 0;
	return 1;
}
void init(stack * s) {
	*s = NULL;
}
