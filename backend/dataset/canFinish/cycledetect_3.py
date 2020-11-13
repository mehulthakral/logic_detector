class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not numCourses or not prerequisites: return True
        # build the graph
        graph = {}
        for pair in prerequisites:
            _from, _to = pair
            graph.setdefault(_from, []).append(_to)
        # we need to find a topological sort if we detect a cycle we are done
        visiting, visited = set(), set()
        def dfs(node):
            # cycle detected
            if node in visiting: return False
            visiting.add(node)
            # explore children
            res = True
            for child in graph.get(node, []):
                if child not in visited:
                    res &= dfs(child)
                    if not res: return False
            # done with this node and its children
            visiting.discard(node)
            visited.add(node)
            return res
        # explore all nodes
        for i in range(numCourses):
            if not dfs(i): return False
        return True
