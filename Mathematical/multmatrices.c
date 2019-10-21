#include<stdio.h>
int main()
{
	int a, b, c, i, j, k;
	scanf("%d%d%d", &a, &b, &c);
	int x[a][b], y[b][c], z[a][c];
	for(i = 0; i < a; i++)
		for(j = 0; j < b; j++)
			scanf("%d", &x[i][j]);	
	for(i = 0; i < b; i++)
		for(j = 0; j < c; j++)
			scanf("%d", &y[i][j]);
	for(i = 0;i < a; i++){
		for(j = 0; j < b; j++){
			z[i][j] = 0;
			for(k = 0; k < c; k++)
				z[i][j] = z[i][j] + x[i][k] * y[k][j];
			printf("%d\n", z[i][j]);
		}
	}
	return 0;
}
