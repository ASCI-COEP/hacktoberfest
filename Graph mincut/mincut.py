import sys
import random
import copy

def mincuts(trialmygraph):
	#print(trialmygraph)
	if len(trialmygraph)>2:
		#print(trialmygraph)
		while(True):
			u = random.choice(list(trialmygraph.keys()))
			#print(trialmygraph.keys())
			v = random.choice(trialmygraph[u])
			if v == u : continue
			#print(u,v)
			break
		contract(u,v,trialmygraph)
		return mincuts(trialmygraph)
	else:
		#print(trialmygraph.keys())
		count = 0
		for k,v in trialmygraph.items():
			#print(set(trialmygraph[k]))
			for i in trialmygraph[k]:
				if i != k : count +=1
			return count

def contract(u,v,trialmygraph):
	#print(trialmygraph[u])
	trialmygraph[u] += trialmygraph[v]
	#print(trialmygraph[u])
	del trialmygraph[v]
	trialmygraph[u].remove(u)
	trialmygraph[u].remove(v)
	for k in trialmygraph.keys():
		trialmygraph[k] = [u if j == v else j for j in trialmygraph[k]]


if __name__ == "__main__":
	filename = sys.argv[1]
	mygraph = dict()
	fh = open(filename, "r")
	for j in fh.readlines():
		#print(j)
		a = list(map(int, j.split()))
		mygraph[a[0]] = a[1:len(a)]
	minmum = 1000000
	for i in range(0,4000):
		#print("Trial : ",i)
		trialmygraph = copy.deepcopy(mygraph)
		_i = mincuts(trialmygraph)
		#print(mygraph)
		if _i < minmum:
			minmum  = _i
	print(minmum)
