#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main(){
	list l1,l2,l;
	char *s;
	int i;
	init(&l1);
	init(&l2);
	insert(&l1, "abc", 0);
	traverse(l1, s);
	printf("%s\n",s );
	insert(&l1, "pqr", 1);
	traverse(l1, s);
	printf("%s\n",s );
	insert(&l1, "abc", 0);
	traverse(l1, s);
	printf("%s\n",s );
	removeDuplicate(&l1);
	traverse(l1, s);
	printf("%s\n",s );
	//insert(&l2, "xyz", 0);
	//traverse(l1, s);
	//printf("%s\n",s );
	intersect(&l1, &l2);


}