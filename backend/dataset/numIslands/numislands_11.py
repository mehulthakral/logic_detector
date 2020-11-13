class Solution:
    def countIslands(self, grid: List[List[str]], row, col) -> None:
        if(row in [-1, len(grid)] or col in [-1, len(grid[0])] or grid[row][col] == "0"):
            return
        grid[row][col] = "0"
        self.countIslands(grid, row, col-1)
        self.countIslands(grid, row-1, col)
        self.countIslands(grid, row, col+1)
        self.countIslands(grid, row+1, col)
        return

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == "1":
                    count += 1
                    self.countIslands(grid, row, col)
        return count
