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
void PrintGraph(graph* g){
	int i, j;
	for(i = 0; i < g->n; i++){
		for(j = 0; j < g->n; j++){
			printf("%3d", g->a[i][j]);
		}
		printf("\n");
	}
}
#define white 0
#define gray 1
#define black 2
int dft(graph *g, int u, int *color){
	int i;
	color[u] = gray;
	for(i = 0; i < g->n; i++){
		if(g->a[u][i] == 1){
			if(color[i] == gray)
				return 1;
			if(color[i] == white && dft(g, i, color))
				return 1;
		}
	}
	color[u] = black;
	return 0;
}
int DetectCycle(graph *g){
	int i;
	int *color = (int*)malloc(sizeof(int) * g->n);
	for(i = 0; i < g->n; i++)
		color[i] = white;
	for(i = 0; i < g->n; i++){
		if(color[i] == white){
			if(dft(g, i, color) == 1)
				return 1;
		}
	}
	return 0;
}
