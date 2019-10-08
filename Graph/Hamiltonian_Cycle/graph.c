#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"graph.h"
int getn(graph* g){
	return g->n;
}
void ginit(graph* g, int n){
	int i, j;
	g->n = n;
	g->a = (int**)malloc(sizeof(int*)*n);
	for(i = 0; i < n; i++){
		g->a[i] = (int*)malloc(sizeof(int)*n);
		for(j = 0; j < n; j++)
			g->a[i][j] = 0;
	}
}
int CreateGraphFromFile(char* filename, graph* g){
	FILE *fp;
	fp = fopen(filename, "r");
	if(!fp)
		return 0;
	int n, i, j;
	fscanf(fp, "%d", &n);
	ginit(g, n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			fscanf(fp, "%d", &(g->a[i][j]));
	}
	return 1;
}
int IsSafe(int i, graph *g, int *path, int pos){
	int j;
	if(g->a[path[pos - 1]][i] == 0)
		return 0;
	for(j = 0; j < pos; j++){
		if(path[j] == i)
			return 0;
	}
	return 1;
}
int HamCycleExist(graph *g, int *path, int pos){
	int i;
	if(pos == g->n){
		if(g->a[path[pos - 1]][path[0]] == 1)
			return 1;
		else{
			return 0;
		}
	}
	for(i = 1; i < g->n; i++){
		if(IsSafe(i, g, path, pos)){
			path[pos] = i;
			if(HamCycleExist(g, path, pos + 1) == 1){
				return 1;
			}
			path[pos] = -1;
		}
	}
	return 0;
}
int HamCycle(graph *g){
	int *path = (int*)malloc(sizeof(int)*(g->n));
	int i;
	for(i = 0; i < g->n; i++)
		path[i] = -1;
	path[0] = 0;
	if(HamCycleExist(g, path, 1) == 0){
		printf("Hamiltonian Cycle does not exist\n");
		return 0;
	}
	printf("Hamiltonian Cycle exist\n");
	for(i = 0; i < g->n; i++)
		printf("%d ", path[i]);
	printf("\n");
	return 1;
}
void PrintGraph(graph* g){
	int i, j;
	for(i = 0; i < g->n; i++){
		for(j = 0; j < g->n; j++){
			printf("%3d", g->a[i][j]);
		}
		printf("\n");
	}
}

