#include "stack.h"

int main(int argc, char const *argv[])
{
	stack l;
	pos x;
	init(&l);
	/*Not in same row or column or diagonal*/
	/*For same diagonal -> mod y2 - y1 = mod x2 - x1*/
	/*Used check function in stack*/
	int n;
	scanf("%d",&n);
if (n < 4){
	printf("Invalid input\n");
	exit(1);
}
	int r = 1, c = 1;
	int len;/*To get number of elements in stack*/
	pos b;/*To retrieve popped element*/
	int flag;/*To check if any row pushed or not*/
		/*If row pushed: d = 0 else d = 1*/
	int i, j;
	DO:
	while(r <= n && c <= n){
		/*only increment column*/
		x.row = r;
		x.col = c;
		/*printf("pair :(%d,%d)\n", r, c);*/
		if(check(l, x)){
			push(&l, x);
			/*printf("pushed\n");*/
			/*After pushed Go to next row*/
			flag = 0;
			r++;
			c = 1;
		}
		else{
		/*	printf("not pushed\n");*/
			
			if (c == n){
				flag = 1;
				/*BackTracking*/
				b = pop(&l);
				/*printf("popped\n");*/
				c = b.col;
				r = b.row;
			}
			c++;
		}
		/*If entire row not pushed then backtrack to previous row;*/
	}
/*	traverse(l);*/
	len = length(l);
	if (len != n){
		/*printf("In goto\n");*/
		b = pop(&l);
		/*printf("popped\n");*/
		c = b.col;
		r = b.row;
		c++;
		goto DO;
	}

/*	printf("final\n");
	traverse(l);*/


	for (i = 1; i <= n;i++){
			b = pop(&l);
		for (j = 1; j <= n; j++) {
			if (j == b.col)
				printf("Q  ");
			else
				printf("-  ");
		}
		printf("\n");
}

return 0;
}