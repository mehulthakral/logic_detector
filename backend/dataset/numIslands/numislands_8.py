class UF:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.n = n
        self.size = n

    def union(self, i, j):
        pi, pj = self.find(i), self.find(j)
        if pi != pj:
            self.size -= 1
            self.p[pj] = pi

    def find(self, i):
        if i != self.p[i]:
            self.p[i] = self.find(self.p[i])
        return self.p[i]


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        d = dict()
        idx = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    d[i, j] = idx
                    idx += 1
        uf = UF(idx)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    if i > 0 and grid[i-1][j] == '1':
                        uf.union(d[i-1, j], d[i, j])
                    if j > 0 and grid[i][j-1] == '1':
                        uf.union(d[i, j-1], d[i, j])
        return uf.size
