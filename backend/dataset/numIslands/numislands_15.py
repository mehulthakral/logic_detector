class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        #如果是 grid 为空，返回 0
        if not grid: return 0
        row, col,island = len(grid), len(grid[0]), 0
        
        # dfs 用循环或者递归，找到一格island之后，将其改成 water，然后沿着四个方向继续做 dfs 检查
        def dfs(x,y):
            if x in range(row) and y in range(col) and grid[x][y]=="1":
                grid[x][y] = 0
                list(map(dfs,(x+1,x-1,x,x),(y,y,y+1,y-1)))
                
        for i in range(row):
            for j in range(col):
                if grid[i][j]=="1":
                    island +=1 #双循环遍历 grid, 如果发现了一个格子的 island，计数器 + 1，消去跟它相邻的
                    dfs(i,j)
                
        return island        
