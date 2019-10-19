#include "stack.h"

void init(stack *s){
	*s = NULL;
}
void push(stack *s, pos data){
	stack temp;
	temp = (node *)malloc(sizeof(node));
	temp -> t.row = data.row;
	temp -> t.col = data.col;
	temp -> next = *s;
	*s = temp;
	temp = NULL;
	free(temp);
}
pos pop(stack *s){
	stack temp;
	pos z;
	temp = *s;
	*s = (*s) -> next;
	temp -> next = NULL;
	z = temp -> t;
	free(temp);
	return z;
}

int check(stack s, pos data){
	while(s){
		if (abs(data.col - s->t.col) == abs(data.row - s->t.row)){
			return 0;
		}
		else if (data.col == s->t.col){
			return 0;
		}
		s = s->next;
	}
	return 1; 
}

void traverse (stack s){
	printf("Stack contents:::\n");
	while(s){
		printf("pair: (%d, %d)\n", s->t.row, s->t.col);
		s = s->next;
	}
}

int length (stack s){
	int len;
	while(s){
		len++;
		s = s->next;
	}
	return len;
}

int isempty(stack s){
	if (s)
		return 0;
	else
		return 1;
}