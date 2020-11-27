from collections import deque

class Solution:
    def __init__(self):
        self.coin_universe = None
 
    def bfs(self, node):
        nodes_to_visit = deque([node])
        nodes_visited = set([node])
        depth = 0
        count = 0
        num_nodes = 1
 
        while len(nodes_to_visit) > 0:
            count += 1
            if count == num_nodes:
                depth += 1
                count = 0
                num_nodes = len(nodes_to_visit)
            node = nodes_to_visit.popleft()
            neighbours = [node - coin for coin in self.coin_universe]
            for neighbour in neighbours:
                if (neighbour not in nodes_visited) and (neighbour >= 0):
                    if neighbour == 0: return depth
                    nodes_visited.add(neighbour)
                    nodes_to_visit.append(neighbour)
        return -1


    def coinChange(self, coin_universe:List[int], amount:int)->int:
        """
        @time: O(n)
        @space: O(1)
        """
        if amount == 0: return 0
        self.coin_universe = coin_universe
        return self.bfs(amount)   
