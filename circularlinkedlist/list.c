#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

void init(list *l){
	*l = NULL;
}

void append(list *l, char* d){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	strcpy(newnode->data, d);
	node* ptr;
	ptr = *l;
	if(!ptr){
		printf("first\n");
		*l = newnode;
		(*l)->next = *l;
		return;
	}
	while(ptr->next != *l){
		ptr = ptr->next;

	}
	ptr->next = newnode;
	ptr->next->next = *l;
}

void insert(list *l, char *d, int pos){
	int i, n;
	n = length(*l);

	if(pos > n){
		return;
	}
	node *newnode= (node *)malloc(sizeof(node));
	strcpy(newnode->data, d);
	newnode->next = NULL;
	node *ptr = *l;
	if(pos == 0 && n == 0){
		*l = newnode;
		(*l)->next = *l;
		return;
	}
	if(pos == 0 ){
		pos = n;
		while(pos-1){
			ptr = ptr->next;
			pos--;
		}
		newnode->next = ptr->next;
		ptr->next = newnode;
		*l = newnode;
		return;
	}
	while((pos-1) != 0 && (pos-1)>0){
		ptr = ptr->next;
		pos--;
	}
	newnode->next = ptr->next;
	ptr->next = newnode;

}

void delete(list *l, int pos){
	int i, n;
	n = length(*l);
	node *ptr = *l, *temp;
	if(n == 1 && pos == 0){
		*l = NULL;
		free(ptr);
		return;
	}
	if(pos > n-1){
		return;
	}
	if(pos == 0){
		pos = n;
		while(pos-1){
			ptr = ptr->next;
			pos--;
		}
		temp = ptr->next;
		ptr->next = ptr->next->next;
		*l = ptr->next;
		free(temp);
		return;
	}
	while(pos-1){
		ptr = ptr->next;
		pos--;
	}
	temp = ptr->next;
	ptr->next = ptr->next->next;
	free(temp);
}

void traverse(list l, char * str){
	node *ptr = l;
	char s[100];
	sprintf(str,"[");
	if(ptr){
		sprintf(s," %s ",ptr->data );
		strcat(str, s);
		ptr=ptr->next;
		while(ptr != l){
			sprintf(s," %s ",ptr->data );
			strcat(str, s);
			ptr = ptr->next;
		}
	}
	strcat(str,"]");
	//return str;
}

int length(list l){
	int count = 1;
	node *ptr = l;
	if(!ptr)
		return 0;
	ptr = ptr->next;
	while(ptr != l){
		count++;
		ptr = ptr->next;
	}
	return count;
}

void removeDuplicate(list *l){
	node *ptr = *l;
	node *ptr2;
	int count = 0, pos;
	if(ptr){
		while(ptr->next != *l){
			pos = count + 1;
			ptr2 = ptr->next;
			while(ptr2 != *l){
				if(strcmp(ptr2->data, ptr->data) == 0){
					//printf("%d\n",pos );
					ptr2 = ptr2->next;
					delete(l,pos);
					pos--;
				}
				else
					ptr2 = ptr2->next;
				pos++;
			}
			ptr = ptr->next;
			count++;
		}	
	}
}

void intersect(list *l1, list *l2){
	removeDuplicate(l1);
	removeDuplicate(l2);
	printf("done\n");
	node *ptr = *l1;
	printf("[");
	if(ptr){
		printf(" %s ",ptr->data );
		ptr=ptr->next;
		while(ptr != *l1){
			printf(" %s ",ptr->data );
			ptr = ptr->next;
		}
	}
	ptr = *l2;
	if(ptr){
		printf(" %s ",ptr->data );
		ptr=ptr->next;
		while(ptr != *l2){
			printf(" %s ",ptr->data );
			ptr = ptr->next;
		}
	}
	printf("\n\\ \\\n");
}

