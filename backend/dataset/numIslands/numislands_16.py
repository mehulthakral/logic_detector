class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        
        rows = len(grid)
        cols = len(grid[0])
		
		# Our helper will take a location on an island and subsequently 
		# update all values of that island to mark it has already been counted.
        def helper(row, col, grid):
		    # Ensure we're in the grid and we're on an unexplored island location ('1') otherwise return (stop the search)
            if row > rows-1 or row < 0 or col > cols-1 or col < 0 or grid[row][col] != '1':
                return
			# If we're in a vald location update the value to mark it's been explored and accounted for.
            grid[row][col] = '#'
			# Continue search in adjacent cells.
            helper(row+1, col, grid)
            helper(row-1, col, grid)        
            helper(row, col+1, grid)
            helper(row, col-1, grid)
		
		# Keep count of the '1' s that we find, which will be the number of islands.
        cnt = 0    
        for row in range(len(grid)):
            for col in range(len(grid[0])):
			    # If we find a location on an island we'll start our DFS and count the island.
                if grid[row][col] == '1':
                    helper(row, col, grid)
                    cnt += 1
                    
        return cnt
