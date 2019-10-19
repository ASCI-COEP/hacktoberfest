#include <stdio.h>
#include <stdlib.h>

typedef struct pos
{
	int row;
	int col;
}pos;

typedef struct node
{
	pos t;
	struct node* next;
}node;

typedef node* stack;

void init(stack *s);

void push(stack *s, pos data);

pos pop();

int check(stack s, pos data);

void traverse (stack s);

int length (stack s);

int isempty(stack s);