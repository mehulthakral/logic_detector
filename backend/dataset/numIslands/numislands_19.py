class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ## RC ##
        ## APPROACH : DFS ##
        # 1. find the land, go to surroundings and convert to water
        # 2. increment island count, get back and search for next islands.
        
		## TIME COMPLEXITY : O(N^2) ##
		## SPACE COMPLEXITY : O(1) ##

        def convertLandToWater(grid,i,j):
            if(i<0 or j<0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] != '1'):
                return
            grid[i][j] = '0'
            for x,y in directions:
                convertLandToWater(grid, i + x, j + y)
        
        if len(grid) == 0 : return 0
        isLandCount = 0
        directions = [(0,1), (0,-1), (-1,0), (1,0)]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    isLandCount += 1
                    convertLandToWater(grid, i, j)
        return isLandCount        
