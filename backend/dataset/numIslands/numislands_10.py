# python BFS code

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """ 
        ans = 0
        for r0, row in enumerate(grid):
            for c0, val in enumerate(row):
                if val=="1":
                    stack = [(r0, c0)]
                    ans=ans+1
                    while stack:
                        r, c = stack.pop()
                        
                        if (0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c]=="1") :
                    
                            
                            
                            grid[r][c]="0"
                            p=[(r,c-1),(r,c+1),(r-1,c),(r+1,c)]
                            stack+=p
                    #ans+=1
                            
        return ans
        
