#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"
#define BUFFER 10
static int max_strLen = 0;
//char str[1000];

void init(list *l) {
	l -> head = NULL;
	l -> tail = NULL;
	l -> nodeCount = 0;
}

void insert(list *l, char *str, int pos) {
	int i = 0;
	node *ptr;
	/*if(nodeCount == 0) {	
		l -> head = (node *)malloc(sizeof(node));
		ptr = l -> head;
		ptr -> data = (char *)malloc(20);
		strcpy(ptr -> data, str);
		ptr -> next = NULL;
		l -> tail = ptr;
		nodeCount++;
	}*/
	if(pos <= l -> nodeCount) {
		node *temp;
		ptr = l -> head;
		while(i < pos - 2) {
			ptr = ptr -> next;
			i++;
		}
		temp = ptr -> next;
		ptr -> next = (node *)malloc(sizeof(node));
		l -> nodeCount++;
		ptr = ptr -> next;
		ptr -> data = (char *)malloc(20);
		ptr -> next = temp;
		strcpy(ptr -> data, str);
	}
	else if(pos > l -> nodeCount) {
		i = 0;
		
		if(!l -> head) {
			l -> head = (node *)malloc(sizeof(node));
			ptr = l -> head;
			l -> nodeCount++;
			while(i < pos - 1) {
				ptr -> data = (char *)malloc(20);
				strcpy(ptr -> data, "\0");
				ptr -> next = (node *)malloc(sizeof(node));
				l -> nodeCount++;
				ptr = ptr -> next;
				i++;
			}
			ptr -> data = (char *)malloc(20);
			strcpy(ptr -> data, str);
			ptr -> next = l -> head;
			l -> tail = ptr;
		}
				
		else {
			ptr = l -> head;		
			while(i < l -> nodeCount - 1) {
				ptr = ptr -> next;
				i++;
			}
			while(i < pos - 1) {
				ptr -> next = (node *)malloc(sizeof(node));
				l -> nodeCount++;
				ptr = ptr -> next;
				ptr -> data = (char *)malloc(20);
				strcpy(ptr -> data, "\0");
				i++;
			}
			strcpy(ptr -> data, str);
			ptr -> next = l -> head;
			l -> tail = ptr;
		}
	}		
	max_strLen += strlen(str);
	printf("%s has been added to list at position %d\n", str, pos);
}

char *traverse(list *l) {
	char *str = (char *)malloc(max_strLen);
	strcpy(str, "");
	node *ptr = l -> head;
	strcat(str, "[");
	strcat(str, ptr -> data);
	strcat(str, ",");
	ptr = ptr -> next;
	while(ptr != l -> head) {
		strcat(str, ptr -> data);
		if(ptr -> next == l -> head) strcat(str, "");
		else strcat(str, ",");
		ptr = ptr -> next;
	}
	strcat(str, "]");
	strcat(str, "\0");
	
	return str;
}	
		
void remDuplicate(list *l) {
	int flag = 0;
	node *ptr_inner, *ptr_outer, *ptr_inner_prev, *temp;
	ptr_outer = l -> head;
		
	while(ptr_outer -> next != l -> head) {
		ptr_inner = ptr_outer -> next;
		ptr_inner_prev = ptr_outer;

		while(ptr_inner != ptr_outer) {
			flag = 0;
			if(strcmp(ptr_inner -> data, ptr_outer -> data) == 0) {
				temp = ptr_inner;
				ptr_inner = ptr_inner -> next;
				ptr_inner_prev -> next = temp -> next;
				free(temp);
				flag = 1;
			}
			if(flag) continue;
			ptr_inner = ptr_inner -> next;
			ptr_inner_prev = ptr_inner_prev -> next;
		}
		ptr_outer = ptr_outer -> next;				
	}
}

void Interseclist(list *l1, list*l2) {
	int flag = 0, count1 = 0, count2 = 0;
	remDuplicate(l1);
	remDuplicate(l2);
	
	node *ptr1, *ptr2, *ptr3, *temp;
	ptr1 = l1 -> head;
	while(count1 < l1 -> nodeCount) {
		ptr2 = l2 -> head;
		flag = 0;
		count2 = 0;
		while(count2 < l2 -> nodeCount) {
			if(strcmp(ptr1 -> data, ptr2 -> data) == 0) {
				count2++;
				flag++;
				break;
			}
			ptr2 = ptr2 -> next;
			count2++;
		}
		if(!flag) {
			temp = ptr1;
			ptr3 = ptr1;
			while(ptr3 -> next != ptr1)
				ptr3 = ptr3 -> next;
			ptr3 -> next = ptr1 -> next;
			if(temp == l1 -> head)
				l1 -> head = ptr1 -> next;
			ptr1 = ptr1 -> next;
			count1++;
			free(temp);
			continue;
		}
		ptr1 = ptr1 -> next;
		count1++;
	}	
}
	



