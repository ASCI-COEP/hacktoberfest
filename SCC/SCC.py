#****************************************************************
#* Author - Soumya Saurav
#* Github - github.com/Default2882
#* Date - 01/09/2019
#****************************************************************


# This program can find the top 5 strongly connected components,
# Using DFS.
# Algo -
#     * Perform DFS on the reversed graph to calculate the finish timings of each vertex.
#     * Perform DFS on normal graph according to the descending order of the finish time.

import sys, threading
sys.setrecursionlimit(800000)
threading.stack_size(67108864)

filename = sys.argv[1]
fh = open(filename,"r")

# Number of nodes needs to be entered manually.
# The default is set to be 875715 because the test.txt contains exactly 875715 nodes
# and it is the biggest testcase amongst all test cases.
# Total number of 

n_nodes = 875715

mygraph = dict()
rev_mygraph = dict()

# Creating the graph from the file passed in as the command line argument.

for line in fh.readlines():
	k = list(map(int,line.split()))
	if k[0] in mygraph:
		mygraph[k[0]].append(k[1])
	else:
		mygraph[k[0]] = [k[1]]

# Creating reversed graph from the normal graph.

for _k,_v in mygraph.items():
	for _n in _v:
		if _n in rev_mygraph:
			rev_mygraph[_n].append(_k)
		else:
			rev_mygraph[_n] = [_k] 

#print(mygraph)
#print(rev_mygraph)

def DFS(graph, i,order, visited):
	visited[i-1] = True
	if i not in graph:
		order.append(i)
		return
	for node in graph[i]:
		if visited[node-1] != True:
			k =  DFS(graph, node, order, visited)
	order.append(i)


def DFS_loop(graph, n_nodes,order, visited):
	for i in range(n_nodes,0,-1):
		if i in graph:
			if visited[i-1] == False:
				DFS(graph, i,order, visited)

def DFS2(graph, i, scc, visited,order):
	k = 1
	visited[i-1] = True
	if i not in graph: return
	for node in graph[i]:
		if visited[node-1] == False:
			try:
				k += DFS2(graph, node,scc,visited,order)
			except:
				k+=0
	return k


def DFS_loop2(graph, n_nodes,scc,visited,order):
	for i in reversed(order):
		if i in graph:
			if visited[i-1] == False:
				m = DFS2(graph, i,scc,visited,order)
				scc.append(m)


def main():
	order = []
	scc = []
	visited = [False]*n_nodes
	DFS_loop(rev_mygraph, n_nodes,order,visited)
	#print(order)
	visited = [False]*n_nodes
	DFS_loop2(mygraph, n_nodes,scc,visited,order)
	print(sorted(scc, reverse = True)[:5])


thread = threading.Thread(target=main)
thread.start()
