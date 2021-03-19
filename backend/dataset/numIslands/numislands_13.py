from typing import List
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        island_count = 0

        for i, _ in enumerate(grid):
            for j, _ in enumerate(grid[i]):
                if grid[i][j] == '1':
                    self.dfs(i, j, grid)
                    island_count += 1

        return island_count


    def dfs(self, i, j, grid):

        if i < 0 or i >= len(grid):
            return

        if j < 0 or j >= len(grid[0]):
            return

        if grid[i][j] == '0':
            return

        grid[i][j] = '0'

        self.dfs(i - 1, j, grid)
        self.dfs(i + 1, j, grid)
        self.dfs(i, j - 1, grid)
        self.dfs(i, j + 1, grid)
