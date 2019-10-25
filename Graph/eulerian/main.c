#include"graph.h"
#include<stdio.h>
int main(int agrc, char *agrv[]){
	graph g;
	CreateGraphFromFile(agrv[1], &g);
	PrintGraph(&g);
	int res = IsEulerian(&g);
	if(res == 0)
		printf("Graph is not Eulerian\n");
	else if(res == 1)
		printf("Graph has Eulerian Path\n");
	else if(res == 2)
		printf("Graph has Eulerian Cycle\n");
	return 0;
}
