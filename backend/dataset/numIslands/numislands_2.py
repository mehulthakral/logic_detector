from queue import Queue

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:            
        result = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    self.bfs(grid, i, j)
                    result += 1
        
        
        return result
    
    def bfs(self, grid, i, j):
        q = Queue()
        q.put([i, j])
        grid[i][j] = "#"
        
        while(q.qsize() > 0):
            i, j  = q.get()
            
            if i - 1 >= 0 and grid[i - 1][j] == "1":
                q.put([i - 1, j])
                grid[i - 1][j] = "#"
            
            if j - 1 >= 0 and grid[i][j - 1] == "1":
                q.put([i, j - 1])
                grid[i][j - 1] = "#"
                
            if i + 1 < len(grid) and grid[i + 1][j] == "1":
                q.put([i + 1, j])
                grid[i + 1][j] = "#"
            
            if j + 1 < len(grid[0]) and grid[i][j + 1] == "1":
                q.put([i, j + 1])
                grid[i][j + 1] = "#"
        
