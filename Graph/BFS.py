from Queue import Queue

visited = set()
queue = Queue()
entry_point = "f"
queue.put(entry_point)
operations = 0

graph = {"a": ["c"],
         "b": ["c", "e"],
         "c": ["a", "b", "d", "e"],
         "d": ["c"],
         "e": ["c", "b"],
         "f": ["a"]
         }

# BFS
while not queue.empty():
    current_node = queue.get()  # Get next node to process
    if current_node not in visited:
        # Add the current node to the set of visited nodes
        visited.add(current_node)
        neighbors = graph[current_node]  # Find neighbors
        # Loop through neighbors and add the newly discovered ones to the queue
        for neighbor in neighbors:
            if neighbor not in visited:
                queue.put(neighbor)
    operations += 1  # Count operations

print("visited:")
print(visited)
