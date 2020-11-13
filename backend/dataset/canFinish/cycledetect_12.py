class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.mat = {}
        for i in range(numCourses):
            self.mat[i] = {}
        
        self.visited = [False for i in range(numCourses)]
        self.repeated = [False for i in range(numCourses)]
        self.stack = []
        
        for u, v in prerequisites:
            self.mat[v][u] = 1
        
        def topologicalSort(node):
            self.visited[node] = True
            self.repeated[node] = True

            for child in self.mat[node]:
                if not self.visited[child]:
                    if topologicalSort(child):
                        return True
                elif self.repeated[child]:
                    return True
                    
            self.stack.append(node)
            self.repeated[node] = False
            return False

        cycle = False
        for node in range(numCourses):
            if not self.visited[node]:
                if topologicalSort(node):
                    cycle = True
                    break

        return not cycle
