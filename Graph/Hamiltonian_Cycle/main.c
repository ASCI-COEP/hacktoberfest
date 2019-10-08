#include"graph.h"
#include<stdio.h>
int main(int agrc, char *agrv[]){
	graph g;
	CreateGraphFromFile(agrv[1], &g);
	PrintGraph(&g);
	HamCycle(&g);
	return 0;
}
