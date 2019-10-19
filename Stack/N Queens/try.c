#include "stack.h"

int main(int argc, char const *argv[])
{
	stack l;
	pos p, x;
	init(&l);
	
	p.row = 2;
	p.col = 3;
	push (&l, p);
	
	p.row = 4;
	p.col = 3;
	
	if (check(l, p))
		push (&l, p);
	else
		printf("Not pushed\n");

	x = pop(&l);
	printf("row = %d\n",x.row );
	printf("col = %d\n",x.col );
	x = pop(&l);
	printf("row = %d\n",x.row );
	printf("col = %d\n",x.col );
	return 0;
}