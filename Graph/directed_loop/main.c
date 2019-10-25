#include"graph.h"
#include<stdio.h>
int main(int agrc, char *agrv[]){
	graph g;
	CreateGraphFromFile(agrv[1], &g);
	PrintGraph(&g);
	int result = DetectCycle(&g);
	if(result == 1)
		printf("Directed Graph contain Cycle\n");
	else
		printf("Directed Graph does Not contain Cycle\n");
	return 0;
}
