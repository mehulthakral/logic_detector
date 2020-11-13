class Solution:
   def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for r,row in enumerate(grid):
            for c,col in enumerate(row):
                if grid[r][c] == '1':
                    self.removeNeighbors(r,c,grid)
                    count += 1
        return count            
    def removeNeighbors(self, r ,c, grid):
        grid[r][c] = 0 
        # print(grid)   
        if r+1 < len(grid) and grid[r+1][c] == '1':
            self.removeNeighbors(r+1,c,grid)
        if c+1 < len(grid[0]) and grid[r][c+1] == '1':
            self.removeNeighbors(r,c+1,grid)    
        if r-1 >= 0 and grid[r-1][c] == '1':
            self.removeNeighbors(r-1,c,grid)
        if c-1 >= 0 and grid[r][c-1] == '1':
            self.removeNeighbors(r,c-1,grid)   
