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
void dft(graph *g, int *visited, int u){
	visited[u] = 1;
	int i;
	for(i = 0; i < g->n; i++){
		if(g->a[u][i] != 0 && visited[i] == 0)
			dft(g, visited, i);
	}
}
int IsConnected(graph *g){
	int *visited = (int*)malloc(sizeof(int) * g->n);
	int i, j, cnt = 0;
	for(i = 0; i < g->n; i++)
		visited[i] = 0;
	int *count = (int*)malloc(sizeof(int)*g->n);
	for(i = 0; i < g->n; i++){
		for(j = 0; j < g->n; j++){
			if(g->a[i][j] != 0)
				cnt++;
		}
		count[i] = cnt;
		cnt = 0;
	}
	for(i = 0; i < g->n; i++){
		if(count[i] != 0)
			break;
	}
	if(i == g->n){
		free(visited);
		free(count);
		return 1;
	}
	dft(g, visited, i);
	for(j = 0; j < g->n; j++){
		if(visited[j] == 0 && count[j] > 0){
			free(visited);
			free(count);
			return 0;
		}
	}
	free(visited);
	free(count);
	return 1;
}
int IsEulerian(graph *g){
	int result = IsConnected(g);
	if(result == 0)
		return 0;
	int i, j, cnt = 0, odd = 0;
	int *count = (int*)malloc(sizeof(int) * g->n);
	for(i = 0; i < g->n; i++){
		for(j = 0; j < g->n; j++){
			if(g->a[i][j] != 0)
				cnt++;
		}
		count[i] = cnt;
		cnt = 0;
	}
	for(i = 0; i < g->n; i++){
		if(count[i] % 2 != 0)
			odd++;
	}
	if(odd > 2)
		return 0;
	if(odd == 2)
		return 1;
	if(odd == 0)
		return 2;
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

