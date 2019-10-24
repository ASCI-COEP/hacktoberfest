/*graph using adjacency matrix*/
typedef struct graph{
	int **a;
	int n;
}graph;
int getn(graph* g);
void ginit(graph* g, int n);
int CreateGraphFromFile(char* filename, graph* g);
void PrintGraph(graph* g);
int* GraphColoring(graph *g, int m);
