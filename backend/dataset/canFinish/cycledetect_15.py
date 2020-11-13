from collections import deque

class Solution:    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
	    # extract a set of vertices from the edge list
        vertices = set([v for sublist in prerequisites for v in sublist]) 
		# transform the set of vertices and edge list into an adjacency list
        graph = { v: [e[1] for e in prerequisites if e[0] == v] for v in vertices}
        
		# traverse the graph starting at each vertex
        for v in vertices:
            bfs = deque(graph[v]) # add all the neighbours of starting node to the BFS queue
            visited = set() # use a set to keep track of the visited nodes and not get stuck in a cycle
            
            while bfs:
                current = bfs.pop()
                visited.add(current)
                if current == v: # we ended up at the same vertex where we started - there's a cycle
                    return False
                for n in graph[current]: # cycle not detected, continue the traversal to the next nodes
                    if n not in visited:
                        bfs.appendleft(n)            
        
        return True
