class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    q = [(i, j)]
                    while q:
                        x, y = q.pop()
                        grid[x][y] = '2'
                        for dx, dy in (0, 1), (0, -1), (1, 0), (-1, 0):
                            xx, yy = x+dx, y+dy
                            if 0 <= xx < m and 0 <= yy < n and grid[xx][yy] == '1':
                                q.append((xx, yy))
                    ans += 1            
        return ans
