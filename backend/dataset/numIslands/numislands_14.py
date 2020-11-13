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
                return 1 
# ***找到一格 island，返回 一个 1，但是只有最后的一个格子返回的 1 才会被 nested loop 记录在list里求sum***
            return 0 #如果是 water 或者超界返回 0
        
        # Nested loop 必须放在 list 里, 对返回值 1，island 的个数求和
        return sum([dfs(i,j) for i in range(row) for j in range(col)])
