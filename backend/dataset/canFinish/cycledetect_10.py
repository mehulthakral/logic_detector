class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        adj_list = [[] for _ in range(n)]
        for pos, nb in prerequisites:
            adj_list[pos].append(nb)

        visited = [False] * n
        rec_stack = [False] * n

        for node in range(n):
            if not visited[node]:
                if self.is_cyclic(node, visited, rec_stack, adj_list):
                    return False
        return True

    def is_cyclic(self, node, visited, rec_stack, adj_list):
        visited[node] = True
        rec_stack[node] = True

        for nb in adj_list[node]:
            if not visited[nb]:
                if self.is_cyclic(nb, visited, rec_stack, adj_list):
                    return True
            elif rec_stack[nb]:
                return True
        rec_stack[node] = False
        return False


