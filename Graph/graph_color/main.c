#include"graph.h"
#include<stdio.h>
#include<stdlib.h>
int main(int agrc, char *agrv[]){
	graph g;
	CreateGraphFromFile(agrv[1], &g);
	PrintGraph(&g);
	int *color = GraphColoring(&g, atoi(agrv[2]));
	if(color == NULL)
		printf("Can't Color %d vertices with %s colors\n", getn(&g), agrv[2]);
	else{
		for(int i = 0; i < getn(&g); i++){
			printf("%d vertex--> %d color\n", i + 1, color[i]);
		}
	}
	free(color);
	return 0;
}
