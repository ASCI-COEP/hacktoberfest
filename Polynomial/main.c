#include<stdio.h>
#include<stdlib.h>
#include "poly.h"

int main() {
	int c, e;
	poly p1, p2;
	init(&p1);
	init(&p2);
	while(scanf("%d%d", &c, &e) != -1)
		insert(&p1, c, e);
	printf("Polynomial 1 : ");
	print(&p1);
	while(scanf("%d%d", &c, &e) != -1)
		insert(&p2, c, e);
	printf("Polynomial 2 : ");
	print(&p2);
	poly *p3;
	init(p3);
	p3 = add(&p1, &p2);
	printf("Result : ");
	print(p3);
	return 0;
}
