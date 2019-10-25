#include<stdlib.h>
#include"stack.h"
#include<stdio.h>
void maintainarr(int a[][8], stack *s){
	node n[8];
	node curr;
	int k = 0, j, x, y, i;
	k = stackcopy(s, n);
	for(i = 0; i < k; i++){
		curr = n[i];
		for(j = 0; j < 8; j++)
			if(j != curr.col)
				a[curr.row][j] = 1;
		for(j = 0; j < 8; j++)
			if(j != curr.row)
				a[j][curr.col] = 1;
		x = curr.row + 1;
		y = curr.col + 1;
		while(x != 8 && y != 8)
			a[x++][y++] = 1;
		x = curr.row - 1;
		y = curr.col - 1;
		while(x != -1 && y != -1)
			a[x--][y--] = 1;
		x = curr.row - 1;
		y = curr.col + 1;
		while(x != -1 && y != 8)
			a[x--][y++] = 1;
		x = curr.row + 1;
		y = curr.col - 1;
		while(x != 8 && y != -1)
			a[x++][y--] = 1;
	}
	for(i = 0; i < k; i++){
		curr = n[i];
		a[curr.row][curr.col] = 2;
	}
}
int main(int agrc, char* agrv[]){
	int a[8][8];
	int i, j, x, y, flag = 0, p, q, m, g, h;
	node curr;
	node *tmp;
	stack s;
	init(&s);
	for(g = 0; g < 8; g++){
	for(h = 0; h < 8; h++){
	curr.row = g;
	curr.col = h;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			a[i][j] = 0;
		}
	}
	for(i = 0; i < 8; i++)
		a[curr.row][i] = 1;
	for(i = 0; i < 8; i++)
		a[i][curr.col] = 1;
	for(i = 1; i < 8; i++)
		a[i][i] = 1;
	push(&s, curr);
	a[curr.row][curr.col] = 2;
	while(1){
		for(j = 0; j < 8; j++){
			for(i = 0; i < 8; i++){
				if(a[i][j] == 0){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				flag = 0;
				break;	
			}
		}
		while(i == 8 && j == 8){
			tmp = pop(&s);
			a[tmp->row][tmp->col] = 0;
			for(m = 0; m < 8; m++)
				if(m != tmp->col)
					a[tmp->row][m] = 0;
			for(m = 0; m < 8; m++)
				if(m != tmp->row)
					a[m][tmp->col] = 0;
			x = tmp->row + 1;
			y = tmp->col + 1;
			while(x != 8 && y != 8)
				a[x++][y++] = 1;
			x = tmp->row - 1;
			y = tmp->col - 1;
			while(x != -1 && y != -1)
				a[x--][y--] = 1;
			x = tmp->row - 1;
			y = tmp->col + 1;
			while(x != -1 && y != 8)
				a[x--][y++] = 1;
			x = tmp->row + 1;
			y = tmp->col - 1;
			while(x != 8 && y != -1)
				a[x++][y--] = 1;
			maintainarr(a, &s);
			for(j = tmp->col; j < 8; j++){
				for((j == tmp->col ? (i = (tmp->row + 1)) : (i = 0)); i < 8; i++){
					if(a[i][j] == 0){
						flag = 1;
						break;
					}
				}
				if(flag == 1){
					flag = 0;
					break;	
				}
			}
		}			
		curr.row = i;
		curr.col = j;
		for(m = 0; m < 8; m++)
			if(m != curr.col)
				a[curr.row][m] = 1;
		for(m = 0; m < 8; m++)
			if(m != curr.row)
				a[m][curr.col] = 1;
		x = curr.row + 1;
		y = curr.col + 1;
		while(x != 8 && y != 8)
			a[x++][y++] = 1;
		x = curr.row - 1;
		y = curr.col - 1;
		while(x != -1 && y != -1)
			a[x--][y--] = 1;
		x = curr.row - 1;
		y = curr.col + 1;
		while(x != -1 && y != 8)
			a[x--][y++] = 1;
		x = curr.row + 1;
		y = curr.col - 1;
		while(x != 8 && y != -1)
			a[x++][y--] = 1;
		a[curr.row][curr.col] = 2;
		push(&s, curr);
		if(isfull(&s))
			break;
	}
	printf("start position %d %d\n", g, h);
	for(p = 0; p < 8; p++){
		for(q = 0; q < 8; q++){
			printf("%3d", a[p][q]);
		}
		printf("\n");
	}
	}
	printf("\n");
	}
	return 0;
}
