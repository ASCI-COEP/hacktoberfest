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
int isSafe(graph *g, int c, int *color, int v){
	int i;
	for(i = 0; i < g->n; i++){
		if(g->a[v][i] && color[i] == c)
			return 0;
	}
	return 1;
}
int Coloring(graph *g, int m, int *color, int v){
	int i;
	if(v == g->n)
		return 1;
	for(i = 1; i <= m; i++){
		if(isSafe(g, i, color, v)){
			color[v] = i;
			if(Coloring(g, m, color, v + 1) == 1)
				return 1;
			color[v] = 0;
		}
	}
	return 0;
}
int* GraphColoring(graph *g, int m){
	int *color = (int*)malloc(sizeof(int) * g->n);
	int i;
	for(i = 0; i < g->n; i++)
		color[i] = 0;
	if(Coloring(g, m, color, 0) == 0)
		return NULL;
	return color;
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

