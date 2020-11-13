from collections import deque

class Solution:
    def canFinish(self, numCourses, prereqs):            
        # Create edge list
        edge_list = [deque() for _ in range(numCourses)]
        for [neighbour, node] in prereqs:
            edge_list[node].append(neighbour)
        
        # Define recursive DFS function
        def DFS(source, path):
            if source in path:
                return(True)
            elif not visited[source]:
                visited[source] = True
                neighbours = edge_list[source]
                for n in neighbours:
                    node_path = path.union([source])
                    if DFS(n, node_path):
                        return(True)
        # Call DFS for each node
        visited = [False for _ in range(numCourses)]  # use as a memo table, thanks to
                                                      # nonlocal scoping in nested functions (here DFS)
        cycle_found = False
        for node in range(numCourses):
            if DFS(node, set()):
                cycle_found = True
                break
        return(not cycle_found)
