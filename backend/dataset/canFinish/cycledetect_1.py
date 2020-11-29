from typing import List
from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        in_degrees = [0 for x in range(numCourses)]
        start_nodes = []
        adj_matrix = defaultdict(list)
        for edge in prerequisites:
            if edge[0] == edge[1]:
                return False
            in_degrees[edge[1]] += 1
            adj_matrix[edge[0]].append(edge[1])
        
        for course_id, in_degree in enumerate(in_degrees):
            if in_degree == 0:
                start_nodes.append(course_id)
        
        if len(start_nodes) == 0:
            return False
        
        # bfs 
        visited = set() 
        for start_node in start_nodes:
            queue = [start_node]
            while queue:
                current = queue.pop()
                visited.add(current)
                for child in adj_matrix[current]:
                    if child in visited:
                        continue
                    in_degrees[child] -= 1
                    if in_degrees[child] < 1:
                        queue.append(child)
        return len(visited) == numCourses     
