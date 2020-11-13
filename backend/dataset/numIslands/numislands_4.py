class Solution:
    def __init__(self):
        self.size = 0
    def numIslands(self, grid: List[List[str]]) -> int:
        if not len(grid):
            return 0
        visited = [[False for val in row] for row in grid]
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if visited[row][col]:
                    continue
                self.findIslands(grid,row,col,visited)
        return self.size
    def findIslands(self,grid,row,col,visited):
        riversize = 0
        explore = [[row,col]]
        while len(explore):
            row,col = explore.pop()
            if visited[row][col]:
                continue
            visited[row][col] = True
            if grid[row][col] == "0":
                continue
            riversize+=1
            unvisited = self.getNeighbours(grid,row,col,visited)
            if len(unvisited):
                for node in unvisited:
                    explore.append(node)
        if riversize > 0:
            self.size+=1
           
    def getNeighbours(self,grid,row,col,visited):
        unvisited = []
        if row > 0 and not visited[row-1][col]:
            unvisited.append([row-1,col])
        if row < len(grid)-1 and not visited[row+1][col]:
            unvisited.append([row+1,col])
        if col > 0 and not visited[row][col-1]:
            unvisited.append([row,col-1])
        if col < len(grid[0])-1 and not visited[row][col+1]:
            unvisited.append([row,col+1])
        return unvisited
