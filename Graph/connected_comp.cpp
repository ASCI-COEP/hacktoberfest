#include <bits/stdc++.h>
using namespace std;

// Algorithm to find connected components in a graph
// Using Disjoint Set Union Data Structure

const int N = 1e5 + 11;
// N is the maximum number of possible nodes in the graph
int p[N], sz[N];
// parent array and the size array

// function to get the id of parent of a set
// uses Path Compression trick

int get(int x){
  if (x == p[x]) return x; // if id is same as parent val
  return p[x] = get(p[x]); // Path Compression 
}

void unite(int x, int y){
	// function to combine two disjoint sets
	// uses Union By Size Algorithm
	x = get(x), y = get(y);
	if (x == y) return; // both belong to same component
	if (sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y]; // connecting y to x iff size(y) < size(x)
	p[y] = x;
    // make x as y's parent
}

int connected_comp(int n){
	int cnt = 0; // stores the number of connected components
	for (int i = 1; i <= n; i++)
		cnt += get(i) == i;
    return cnt;
}

int32_t main(){
	int n, m; // total number of nodes of the graph = n
	// total number of edges of graph = m
	cin >> n >> m;
	// initialize the parent array and the size array
	// initially all nodes are their own parents
	for (int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
    for (int i = 0; i < m; i++){
    	int x, y;
    	// two nodes to connect;
    	cin >> x >> y;
    	unite(x, y);
    }
   cout << "The number of connected components in the graph is : ";
   int ret = connected_comp(n);
   cout << ret << endl;
}