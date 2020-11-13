class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        total_islands = 0
        def recursive_islands(grid, m, n):
            if grid[m][n] == '0':
                return 
            
            grid[m][n] = '0'
            if m-1 >= 0:
                recursive_islands(grid, m-1,n)
            if m+1<len(grid):
                recursive_islands(grid, m+1, n)
            if n-1 >= 0:
                recursive_islands(grid, m, n-1)
            if n+1 < len(grid[0]):
                recursive_islands(grid, m, n+1)
                
            
        
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == '1':
                    #then we go into recursion to mark everything 0
                    recursive_islands(grid, i, j)
                    total_islands+=1
                else:
                    continue
        
        return total_islands
