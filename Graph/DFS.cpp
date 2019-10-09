#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph
{
	int V;
	list<int>*adj;
	bool*visited;
public:
	Graph(int);
	void addedge(int, int);
	void getdfs();
	void dfs(int);
};
Graph::Graph(int v)
{
	V = v;
	adj = new list<int>[V + 1];
	visited = new bool[V + 1];
}
void Graph::addedge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void Graph::getdfs()
{
	memset(visited, false, V + 1);
	for (int i = 1; i < V + 1; i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
}
void Graph::dfs(int src)
{
	visited[src] = true;
	cout << src << " ";
	list<int>::iterator it;
	for (it = adj[src].begin(); it != adj[src].end(); it++)
	{
		if (!visited[(*it)])
			dfs(*it);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	Graph g(7);
	g.addedge(1, 2);
	g.addedge(1, 3);
	g.addedge(1, 5);
	g.addedge(2, 4);
	g.addedge(2, 5);
	g.addedge(4, 6);
	g.addedge(5, 6);
	g.getdfs();
}