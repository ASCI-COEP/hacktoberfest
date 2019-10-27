#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *s;
	struct node *next;
}node;

typedef struct list{
	node *front, *rear;
}list;

void init(list *l);

int isempty(list);

void insert(list *l, char *str, int pos); 

char *traverse(list *l);

void remDuplicate(list *l);

void Interseclist(list *l1, list*l2);

int length(list l);