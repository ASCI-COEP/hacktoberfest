#include<stdlib.h>
#include"stack.h"
void init(stack *s){
	s->i = 0;
}
int isfull(stack *s){
	return s->i == MAX;
}
int isempty(stack *s){
	return s->i == 0;
}
void push(stack *s, node curr){
	s->arr[s->i] = curr;
	s->i++;
}
/*caller should free the return value*/
node* pop(stack *s){
	node* curr = (node*)malloc(sizeof(node)*1);
	s->i--;
	*curr = s->arr[s->i];
	return curr;
}
int stackcopy(stack *s, node* n){
	int i, k = 0;
	for(i = 0; i < s->i; i++){
		n[k++] = s->arr[i];
	}
	return k;
}
