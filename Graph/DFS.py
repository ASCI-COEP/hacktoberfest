def DFS(graph,visited,element,n):
    a=graph[element]
    #adding current node to visited nodes list
    visited+=[element]
    print(element,end=" ")
    for i in a:
        #checking whether all nodes are visited
        if(len(visited)==n):
            return 0
        #checking if node is visited
        if i not in visited:
            
            DFS(graph,visited,i,n)
            
            
            
graph = {"a": ["c", "f"],
         "b": ["c", "e"],
         "c": ["a", "b", "d", "e"],
         "d": ["c"],
         "e": ["c", "b"],
         "f": ["a"]
         }
visited=[]
DFS(graph,visited,'a',6)

