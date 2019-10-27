#include "list.h"

void init(list *l){
	l -> front = NULL;
	l -> rear  = NULL;
}

void insert(list *l, char *str, int position){
	node *temp, *x;
	temp = l -> front;
	int len = length(*l);
	int i;
	if (position < 0 || position > len)
		return;

	for (i = 0; i < position -1; i++)
		temp = temp -> next;

	if (position == 0)
		temp = l->rear;

	x = (node *)malloc(sizeof(node));
	x -> s = (char *)malloc(sizeof(str) + 1);
	strcpy(x->s, str);

	if (len == 0){
		l -> front = x;
		l -> rear = x;
		x -> next = x;
		return;
	}

	x -> next = temp->next;
	temp -> next = x;

	if (position == len)
		l -> rear = x;

	if (position == 0)
		l-> front = x;
}	

int length(list l){
	int cnt = 0;
	node *p = l.front;
	if (p == NULL)
		return 0;
	do{
		cnt++;
		p = p -> next;
	}while(p != l.front);

	return cnt;
}
char *traverse(list *l){
	node *temp;
	temp = l->front;

	char *str;
	str = (char *)malloc(500);
	/*If temp is NULL*/
	if (!temp){
		strcat(str, "[]");
		return str;
	}
	strcat(str, "[");
	do{
		// len_str += sizeof(temp -> s);
		strcat(str, temp -> s);
		strcat(str, ", ");
		temp = temp -> next;
	}while(temp != l->front);
	strcat(str, "]");
	return str;
}
void remDuplicate(list *l){
	node *temp, *p, *q, *r;
	temp = l -> front;
	p = l -> front;
	q = l -> rear;
	int len = length(*l);
	if (len <= 1){
		printf("List must contain atleast 2 elements\n");
		return;
	}
	while(p != q){
		do{
			if (!strcmp(p -> s, temp -> next -> s)){
				r = temp -> next;
				temp -> next = temp -> next -> next;
				r -> next = NULL;
				/*Change rear pointer if duplicate*/
				if (r == q){
					q = temp;
					l->rear = q;
					free(r);
					break;
				}
				free(r);
				if (!strcmp(p -> s, temp -> next -> s)){
					continue;
				}
			}
			temp = temp -> next;
		}while(temp -> next != l -> front);
		p = p-> next;
		temp = p;
	}
}
void Interseclist(list *l1, list*l2){
	list l3;
	node *temp1 = l1 -> front, *temp2 = l2 -> front;
	int pos = 0;
	char *s;
	init(&l3);
	remDuplicate(l1);
	remDuplicate(l2);
	do{
		do{

			if(!strcmp(temp1 -> s, temp2-> s)){
				insert(&l3, temp1->s, pos);
				pos++;
			}
			temp2 = temp2 -> next;
		}while(temp2 != l2 -> front);
		
		temp1 = temp1 -> next;
	}while(temp1 != l1 -> front);
	
	/*Traverse the intersected list*/
	s = traverse(&l3);
	printf("%s\n",s);
}
