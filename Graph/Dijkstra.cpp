/*
Given a graph of V nodes represented in the form of adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow .The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are 2*V space separated values, which denotes the weight of an edge of the matrix (graph). The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test case output will be V space separated integers where the ith integer denote the shortest distance of ith vertex from source vertex.

You task:
You are required to complete the function dijkstra() which takes 3 arguments. The first argument is the adjacency matrix (graph), the second argument is the source vertex s and the third argument is V denoting the size of the matrix. The function prints  V space separated integers where i'th integer denotes the shortest distance of the i'th vertex from source vertex.

Constraints:
1 <= T <= 20
1 <= V <= 20
0 <= graph[i][j] <= 1000
0 <= s

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.
*/

#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        vector<vector<int>> g(V);
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        int s;
        cin>>s;
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}


/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
void dijkstra(vector<vector<int>> graph, int src, int V)
{   int i, j;
    bool visited[V + 1];
    int distance[V + 1];
    for(i = 0; i < V; i++)
            distance[i] = INT_MAX, visited[i] = false; //Marking every node as unvisited and distance to every node as maximum
    distance[0] = 0;
    visited[src] = true;//Marking source node as visited
    for(i = 0; i < V; i++) {
        if(graph[src][i]) {
            distance[i] = graph[src][i]; //Initializing the distance of every node connected to the source node
        }
    }
    for(i = 0; i < V; i++) {
        int u, k, min = INT_MAX;
        for(k = 0; k < V; k++)
                if(!visited[k] && distance[k] < min) //Finding a vertex with minimum distance
                        min = distance[k], u = k; //Storing vertex in u
        visited[u] = true;
        for(j = 0; j < V; j++) {
            if(!visited[j] && graph[u][j] && distance[j] > distance[u] + graph[u][j] && distance[u] != INT_MAX) // Selecting a unvisited vertex connected to the vertex u with maximum distance
                            distance[j] = distance[u] + graph[u][j];
       }

    }
//Printing the o/p
    for(i = 0; i < V; i++) {
            if(distance[i] == INT_MAX)
                cout << "0 ";
            else
                cout << distance[i] << " ";
    }
}

