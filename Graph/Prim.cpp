#include<iostream>
#include<climits>
#include<list>
#include<vector>
#include<queue>
#include<functional>
#define INF INT_MAX
using namespace std;
typedef pair<int, int> iPair;
class Graph
{
	int V;
	list<iPair>*adj;
public:
	Graph(int v);
	void addedge(int a, int b, int w);
	void prim(int x);
};
Graph::Graph(int v)
{
	V = v;
	adj = new list<iPair>[V];
}
void Graph::addedge(int a, int b, int w)
{
	adj[a].push_back(make_pair(b, w));
	adj[b].push_back(make_pair(a, w));
}
void Graph::prim(int src)
{
	priority_queue<iPair, vector<iPair>, greater<iPair> >pq;
	vector<int>key(V , INF);
	vector<bool>inmst(V , false);
	vector<int>parent(V, -1);
	pq.push(make_pair(0, src));
	key[src] = 0;
	while(!pq.empty())
	{
		int u = pq.top().second;
		inmst[u] = true;
		pq.pop();
		list<iPair>::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = (*it).first;
			int weight = (*it).second;
			if(inmst[v]==false && key[v]>weight)
			{
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
				
			}
		}
	}
	cout<<"MINIMUM SPANNING TREE"<<endl;
	cout << "FROM" << "   WEIGHT   " << "TO" << endl;
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] << "       " <<key[i] <<"       "<< i << endl;
	}
}
int main()
{
	Graph g(9);
	g.addedge(0, 1, 4);
	g.addedge(0, 7, 8);
	g.addedge(1, 2, 8);
	g.addedge(1, 7, 11);
	g.addedge(2, 3, 7);
	g.addedge(2, 8, 2);
	g.addedge(2, 5, 4);
	g.addedge(3, 4, 9);
	g.addedge(3, 5, 14);
	g.addedge(4, 5, 10);
	g.addedge(5, 6, 2);
	g.addedge(6, 7, 1);
	g.addedge(6, 8, 6);
	g.addedge(7, 8, 7);
	g.prim(0);
}
